% ----------------------------------------------------------------------------------------------
% Funcion Signal ...
% 
% Ultima modificación: 11/2013
% 
% Autor: Ing.César Angel Fuoco
%
% Descripción:
%
% Funcion que guarda un vector de 1xN muestras en un archivo de texto. Cada elemento se expresa 
% en hex signed de 16bits y la forma de la tabla es una matriz de N/8 filas x 8 Columnas
%
% ----------------------------------------------------------------------------------------------

function func_fft_signal2fileCSV_hex_fixed(file_name,senal)
    
    N= length(senal);

    fid = fopen(file_name,'wt');                        % creo el archivo
        
    for k=1:N
        aux = fi(senal(k), 1, 16, 15)
        fprintf(fid,'0x%s, ',aux.hex); 
        fprintf(fid,'\n');                              % Enter entre samples
    end
    
    
    fclose(fid);                                        % cierro el archivo
    
    return ;
    
end
