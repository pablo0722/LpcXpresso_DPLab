%% levantamiento de archivo
clc;
close all;
WordLength  = 16 ;                                              % Simulo conversor de 16 bits signado - ( signed fractional Q15 )
FractLength = 15 ;
q = quantizer( 'Mode', 'fixed','Format' ,[WordLength FractLength],'OverflowMode', 'Saturate','RoundMode','floor');

fid = fopen('outq15.txt');               % Abro el archivo de texto exportado por MPLABX

DSP_output = fscanf( fid, '%4x', inf);      % leo de a 8 datos hexa                                     % Leo las muestras en Q15 y las copio a un vector integer unsigned
DSP_output=dec2hex(DSP_output);             % convierto a valores hexa
signal=hex2num(q,DSP_output);               % convierto a tipo double

figure('name','signal LPC');
hold on;
plot(signal,'r');
figure('name','Espectro LPC');
plotFFT(signal,1000);