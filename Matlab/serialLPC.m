%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% CLEAN ALL SECTION
    close all; clear all; clc;
    xTimePlot = 0;
    xSpecPlot = 0;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% PARÁMETROS DEL SISTEMA
    xAdqTime = 5;
    xNFrames = 10;
    xFs      = 4000;
    xBRate   = 115200;
    xAdcBits = 12;
    xVRef    = 3.3;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% CAPTURA Y AJUSTE DE DATOS a valores de tensión
[mData,vData] = dataSerialCapture( xAdqTime , xNFrames ,xFs , xBRate );
for jj = 1:xNFrames
    mData(:,jj) = dataAdjustToADC( xAdcBits , xVRef , mData(:,jj) );
end
vData = dataAdjustToADC( xAdcBits , xVRef , vData );
