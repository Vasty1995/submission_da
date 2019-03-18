/*
 * DA2CT2C.c
 *
 * Created: 3/18/2019 12:53:09 PM
 * Author : YKengne
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(TIMER0_OVF_vect)	//interrupt function
{
	PORTB ^= 0xFF;		//toggle PORTB output
	TCNT0 = 65292l;		//reset counter
}

int main(void)
{
	DDRB = 0xFF;			//set PORTB to output
	TIMSK0 = (1 << TOIE0);	//clear interrupt flag
	TCCR0B = 0x05;			//set prescaler to 1024
	TCNT0 = 65292;			//set counter value
	sei();					//set interrupt
	while(1)
	{
	}
}