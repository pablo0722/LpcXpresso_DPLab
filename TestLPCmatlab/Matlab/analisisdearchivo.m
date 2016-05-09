%% levantamiento de archivo
fid = fopen('sen100hex.txt');               % Abro el archivo de texto exportado por MPLABX

DSP_output = fscanf( fid, '%8x', inf);      % leo de a 8 datos hexa                                     % Leo las muestras en Q15 y las copio a un vector integer unsigned
DSP_output=dec2hex(DSP_output);             % convierto a valores hexa
% signal=hex2num(DSP_output);               % convierto a tipo double
signal=hex2dec(DSP_output);
figure('name','signal LPC');
hold on;
plot(signal,'r');