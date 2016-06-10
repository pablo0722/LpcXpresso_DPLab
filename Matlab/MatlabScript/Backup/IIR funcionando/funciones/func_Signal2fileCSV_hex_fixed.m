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

function func_Signal2fileCSV_hex_fixed(file_name,senal)

    % si debe tomar la se�al en double y guardarla en punto fijo debe ir esta linea, para 1.15
    senal=fi(senal,1,16,15);

    N= length(senal);

    str=[];
    
    for i=1: N
        str =[str ; hex(senal(i))];
    end

    %last  = str(N,:);                       % guardo el ultimo numero
    %str = str(1:(N-1),:);                   % borro de la senal el ultimo numero
    
    fid = fopen(file_name,'wt');             % creo el archivo

    for i=1: (N/8)
        for k=1:8
            fprintf(fid,'%s\t',str( (i-1)*8 + k,:) );     % escribo los elementos de las columnas
        end
        fprintf(fid,'\n');                   % escribo un enter
    end

    fclose(fid);                      

    return ;
end
