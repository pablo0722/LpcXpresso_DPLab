#ifndef UTILES_PR_H
#define UTILES_PR_H




	typedef			unsigned int 			uint32_t;
	typedef 		unsigned short int 		uint16_t;
	typedef 		unsigned char 			uint8_t;

	#define 		__R 					volatile const		//!< Read
	#define 		__W 					volatile			//!< Write
	#define 		__RW 					volatile			//!< Read/Write




	/**************************************************************************************************/
	/********************************************* DEFINES ********************************************/
	/**************************************************************************************************/

		// Aca se pueden agregar y modificar leds con un nombre "comodo" para el usuario
	enum e_LED
	{
		LED_STICK,
		LED_1,
		LED_2,
		LED_3,
		LED_4,
		RGB_G,
		RGB_R,
		RGB_B,

		MAX_LEDS
	};


		// Aca se pueden agregar y modificar teclas con un nombre "comodo" para el usuario
	enum e_KEY
	{
		KEY0,
		KEY1,
		KEY2,
		KEY3_RC,
		KEY4_RC,

		MAX_KEYS
	};

	#if MAX_KEYS > 32
		#error No pueden haber mas de 32 teclas
	#endif


		// Aca se pueden agregar y modificar  Digitos del Displays 7-Segmentos con un nombre "comodo" para el usuario
	enum e_SEG7
	{
		DISP7S_1,
		DISP7S_2,
		DISP7S_3,
		DISP7S_4,
		DISP7S_5,
		DISP7S_6,

		MAX_DISP7S
	};



	enum e_OPCION_TIMER
	{
		OPCION_TIMER_UNICO,
		OPCION_TIMER_CONTINUO
	};



	/**************************************************************************************************/
	/******************************************** FUNCIONES *******************************************/
	/**************************************************************************************************/

		/*! \fn 		void SetPinSel(uint8_t puerto, uint8_t pin, uint8_t funcion)
		 *  \brief 		Elije funcion de un pin
		 *  \param 		puerto 		= (0 -> 3)
		 *  \param 		pin 		= (0 -> 31)
		 *  \param 		funcion 	= (FUNCION_GPIO, FUNCION_1, FUNCION_2, FUNCION_3)
		 *  \return 	void
		 */
		void SetPinSel(uint8_t puerto, uint8_t pin, uint8_t funcion);

		/*! \fn 		void SetPinModeIn(uint8_t puerto, uint8_t pin, uint8_t modo)
		 *  \brief 		Elije modo de entrada
		 *  \param 		puerto 		= (0 -> 3)
		 *  \param 		pin 		= (0 -> 31)
		 *  \param 		modo 		= (PULL_UP, PULL_DOWN, AMBOS, NINGUNO)
		 *  \return 	void
		 */
		void SetPinModeIn(uint8_t puerto, uint8_t pin, uint8_t modo);

		/*! \fn 		void SetPinModeOut(uint8_t puerto, uint8_t pin, uint8_t modo)
		 *  \brief 		Elije modo de salida
		 *  \param 		puerto 		= (0 -> 3)
		 *  \param 		pin 		= (0 -> 31)
		 *  \param 		modo 		= (NORMAL, OPEN_DRAIN)
		 *  \return 	void
		 */
		void SetPinModeOut(uint8_t puerto, uint8_t pin, uint8_t modo);

		/*! \fn 		void SetPinDir(uint8_t puerto, uint8_t pin, uint8_t dir)
		 *  \brief 		Elije direccion de un pin
		 *  \param 		puerto 		= (0 -> 3)
		 *  \param 		pin 		= (0 -> 31)
		 *  \param 		dir 		= (ENTRADA, SALIDA)
		 *  \return 	void
		 */
		void SetPinDir(uint8_t puerto, uint8_t pin, uint8_t dir);

			//puerto: 0 - 3
			//pin: 0 - 31
			//funcion: ENABLE_MASK
		void SetPinMask(uint8_t puerto, uint8_t pin, uint8_t mask);

			//puerto: 0 - 3
			//pin: 0 - 31
		void SetPin(uint8_t puerto, uint8_t pin, uint8_t valor);

			//puerto: 0 - 3
			//pin: 0 - 31
			//estado: BAJO / ALTO
		uint8_t GetPin(uint8_t puerto, uint8_t pin, uint8_t estado);



#endif
