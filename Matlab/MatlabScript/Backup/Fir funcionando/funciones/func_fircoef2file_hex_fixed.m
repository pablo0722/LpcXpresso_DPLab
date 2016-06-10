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

function func_fircoef2file_hex_fixed(file_name,Hd)

    fid = fopen(file_name,'wt');                        % creo el archivo
    fprintf(fid,'.hword ');                             % escribo la directiva de assembly "hexword type"
    
    for k=1:size(Hd.numerator,2)
        coeficiente = fi(Hd.numerator(k), 1, 16, 15)
        string_coef = coeficiente.hex;
        fprintf(fid,'0x%s, ',string_coef);              % escribo la directiva de assembly "hexword type"
    end
    
    fprintf(fid,'\n');                                  % Enter para finalizar
    fclose(fid);                                        % cierro el archivo
    
    return ;
end
