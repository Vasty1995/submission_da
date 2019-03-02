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
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
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
#include <avr/io.h>


int main()
{
	DDRB = 0b00000100;
	PORTB = 0x00;
	TCCR1B = 5;         // set prescaler to 1024
	while(1) {
		if(TCNT1 == 0x01E7){
			PORTB ^= 0b00000100;
			TCNT1 = 0x00;
		}
	}
}