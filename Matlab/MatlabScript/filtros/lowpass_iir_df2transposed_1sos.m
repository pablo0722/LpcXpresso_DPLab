function Hd = lowpass_iir_df2transposed_1sos
%LOWPASS_IIR_DF2TRANSPOSED_1SOS Returns a discrete-time filter object.

%
% MATLAB Code
% Generated by MATLAB(R) 7.12 and the DSP System Toolbox 8.0.
%
% Generated on: 08-May-2014 20:36:08
%

% Butterworth Lowpass filter designed using FDESIGN.LOWPASS.

% All frequency values are in Hz.
Fs = 48000;  % Sampling Frequency

Fpass = 1000;        % Passband Frequency
Fstop = 10000;       % Stopband Frequency
Apass = 1;           % Passband Ripple (dB)
Astop = 20;          % Stopband Attenuation (dB)
match = 'stopband';  % Band to match exactly

% Construct an FDESIGN object and call its BUTTER method.
h  = fdesign.lowpass(Fpass, Fstop, Apass, Astop, Fs);
Hd = design(h, 'butter', 'MatchExactly', match);
% Convert the filter to the Direct-Form II Transposed, SOS structure.
Hd = convert(Hd, 'df2tsos');

% [EOF]