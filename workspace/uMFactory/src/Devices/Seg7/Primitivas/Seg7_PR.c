/*
 * 7Seg_PR.c
 *
 *  Created on: 11/03/2015
 *      Author: Pablo
 */


#include "Devices/Seg7/Seg7_buffer.h"
#include "Startup.h"

#ifdef MICRO_LPC1769
	#include "Devices/Seg7/Drivers/LPC1769/Seg7_FW_LPC1769.h"
#endif /* MICRO_LPC1769 */


void Disp_7seg_init()
{
	fw_Disp7Seg_init();
}

void set_7Segmentos(uint32_t val, uint8_t dp_idx)
{
	fw_set_7Segmentos(val, dp_idx);
}

void interrupt_7Segmentos()
{
	fw_interrupt_7Segmentos();
}
