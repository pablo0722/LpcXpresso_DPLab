
% -----------------------------------------------------------------------------------------
% dsPIC_IIR_design 
% 
% Ultima modificación: 5/2014
% 
% Autor: Ing. César Angel Fuoco
%
% Descripción:
% Diseñado para comparar los resultados del filtrado IIR en un dsPIC con los resultados de 
% un filtrado de en MATLAB.      Se   genera una señal de prueba y se exporta a un archivo
% mch. Tambien se exporta la informacion del filtro en un archivo. Cada muestra de la señal 
% se codifica en Q15. El procesamiento es OFFLINE. Se debe hacer un breackpoint 
% donde indica el script e ir al MPLABX para obtener los resultados del dsPIC.
% -----------------------------------------------------------------------------------------

clear all;                                                      % Limpia el worksapace
close all;                                                      % Cierra todas las ventanas
clc;

addpath ./funciones;                                            % Path relativo de funciones
addpath ./filtros;                                              % Path relativo de funciones

FileName_signal='./Archivos Import Export/signal.mch';          % ruta destino para la señal de prueba
FileName_coeficientes='./Archivos Import Export/coef_iir.h';    % ruta destino para los coeficientes
FileName_NumSOS='./Archivos Import Export/NumSOS.h';            % ruta destino para los coeficientes
FileName_ScaleValue='./Archivos Import Export/ScaleValue.h';    % ruta destino para el Scale Value


%% Señal de prueba
A = 0.01; f0 = 1000; N = 256; fs = 44211; ph = 0;NBits = 16;d=0.5;   
%A = 1; f0 = 4000; N = 1024; fs = 8000; ph = 0;NBits = 16;d=0.5;   

[tAxis signal] = func_mySin (A, f0, N, ph, fs);
%[tAxis signal] = func_mySquare (A, f0, N, d, fs)

%% Simulo Conversión Analógico a Digital & punto fijo
                                                     
WordLength  = 16 ;                                              % Simulo conversor de 16 bits signado - ( signed fractional Q15 )
FractLength = 15 ;
q = quantizer( 'Mode', 'fixed','Format' ,[WordLength FractLength],'OverflowMode', 'Saturate','RoundMode','floor');
                                                          
signal_q = quantize( q , signal);                               % Cuantifico las señales en 16 bits el tipo de dato retornado por la 
                                                                % funcion quantize sigue siendo double pero con precision de 16 bits
func_Signal2fileCSV_hex_fixed(FileName_signal,signal_q);        % Esta funcion pone la señal en punto fijo, antes de guardarla

%% Diseño del filtro IIR 
Hd = lowpass_iirfilter_df1transposed_1sos ;                     % Objeto filtro exportado del fdatool

func_iircoef2file_hex_fixed(FileName_coeficientes,Hd);          % Guardo los coeficientes a un archivo
func_NumSOS(FileName_NumSOS,Hd);                                % Guardo el Numero de SOS a un archivo
func_ScaleValue(FileName_ScaleValue,Hd);                        % Guardo el ScaleValue a un archivo
fvtool(Hd);                                                     % Visualizo el filtro digital

%% Función de procesamiento - Filtrado 
y=filter(Hd,signal_q);                                          % filter resuelve direct form II transposed                              

%% >> MPLAB X ( Poner un Breackpoint en esta linea antes de procesar )
% Dentro de MPLAB X, realizar los siguientes pasos para no equivocarse: 
% 1. Clean and Build Proyect
% 2. Make & Program Device
% 3. Debug Proyect
% 4. Poner un breackpoint antes de llamar a la funcion IIR.
% 5. Abrir la ventana de Memory view > FSR Registers
% 6. Seleccionar el sector de memoria correspondiente al "Buffer in"
% 7. Hacer "import table" de la señal generada por matlab.
% 8. Poner un breackpoint a la salida de la funcion IIR.
% 9. Seleccionar el sector de memoria correspondiente al "Buffer out"
% 10. Hacer un "export table" a un archivo mch
% 11. Volver a Matlab y darle F5 ( Continue )
% Nota: Es muy importante verificar que los import y export se realizan
% correctamente, para esto comparar los arhivos de texto con el memory view 


%% Comparación de salida Matlab vs dsPIC
fid = fopen('./Archivos Import Export/dump_iir.mch');            % Abro el archivo de texto exportado por MPLABX

DSP_output = fscanf( fid, '%4x', inf);                           % Leo las muestras en Q15 y las copio a un vector integer unsigned
DSP_output = dec2hex(DSP_output);
DSP_output = hex2num(q,DSP_output);

%% Ploteos - Gráficos - Resultados
figure;
subplot(411);plot(signal,'Linewidth',2);title('SENAL DE EXCITACION');
subplot(412);plot(y,'m','Linewidth',2);title('SENAL PROCESADA EN MATLAB EN PUNTO FIJO');
subplot(413);plot(DSP_output,'r','Linewidth',2);title('SENAL PROCESADA EN DSPIC EN PUNTO FIJO');

clc;
Error = DSP_output - y;
MSE = mse(Error);
disp(sprintf('MSE Matlab Vs dsPIC: %e',MSE));
subplot(414);plot(Error,'gr','Linewidth',2);title('ERROR ENTRE DSPIC Y MATLAB');



