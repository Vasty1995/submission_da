
#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
	DDRC = 0x00;	//set DDRC to read input
	DDRB = 0xFF;	//set DDRB to output
	
	while(1)
	{
		if((PINC & 0b00000100) == 0b00000100)	//check if the button was pressed
		{
			_delay_ms(1000);			//delay 250ms
			PORTB = 0XFF;	//set PORTB 1 to output
		}
	}
}