function [flotante, hexa] = q2dec(valor, q_fractional)
%% [flotante, hexa] = q2dec(valor, q_fractional)
% Convierte un numero de punto fijo a hexadecimal y a punto flotante
%
% valor [in]:           Numero que se quiere convertir
% q_fractional [in]:    Cantidad de bits en parte fraccional (debe ser 15 o 31. ej: si es q15, entonces q_fractional = 15)
%
% flotante [out]:       Valor convertido a punto flotante
% hexa [out]:           Valor convertido a hexadecimal como string

%%
    if q_fractional == 15 || q_fractional == 31
        WordLength  = q_fractional+1 ;                                              % Simulo conversor de 16 bits signado - ( signed fractional Q15 )
        FractLength = q_fractional ;
        q = quantizer( 'Mode', 'fixed','Format' ,[WordLength FractLength],'OverflowMode', 'Saturate','RoundMode','floor');

        if q_fractional == 15
            Y = uint16(valor);
            n = 4;
        elseif q_fractional == 31
            Y = uint32(valor);
            n = 8;
        end
        hexa = dec2hex(Y);
        flotante = hex2num(q,hexa);
        hexa = ['0x' dec2hex(Y, n)];
    else
        error('q_fractional [in]:    Cantidad de bits en parte fraccional (debe ser 15 o 31. ej: si es q15, entonces q_fractional = 15)');
    end

end