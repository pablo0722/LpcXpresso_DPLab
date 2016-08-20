function Hd = highpass_iirfilter_df2transposed_3sos_B
%HIGHPASS_IIRFILTER_DF2TRANSPOSED_3SOS_B Returns a discrete-time filter object.

%
% MATLAB Code
% Generated by MATLAB(R) 7.12 and the DSP System Toolbox 8.0.
%
% Generated on: 27-Mar-2014 21:07:16
%

% Elliptic Highpass filter designed using FDESIGN.HIGHPASS.

% All frequency values are in Hz.
Fs = 8000;  % Sampling Frequency

Fstop = 1000;    % Stopband Frequency
Fpass = 1700;    % Passband Frequency
Astop = 60;      % Stopband Attenuation (dB)
Apass = 0.1;     % Passband Ripple (dB)
match = 'both';  % Band to match exactly

% Construct an FDESIGN object and call its ELLIP method.
h  = fdesign.highpass(Fstop, Fpass, Astop, Apass, Fs);
Hd = design(h, 'ellip', 'MatchExactly', match);
set(Hd, 'Arithmetic', 'double');
% Convert the filter to the Direct-Form II Transposed, SOS structure.
Hd = convert(Hd, 'df2tsos');
set(Hd, 'Arithmetic', 'double');
pnorm  = 'l1';    % Pth Norm
maxnum = 2;       % Maximum Numerator
numcon = 'None';  % Numerator Constraint
omode  = 'Wrap';  % Overflow Mode
svcon  = 'Unit';  % Scale Value Constraint

scale(Hd, pnorm, ...
    'MaxNumerator', maxnum, ...
    'NumeratorConstraint', numcon, ...
    'Overflowmode', omode, ...
    'ScaleValueConstraint', svcon, ...
    'SOSReorder', 'none');
set(Hd, 'Arithmetic', 'double');
% Set the arithmetic property.
set(Hd, 'Arithmetic', 'fixed', ...
    'CoeffWordLength', 16, ...
    'CoeffAutoScale', false, ...
    'NumFracLength', 15, ...
    'DenFracLength', 15, ...
    'ScaleValueFracLength', 15, ...
    'ProductMode', 'specifyprecision', ...
    'ProductWordLength', 32, ...
    'NumProdFracLength', 31, ...
    'DenProdFracLength', 31, ...
    'AccumMode', 'specifyprecision', ...
    'AccumWordLength', 40, ...
    'NumAccumFracLength', 31, ...
    'DenAccumFracLength', 31, ...
    'StateWordLength', 16, ...
    'StateAutoScale', true, ...
    'SectioninputWordLength', 16, ...
    'SectioninputFracLength', 6, ...
    'SectionoutputWordLength', 16, ...
    'SectionoutputFracLength', 7, ...
    'InputWordLength', 16, ...
    'inputFracLength', 15, ...
    'OutputWordLength', 16, ...
    'OutputMode', 'SpecifyPrecision', ...
    'outputFracLength', 15, ...
    'signed',        true, ...
    'RoundMode',     'convergent', ...
    'OverflowMode',  'Saturate', ...
    'CastBeforeSum', true);



% [EOF]