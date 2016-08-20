clear all;                                                      % Limpia el worksapace
close all;                                                      % Cierra todas las ventanas
clc;

addpath .././funciones;                                            % Path relativo de funciones
addpath .././filtros;                                              % Path relativo de funciones

% Capture the current state of the display format and set it to 'loose' and 'long g'.
formatAtStartOfThisDemo        = get(0,'Format');
formatSpacingAtStartOfThisDemo = get(0,'FormatSpacing');
format loose
format long g
% Capture the current state of and reset the fi display and logging
% preferences to the factory settings.
fiprefAtStartOfThisDemo = get(fipref);
reset(fipref);
% Capture the present state of and reset the global fimath to the factory
% settings.
globalFimathAtStartOfThisDemo = fimath;
resetglobalfimath;

A = 1; f0 = 2560;N = 256;fs = 44211;ph = 0;NBits = 16;d=0.5;   

figure(1);
w0 = fi_radix2twiddles(N);
polar(angle(w0),abs(w0),'o')
title('Twiddle Factors: Complex roots of unity')  



% Señal de prueba

[tAxis signal] = func_mySin (A, f0, N, ph, fs);

% Convert to signed fixed-point
figure(2);
% Re-run the same algorithm with the fixed-point inputs & Scaling                
x = sfi(signal); % Convert to signed fixed-point. Default Q15
w = sfi(w0); % Convert to signed fixed-point

y = fi_m_radix2fft_withscaling(x,w);
y0 = fft(signal); % MATLAB's built-in FFT for comparison
fi_fft_demo_plot(real(x), y, y0/N, fs, 'Fixed-point data', ...
                        {'Fixed-point FFT with scaling','Scaled built-in'});