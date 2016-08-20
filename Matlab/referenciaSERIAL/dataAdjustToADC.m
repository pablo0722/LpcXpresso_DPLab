function [ adjData ] = dataAdjustToADC( adcBits,vRef,data )
%DATAADJUSTTOADC Funcion para ajustar los datos a valores reales de tension

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% PARAMETROS DEL ADC
    NUM_BITS  = adcBits;
    NUM_CODES = 2^NUM_BITS;
    V_REF     = vRef;
    V_STEP    = V_REF / NUM_CODES;
    V_MAX     = V_REF - V_STEP;
    % V_MIN     = 0;
    % ADC_LEVEL = 0 : V_STEP : V_REF - V_STEP;
    adjData = zeros(length(data),1);
    for ii = 1 : length(data)
        adjData(ii) = data(ii) * V_MAX / NUM_CODES;
    end

end

