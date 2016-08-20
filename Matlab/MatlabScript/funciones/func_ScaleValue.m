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

function func_ScaleValue(file_name,Hd)

    fid = fopen(file_name,'wt');                        % creo el archivo
    %fprintf(fid,'.equ HighpassNumSections,');          % escribo la directiva de assembly "hexword type"
    
    Numberofbiquads = length( Hd.ScaleValues ) - 1;     
    scalevalue = Hd.ScaleValues(Numberofbiquads);       % Gain out de la cascada de IIRs. Consideramos la etapas intermedias con gain:1
    %scalevalue = Hd.ScaleValues;
    scalevalue_fixedpoint=fi(scalevalue,1,16,15);    
    scalevalue_fixedpoint = scalevalue_fixedpoint.hex;
    fprintf(fid,'fractional scalevalue=0x%s;',scalevalue_fixedpoint);        % escribo el scale value en hex 
   
    
    fprintf(fid,'\n');                                  % Enter para finalizar
    fclose(fid);                                        % cierro el archivo
    
    return ;
end
