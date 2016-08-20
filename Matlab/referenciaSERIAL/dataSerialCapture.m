function [ matData,vecData ] = dataSerialCapture( adqTime , nFrames ,fSamp , baudRate )
%SERIALCAPTURE Funcion para tomar datos por el puerto serie

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%% PARAMETROS DE LAS SEÑALES
    % El tiempo que quiero grabar en total
        ADQ_TIME      = adqTime; % 10 segundos             
    % En cuantas ventanas de captura lo voy a dividir
        FRAMES        = nFrames; % 10 ventanas de 1 segundos
    % Tiempo por frame
        TIME_X_FRAME  = ADQ_TIME / FRAMES;
    % La velocidad de muestreo del ADC
        FS            = fSamp; % 4000
    % La cantidad total de muestras de informacion que tengo por ventanaa
        NUMEL_DATA    = FS * ADQ_TIME / FRAMES;
    % Como las muestras vienen por UART la cantidad de datos enviados es
    % ... el doble de la cantidad total de muestras.
        NUMEL_RAWDATA = NUMEL_DATA * 2;
        
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%% PARAMETROS DE LA COMUNICACION
    puerto  = 'COM3';
    request = 255;
    s       = serial(puerto);
              set(s,'DataBits',8);
              set(s,'StopBits',1);
              set(s,'BaudRate',baudRate); % 115200
              set(s,'Parity','None');
              set(s,'terminator','LF');
              set(s,'Timeout',10);
              set(s,'InputBufferSize',NUMEL_RAWDATA);

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%% CONTENEDORES
    rawdata = zeros(NUMEL_RAWDATA,FRAMES);
    data    = zeros(NUMEL_DATA,FRAMES);

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%% Comienzo del script
    fopen(s);                               % Abro fd para la comunicacion
    pause(2);                               % Da tiempo a inicializar
    disp('Solicitando envío de datos...');  
    fwrite(s,request,'uchar');              % Solicito datos
    disp('Capturando datos...');
    tic
        for jj = 1:FRAMES
            [rawdata(:,jj),count] = fread(s,NUMEL_RAWDATA,'uchar');
        end
    toc
    disp('Fin de la captura');
    fwrite(s,request,'uchar');              % Finalizo la comunicacion

    fclose(s);                              % Cierro fd
    delete(s);                              % Borro fs
    clear s;                                % Elimino completamente

    for jj = 1 : FRAMES
        for ii = 1 : NUMEL_DATA
             % Los datos se envian de a 8 bytes. Se deben reordenar para que
             % se puedan interpretar como datos de 16 bytes
             data(ii,jj) = rawdata(2*ii-1,jj)*256 + rawdata(2*ii,jj);
        end
    end
    
    matData = data;
    vecData = data(:);

end

