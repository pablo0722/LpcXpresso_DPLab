function [ signal ] = signalforMU( f,fs,L,Lword )
clc;
close all;
%% seteo de la señal
signal=0.9*tono(f,fs,L);

%% ------------señal generada-------------------------%
figure ('name','Señal pretendida');
plot(signal);

%% Simulo Conversión Analógico a Digital & punto fijo
                                                     
WordLength  = Lword ;                    % Simulo conversor de 16 bits signado - ( signed fractional Q15 )
FractLength = Lword-1 ;
q = quantizer( 'Mode', 'fixed','Format' ,[WordLength FractLength],'OverflowMode', 'Saturate','RoundMode','floor');
                                                          
signal_q = quantize( q , signal);        % Cuantifico las señales en 16 bits el tipo de dato retornado por la 
                                         % funcion quantize sigue siendo double pero con precision de 16 bits

FileName_signal='./signal.txt';          % ruta destino para la señal de prueba

func_Signal2fileCSV_hex_fixed(FileName_signal,signal_q,Lword);        % Esta funcion pone la señal en punto fijo y la guardar en un archivo

end

