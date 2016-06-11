close all; clear all; clc;


% addpath('../funciones_varias');
% addpath(genpath('../MatlabScript'));
%% generacion de la señal
f=100;
fs=22050;
L=2048;
Lword=32;  % Q31

signal = signalforMU_file(f,fs,L,Lword);
%plot(signal);
signal=signal*(2^32)*0.99;
%% establezco comunicación serie
% para ver el puerto, en la consola dmesg

srl = serial('/dev/ttyUSB0','BaudRate',9600,'DataBits',8,'StopBits',1);
srl.InputBufferSize = 2048*4;
fopen(srl);

for h=1:size(signal,2)
    fwrite(srl,(h),'int32','sync');
    h
end
% plot(signal);
%  fclose(srl);
%  delete(srl);
%  clear srl;
% plot(signal);

%% interpretacion de datos
WordLength  = 32 ;                                              % Simulo conversor de 16 bits signado - ( signed fractional Q15 )
FractLength = 31 ;
q = quantizer( 'Mode', 'fixed','Format' ,[WordLength FractLength],'OverflowMode', 'Saturate','RoundMode','floor');
    
display('ahi vienen los indios')
[resultados, count, msg]=fread(srl, 2048, 'int32');
Y = typecast(resultados, 'int32'); % agrupo de a 4 bytes
Ym= dec2hex(Y);
Ym= hex2num(q,Ym);
figure('name','resultados');
plot(Y);

