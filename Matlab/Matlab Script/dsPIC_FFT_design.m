% -----------------------------------------------------------------------------------------
% dsPIC_FFT_design 
% 
% Ultima modificación: 8/2015
% 
% Autor: Ing. César Angel Fuoco
%
% Descripción:
% Diseñado para comparar los resultados de la funcion FFT del dsPIC33F con los resultados    
% de la FFT en MATLAB. Se genera una señal de prueba y se exporta a un archivo 
% mch. Cada muestra de la señal se codifica en Q15. El procesamiento es puramento Offline. 
% Se debe hacer un breackpoint donde indica el script e ir al MPLABX para obtener los resultados 
% del dsPIC.
%
% -----------------------------------------------------------------------------------------

clear all;                                                      % Limpia el worksapace
close all;                                                      % Cierra todas las ventanas
clc;

addpath ./funciones;                                            % Path relativo de funciones
addpath ./filtros;                                              % Path relativo de funciones


%% Señal de prueba
A = 1; f0 = 2560;N = 256;fs = 44211;ph = 0;NBits = 16;d=0.5;   
[tAxis signal] = func_mySin (A, f0, N, ph, fs);
%[tAxis signal] = func_mySquare (A, f0, N, d, fs)

%% Simulo Conversión Analógico a Digital & punto fijo
                                                     
WordLength  = 16 ;                                              % Simulo conversor de 16 bits signado - ( signed fractional Q15 )
FractLength = 15 ;
q = quantizer( 'Mode', 'fixed','Format' ,[WordLength FractLength],'OverflowMode', 'Saturate','RoundMode','floor');
                                                          
signal_q = quantize( q , signal);                               % Cuantifico las señales en 16 bits el tipo de dato retornado por la 
                                                                % funcion quantize sigue siendo double pero con precision de 16 bits

FileName_signal='./Archivos Import Export/signal.mch';          % ruta destino para la señal de prueba
FileName_signal='./Archivos Import Export/signal.h';            % ruta destino para la señal de prueba
%FileName_coeficientes='./Archivos Import Export/twidfactor.h';  % ruta destino para los coeficientes
%FileName_NumTaps='./Archivos Import Export/fft_block_length.h'; % ruta destino para los coeficientes

%func_Signal2fileCSV_hex_fixed(FileName_signal,signal_q);        % Esta funcion pone la señal en punto fijo, antes de guardarla
func_fft_signal2fileCSV_hex_fixed(FileName_signal,signal_q);    %

%% Calculo la FFT
NFFT = N;                                                       % N bin fft - si NFFT es distinto a N debemos hacer zero stuffing en el vector de entrada
aux = fft (signal,NFFT);                                             % Calcula la dft - devuelve un vector con parte real e imag
%esp = fftshift(aux);                                            % espejamos ( simetria dft )
yExpAbs = (abs (aux))/NFFT;                                       % escalo la amplitud
%yExpAbs = abs (aux)/2560;                                       % con esto da bien... >(
fAxis = (-fs/2:fs/NFFT:fs/2 - fs/NFFT);                         % eje grafico
%stem (fAxis,yExpAbs,'-bl');

%fixed point fft
%http://www.mathworks.com/help/fixedpoint/ug/convert-fast-fourier-transform-fft-to-fixed-point.html

%func_fircoef2file_hex_fixed(FileName_coeficientes,Hd);          % Guardo los coeficientes a un archivo
%func_NumTaps(FileName_NumTaps,Hd);                              % Guardo el Numero de Taps a un archivo


%% >> MPLAB X ( Poner un Breackpoint en esta linea antes de procesar )
% Dentro de MPLAB X, realizar los siguientes pasos para no equivocarse: 
% 1. Clean and Build Proyect
% 2. Make & Program Device
% 3. Debug Proyect
% 4. Poner un breackpoint antes de llamar a la funcion FIR.
% 5. Abrir la ventana de Memory view > FSR Registers
% 6. Seleccionar el sector de memoria correspondiente al "Buffer in"
% 7. Hacer "import table" de la señal generada por matlab.
% 8. Poner un breackpoint a la salida de la funcion FIR.
% 9. Seleccionar el sector de memoria correspondiente al "Buffer out"
% 10. Hacer un "export table" a un archivo mch
% 11. Volver a Matlab y darle F5 ( Continue )
% Nota: Es muy importante verificar que los import y export se realizan
% correctamente, para esto comparar los arhivos de texto con el memory view 


%% Comparación de salida Matlab vs dsPIC
fid = fopen('./Archivos Import Export/dump_fft.mch');           % Abro el archivo de texto exportado por MPLABX

DSC_output = fscanf( fid, '%4x', inf);                          % Leo las muestras en Q15 y las copio a un vector integer unsigned
DSC_output=dec2hex(DSC_output);
DSC_output=hex2num(q,DSC_output);


%% Ploteos - Gráficos - Resultados
figure;
subplot(411);plot(signal,'Linewidth',2);title('SENAL DE EXCITACION');
subplot(412);stem (fAxis,yExpAbs,'-bl');title('FFT PROCESADA EN MATLAB EN DOUBLE PRESICION');
%subplot(413);stem (DSC_output,yExpAbs,'-bl');title('FFT PROCESADA EN dsPIC EN PUNTO FIJO');
subplot(413);stem (fAxis,DSC_output,'-r');title('FFT PROCESADA EN dsPIC EN PUNTO FIJO');
clc;
Error = DSC_output - yExpAbs;
MSE = mse(Error);
disp(sprintf('MSE MATLAB VS DSPIC : %e',MSE));
subplot(414);plot(Error,'gr','Linewidth',2);title('ERROR ENTRE DSPIC Y MATAB');



