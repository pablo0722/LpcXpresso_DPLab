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

function func_NumSOS(file_name,Hd)

    fid = fopen(file_name,'wt');                        % creo el archivo
    fprintf(fid,'.equ HighpassNumSections,');           % escribo la directiva de assembly "hexword type"
    
    Numberofbiquads = length( Hd.ScaleValues ) - 1;     % Number of SOS
    fprintf(fid,'%d',Numberofbiquads);
    fprintf(fid,'\n');                                  % Enter para finalizar
    fclose(fid);                                        % cierro el archivo
    
    return ;
end
