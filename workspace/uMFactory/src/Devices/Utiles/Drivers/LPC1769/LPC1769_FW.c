#include "Startup.h"

#ifdef MICRO_LPC1769

	#include "Devices/Utiles/Drivers/LPC1769/LPC1769_FW_reg.h"


	void SetPinSel(uint8_t puerto, uint8_t pin, uint8_t funcion)
	{
		puerto = (puerto*2) + (pin/16);
		pin = (pin%16)*2;

		PINSEL[puerto] &= ~(0x03 << pin);
		PINSEL[puerto] |= ((funcion & 0x03) << pin);
	}

	void SetPinModeIn(uint8_t puerto, uint8_t pin, uint8_t modo)
	{
		puerto = (puerto*2) + (pin/16);
		pin = (pin%16)*2;

		PINMODE[puerto] &= ~(0x03<<pin);
		PINMODE[puerto] |= ((modo & 0x03) << pin);
	}

	void SetPinModeOut(uint8_t puerto, uint8_t pin, uint8_t modo)
	{
		if(modo) PINMODE_OD[puerto] |= (0x01<<pin);
		else PINMODE_OD[puerto] &= ~(0x01<<pin);
	}

	void SetPinDir(uint8_t puerto, uint8_t pin, uint8_t dir)
	{
		puerto = puerto*8;

		if(dir) GPIO[puerto] |= (0x01<<pin);
		else GPIO[puerto] &= ~(0x01<<pin);
	}

	void SetPinMask(uint8_t puerto, uint8_t pin, uint8_t mask)
	{
		puerto = (puerto*8) + 4;

		if(mask) GPIO[puerto] |= (0x01<<pin);
		else GPIO[puerto] &= ~(0x01<<pin);
	}

	void SetPin(uint8_t puerto, uint8_t pin, uint8_t valor)
	{
		puerto = (puerto*8) + 5;

		if(valor) GPIO[puerto] |= (0x01<<pin);
		else GPIO[puerto] &= ~(0x01<<pin);
	}

	uint8_t GetPin(uint8_t puerto, uint8_t pin, uint8_t estado)
	{
		puerto = (puerto*8) + 5;

		return ( ((GPIO[puerto]>>pin) & 0x01) == estado ? (uint8_t)1 : (uint8_t)0 );
	}

#endif
