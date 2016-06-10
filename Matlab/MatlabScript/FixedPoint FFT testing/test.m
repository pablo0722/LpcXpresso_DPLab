% Capture the current state of the display format and set it to 'loose' and
% 'long g'.
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

n = 64;                                     % Number of points
Fs = 4;                                     % Sampling frequency in Hz
t  = (0:(n-1))/Fs;                          % Time vector
f  = linspace(0,Fs,n);                      % Frequency vector
f0 = .2; f1 = .5;                           % Frequencies, in Hz
x0 = cos(2*pi*f0*t) + 0.55*cos(2*pi*f1*t);  % Time-domain signal
y  = fft(x0);                               % Frequency-domain transformation

figure(1);
subplot(211); plot(t,x0,'b.-'); xlabel('Time (s)'); 
ylabel('Amplitude');legend('x0')
subplot(212); plot(f,abs(y),'m.-'); xlabel('Frequency (Hz)');
ylabel('Magnitude');legend('abs(fft(x0))')

figure(2);
w0 = fi_radix2twiddles(n);
polar(angle(w0),abs(w0),'o')
title('Twiddle Factors: Complex roots of unity')

figure(3);
y = fi_m_radix2fft_algorithm1_6_2(x0, w0);
y0 = fft(x0); % MATLAB's built-in FFT for comparison
fi_fft_demo_plot(real(x0),y,y0,Fs,'Double data', {'FFT Algorithm 1.6.2','Built-in FFT'});

x = sfi(x0);  % Convert to signed fixed-point. Default Q15
w = sfi(w0);  % Convert to signed fixed-point

figure(4);
% Re-run the same algorithm with the fixed-point inputs
y  = fi_m_radix2fft_algorithm1_6_2(x,w);
fi_fft_demo_plot(real(x),y,y0,Fs,'Fixed-point data', ...
                        {'Fixed-point FFT Algorithm 1.6.2','Built-in'});
figure(5);
% Re-run the same algorithm with the fixed-point inputs & Scaling                
x = sfi(x0);
w = sfi(w0);

y = fi_m_radix2fft_withscaling(x,w);
fi_fft_demo_plot(real(x), y, y0/n, Fs, 'Fixed-point data', ...
                        {'Fixed-point FFT with scaling','Scaled built-in'});