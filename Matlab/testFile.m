function [ signal ] = testFile( filename,Lword,fs)
%% levantamiento de archivo de se�al en punto fijo Q15 o Q31.
% file      nombre del archivo a analizar
% Lword     tama�o de la palabra de dato q15=16, q31=32
% fs        frecuencia de muestreo para el ploteo
% signal    se�al provista en el archivo
% plot      en 0 no se plotea la se�al
clc;
close all;
% clear all;
%% datos de cuantizaci�n
WordLength  = Lword ;                       % Simulo conversor de Lword bits signado - ( ej signed fractional Q15 )
FractLength = Lword-1 ;
q = quantizer( 'Mode', 'fixed','Format' ,[WordLength FractLength],'OverflowMode', 'Saturate','RoundMode','floor');
%% aperturadel archivo
% name=char(file);
% ext=char('.txt');
% filename=[name ext]
fid = fopen(filename);                      % Abro el archivo de texto exportado por IDE
                                            % Leo las muestras en Q15 y las copio a un vector integer unsigned
if Lword==16
    DSP_output = fscanf( fid, '%4x', inf);  % leo de a 4 datos hexa                                    
elseif Lword==32
    DSP_output = fscanf( fid, '%8x', inf);  % leo de a 8 datos hex
end
DSP_output=dec2hex(DSP_output);             % convierto a valores hexa
signal=hex2num(q,DSP_output);               % convierto a tipo double

%% ploteos
% if plot==1
    figure('name','signal LPC');
    hold on;
    plot(signal,'r');
    figure('name','Espectro LPC');
    plotFFT(signal,fs);
% end
end

