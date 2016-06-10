%> \file func_mySin.m
%> \brief Generador de se�al senoidal.
%> \author Ing. Jer�nimo F. Atencio (jerome5416@gmail.com)
%> \author UTN FRBA - DPLab
%> \date 2010.04.01
%> \version 1.0.0

%> \brief Genera una se�al senoidal.
%> \param A Vector fila de Amplitudes.
%> \param f0 Vector fila de frecuencias de las se�ales senoidales.
%> \param N Cantidad de muestras a generar.
%> \param ph Vector fila de fase inicial en radianes.
%> \param fs Frecuencia de muestreo.
%>
%> \return tAxis Eje de tiempo.
%> \return y Se�ales resultantes.
%>
%> \warning Una amplitud negativa cambia la fase.
%> \todo Validar parametros.
function [tAxis y] = func_mySin (A, f0, N, ph, fs)

    tAxis = (0:1/fs:(N - 1)/(fs));          %-- Eje de tiempo --
    tAxis2 = tAxis(ones (length(f0), 1), :);
    f0 = f0(ones (length(tAxis), 1), :)';
    A = A(ones (length(tAxis), 1), :);
    ph = ph(ones (length(tAxis),1), :);
    y = A .* sin (2 * 3.14 .* (tAxis2 .* f0)' + ph);

end
