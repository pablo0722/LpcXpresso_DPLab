%% envio de datos por puerto serie a LPC1769    
clc;
close all;
%% envio de se�al
srl = serial('/dev/ttyUSB0','BaudRate',9600,'DataBits',8,'StopBits',1);
fopen(srl);
% fprintf(srl,'hola');

%% recepci�n de se�al
rta=fscanf(srl);
% fclose(srl);


