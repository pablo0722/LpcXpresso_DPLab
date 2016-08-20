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
len = 2048*2;

srl = serial('/dev/ttyUSB1','BaudRate',9600,'DataBits',8,'StopBits',1);
srl.InputBufferSize = len;
fopen(srl);

in_real = 0.999969482*tono(234, len/4, len/4)*(2^15);
in_imag = 0.999969482*zeros(1, len/4)*(2^15);
in = sqrt(in_real.^2 + in_imag.^2);

for h=1:len/4
    fwrite(srl, in_real(h), 'int16', 'sync');
    fwrite(srl, in_imag(h), 'int16', 'sync');
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
[resultados, count, msg]=fread(srl, len/2, 'int16');
% Y = typecast(resultados, 'int32'); % agrupo de a 4 bytes
% Ym= dec2hex(Y);
% Ym= hex2num(q,Ym);
% figure('name','resultados');
% plot(Y);
close all;
figure();
subplot(211), plot(in_real), title('entrada');
subplot(212), plot(resultados), title('salida');

cierre;