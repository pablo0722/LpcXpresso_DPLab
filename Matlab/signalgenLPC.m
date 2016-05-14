clc;
clear all;
close all;
%% Tabla para la senoidal
% -----------seteo de la señal----------------------%
fs=1000;
t=0:1/fs:1-(1/fs);
f=2;
L=2048;
w=2*pi*f;
s=sin(w*t);
s=[s s s s s];
signal=0.9.*s(1:L);

%% ------------señal generada-------------------------%
figure ('name','Señal pretendida');
plot(signal);

%% Simulo Conversión Analógico a Digital & punto fijo
                                                     
WordLength  = 16 ;                                              % Simulo conversor de 16 bits signado - ( signed fractional Q15 )
FractLength = 15 ;
q = quantizer( 'Mode', 'fixed','Format' ,[WordLength FractLength],'OverflowMode', 'Saturate','RoundMode','floor');
                                                          
signal_q = quantize( q , signal);                               % Cuantifico las señales en 16 bits el tipo de dato retornado por la 
                                                                % funcion quantize sigue siendo double pero con precision de 16 bits

FileName_signal='./signal.txt';          % ruta destino para la señal de prueba

func_Signal2fileCSV_hex_fixed(FileName_signal,signal_q);        % Esta funcion pone la señal en punto fijo y la guardar en un archivo


