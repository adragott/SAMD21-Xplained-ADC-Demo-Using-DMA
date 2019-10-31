/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * This is a bare minimum user application template.
 *
 * For documentation of the board, go \ref group_common_boards "here" for a link
 * to the board-specific documentation.
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to system_init()
 * -# Basic usage of on-board LED and button
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <asf.h>
#include "pusart.h"
#include "padc.h"
int main (void)
{
	system_init();
	delay_init();
	system_interrupt_enable_global();
	pusart_init();
	padc_init();
	padc_start();
	
	// Clear screen
	printf("%c[2J", 27);
	// reset cursor pos
	printf("%c[u", 27);
	printf(" --\033[31;1m Penguin's\033[0;;40m SAMD21 ADC Demo using DMA -- \r\n");
	for (;;)
	{
		float voltage = padc_get_voltage();
		printf("Voltage: %d.%03d", (int)voltage, ((int)((voltage - (int)voltage) * 1000)));
		delay_ms(500);
		// clear line
		printf("%c[2K", 27);
		// reset cursor pos
		printf("%c[u", 27);
		// moves cursor one down
		printf("%c[1B", 27);
	}
}
