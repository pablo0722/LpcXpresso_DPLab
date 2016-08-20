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

function func_NumTaps(file_name,Hd)

    fid = fopen(file_name,'wt');                        % creo el archivo
    fprintf(fid,'.equ LowPassNumTaps,');                             % escribo la directiva de assembly "hexword type"
    
    NumTaps=size(Hd.numerator,2);
    fprintf(fid,'%d',NumTaps);
    fprintf(fid,'\n');                                  % Enter para finalizar
    fclose(fid);                                        % cierro el archivo
    
    return ;
end
