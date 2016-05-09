clc;
clear all;
close all;
%% Tabla para la senoidal
% -----------seteo de la señal----------------------%
fs=1000;
t=0:1/fs:1-(1/fs);
f=2;
L=2048;
w=2*pi*f;
s=sin(w*t);
s=[s s s s s];
s=s(1:L);

%% ------------señal generada-------------------------%
figure ('name','Señal pretendida');
plot(s);

%% ------------construcción de indexación-------------% 
a=char('0xIndexing,');
x=char('0x');
comma=char(',');

for i=1:length(s)           %la funcion senoCMSIS admite argumento de 0 a 1
    index(i)=asin(s(i)/pi);
    a=[a;x dec2q31(index(i),'hex') comma];
end

%% ------------construcción de se�al-------------% 
signalforLPC=char('0xsignaLPC,');
x=char('0x');
comma=char(',');

for i=1:length(s)           %la funcion senoCMSIS admite argumento de 0 a 1
    signalforLPC=[signalforLPC;x dec2q31(s(i),'hex') comma];
end



