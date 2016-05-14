%> \file func_AudioFFT.m
%{
function [fAxis yExpAbs ] = func_FFT ( y,fs )
    N = length(y);
    fAxis = (0:fs/N:fs/2 - fs/N);
    Modesp = abs (fft(y)/N);
    Modesp = Modesp(1:N/2);     % 0 - Fn 
    Modesp = Modesp*2;          % Duplico las amplitudes por mostrar solamente el espectro positivo
    Modesp(1) = Modesp(1)/2;    % La componente de DC no hay que multiplicarla por 2
    yExpAbs = Modesp;
end
%}
function [fAxis yExpAbs ] = func_FFT ( y,fs )
    N = length(y);
    fAxis = (-fs/2:fs/N:fs/2 - fs/N);
    esp = fftshift(fft (y));
    yEspAbs = abs (esp)/N;
end