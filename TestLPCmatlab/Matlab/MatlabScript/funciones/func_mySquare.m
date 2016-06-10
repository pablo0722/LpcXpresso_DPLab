%> \file func_mySquare.m
%> \brief Generador de señal cuadrada.
%> \author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
%> \author UTN FRBA - DPLab
%> \date 2010.04.01
%> \version 1.0.0

%> \brief Genera una señal cuadrada.
%> \param A Amplitud.
%> \param f0 Frecuencias de las señal cuadrada.
%> \param N Cantidad de muestras a generar.
%> \param d Ciclo de actividad 0 - 1
%> \param fs Frecuencia de muestreo.
%>
%> \return tAxis Eje de tiempo.
%> \return y Señales resultantes.
%>
function [tAxis y] = func_mySquare (A, f0, N, d, fs)

    %tAxis = (0:1/fs:(N - 1)/(fs));          %-- Eje de tiempo --
    %y = A .* square (2 * pi .* tAxis .* f0, d * 100);
    tAxis = (0:1/fs:(N - 1)/(fs));          %-- Eje de tiempo --
    %tAxis2 = tAxis(ones (length(f0), 1), :);
    %f0 = f0(ones (length(tAxis), 1), :)';
    %A = A(ones (length(tAxis), 1), :);
    %d = d(ones (length(tAxis),1), :)';
    y = zeros (N, length(A));
    for h = 1:length(A) 
        y(:,h) = A(h) .* square (2 * pi .* (tAxis .* f0(h)), d(h) * 100);
    end;

end
