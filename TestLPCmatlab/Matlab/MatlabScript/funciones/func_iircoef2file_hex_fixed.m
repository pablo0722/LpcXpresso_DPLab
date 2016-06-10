% ----------------------------------------------------------------------------------------------
% Funcion 
% 
% Ultima modificación: 11/2013
% 
% Autor: Ing.César Angel Fuoco
%
% Descripción:
%
%
% ----------------------------------------------------------------------------------------------

function func_iircoef2file_hex_fixed(file_name,Hd)

    fid = fopen(file_name,'wt');                        % creo el archivo
    fprintf(fid,'.hword ');                             % escribo la directiva de assembly "hexword type"
    
    
    %******************************************************************
    %  Los Coeficientes se exportan al dsPIC en un archivo de texto. 
    %  Se ordenan de la siguiente manera:
    %           
    %          b0 b1 -a1 b2 -a2  ... b0n b1n -a1n b2n -a2n    
    %
    %  La funcion de la libreria dsp implementa un "final shift", el
    %  cual funciona como un escalamiento de salida para garantizar 
    %  el 0dB del filtrado ( Es decir que mi funcion del dsPIC no 
    %  modifique la ganancia en la banda de paso ). Para simplificar
    %  el tratamiento en el dsPIC este finalshift lo pondremos a cero
    %  ( sin escalamiento ) y los coeficientes en matlab estaran 
    %  exportados en 1.15
    %  
    %******************************************************************
    Numberofbiquads = length( Hd.ScaleValues ) - 1;     % Number of SOS

    ScalingFactor = 2;                                  % 
    
    for i=1:Numberofbiquads
        j=(i-1)*5;
        coef(j+1) = Hd.sosMatrix(i,1)/ScalingFactor;    % Numerator en double
        coef(j+2) = Hd.sosMatrix(i,2)/ScalingFactor; 
        coef(j+3) = -(Hd.sosMatrix(i,5)/ScalingFactor); 
        coef(j+4) = Hd.sosMatrix(i,3)/ScalingFactor; 
        coef(j+5) = -(Hd.sosMatrix(i,6)/ScalingFactor); 
    end
    
    Numcoefs = Numberofbiquads * 5 ;
    
    for k=1:Numcoefs
        coeficiente = fi(coef(k), 1, 16, 15)            % Se guardan en 1.15 
        string_coef = coeficiente.hex;
        fprintf(fid,'0x%s, ',string_coef);              % escribo los coefs
    end
    
    fprintf(fid,'\n');                                  % Enter para finalizar
    fclose(fid);                                        % cierro el archivo
    
    return ;
end
