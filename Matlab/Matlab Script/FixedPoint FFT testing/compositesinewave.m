
clear all;                                                      % Limpia el worksapace
close all;                                                      % Cierra todas las ventanas
clc;

addpath ./funciones;                                            % Path relativo de funciones
addpath ./filtros;                                              % Path relativo de funciones

WordLength  = 16 ;                                              % Simulo conversor de 16 bits signado - ( signed fractional Q15 )
FractLength = 15 ;
q = quantizer( 'Mode', 'fixed','Format' ,[WordLength FractLength],'OverflowMode', 'Saturate','RoundMode','floor');

N = 512;
fs = 8000; 

%% Senal de 2 armonicas
fid = fopen('.././Archivos Import Export/compositesinewave.h');           % Abro el archivo de texto exportado por MPLABX

string=fscanf( fid, '%s');
fclose(fid);

% primer Q15
% aux=string(3;6)
% DSC_output(1)=hex2num(q.aux)
        
for i=1:N
    char=string((i-1)*7+3: (i-1)*7 + 6);
    signal(i)=hex2num(q,char);
end
figure;  
plot(signal);

NFFT=N;
espcmpx = fft (signal/2,NFFT);                                             % Calcula la dft - devuelve un vector con parte real e imag
yExpAbs = (abs (espcmpx))/NFFT;                                          % escalo la amplitud
fAxis = (-fs/2:fs/NFFT:fs/2 - fs/NFFT);                             % eje grafico

figure;
subplot(3,1,1)
plot (fAxis,real(espcmpx)/NFFT,'-bl');

subplot(3,1,2)
plot (fAxis,imag(espcmpx)/NFFT,'-bl');

subplot(3,1,3)
plot (fAxis,yExpAbs,'-bl');

%% Comparación de salida Matlab vs dsPIC

fid = fopen('.././Archivos Import Export/dump_real.mch');           % Abro el archivo de texto exportado por MPLABX
DSC_output = fscanf( fid, '%4x', inf);                          % Leo las muestras en Q15 y las copio a un vector integer unsigned
DSC_output=dec2hex(DSC_output);
DSC_REAL_output=hex2num(q,DSC_output);
fclose(fid);

fid = fopen('.././Archivos Import Export/dump_imag.mch');           % Abro el archivo de texto exportado por MPLABX
DSC_output = fscanf( fid, '%4x', inf);                          % Leo las muestras en Q15 y las copio a un vector integer unsigned
DSC_output=dec2hex(DSC_output);
DSC_IMAG_output=hex2num(q,DSC_output);
fclose(fid);

fid = fopen('.././Archivos Import Export/dump_fft_sqrt.mch');           % Abro el archivo de texto exportado por MPLABX
DSC_output = fscanf( fid, '%4x', inf);                          % Leo las muestras en Q15 y las copio a un vector integer unsigned
DSC_output=dec2hex(DSC_output);
DSC_output=hex2num(q,DSC_output);
fclose(fid);

figure;
subplot(3,1,1);
plot(fAxis,DSC_REAL_output,'-bl');

subplot(3,1,2);
plot(fAxis,DSC_IMAG_output,'-bl');

subplot(3,1,3);
plot(fAxis,DSC_output,'-bl');





%% Comparo con la fft matlab

w0 = fi_radix2twiddles(N);
x = sfi(signal/2);  % Convert to signed fixed-point. Default Q15
w = sfi(w0);  % Convert to signed fixed-point

figure;
% Re-run the same algorithm with the fixed-point inputs & Scaling                
y = fi_m_radix2fft_withscaling(x,w);
y0 = fft(signal/2); % MATLAB's built-in FFT for comparison
fi_fft_demo_plot(real(x), y, y0/N, fs, 'Fixed-point data', ...
                        {'Fixed-point FFT with scaling','Scaled built-in'});



%% Metrica de Error
Error = DSC_output - yExpAbs';
MSE = mse(Error);
disp(sprintf('MSE Matlab Vs dsPIC: %e',MSE));
figure;
plot(Error,'gr','Linewidth',2);title('ERROR ENTRE DSPIC Y MATLAB DOUBLE PRESICION');

y=abs(double(y));
Error = DSC_output - y';
MSE = mse(Error);
disp(sprintf('MSE Matlab Vs dsPIC: %e',MSE));
figure;
plot(Error,'gr','Linewidth',2);title('ERROR ENTRE DSPIC Y MATLAB FIXED POINT Q15');

%% Yapa
DSC_output = csvread('.././Archivos Import Export/dump_fft_sqrt_float.csv');  
figure;
plot(fAxis,DSC_output,'-bl');

Error = DSC_output - yExpAbs;
MSE = mse(Error);
disp(sprintf('MSE Matlab Vs dsPIC: %e',MSE));
figure;
plot(Error,'gr','Linewidth',2);title('ERROR ENTRE DSPIC Y MATLAB DOUBLE PRESICION');


