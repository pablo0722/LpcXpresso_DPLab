
% addpath('../funciones_varias');
% addpath(genpath('../MatlabScript'));
%% generacion de la señal
f=1000;
fs=22050;
L=2048;
Lword=32;  % Q31

signal = signalforMU_file(f,fs,L,Lword);
%plot(signal);
signal=signal*(2^32)*0.99;
%% establezco comunicación serie
srl = serial('/dev/ttyUSB1','BaudRate',9600,'DataBits',8,'StopBits',1);
fopen(srl);
for h=1:size(signal)
fwrite(srl,int32(signal(h)));
end


%% interpretacion de datos
% DSP_output = fscanf( srl,'%d');
resultados=fread(srl);
%resultados=DSP_output*(2^-32);
figure('name','resultados');
plot(resultados);

