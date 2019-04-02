/*
 * DA3A.c
 *
 * Created: 4/2/2019 1:28:12 PM
 * Author : YKengne
 */ 

#define F_CPU 16000000UL
#define BAUD 9600

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

void USART_tx_string( char* data); //prototype for printing string
void USART_init( void ); //prototype for USART_init function
void USART_send(char val); //prototype fo send function

char str[] = "Hello World!"; //holds the array of characters
char outs[20];  //number of character spaces
volatile float tmp = 3.141593;//floating point value 


int main(void)
{
	TCCR1B = 5; //sets the prescaler to 1024
	TIMSK1 = (1<<TOIE1); //enables overflow interrupt
	TCNT1 = 49911; //TCNT1 value the counter counts up to

	USART_init(); //call function

	sei();//enables the interrupt 


	while(1)
	{
		
	}
}


ISR(TIMER1_OVF_vect)
{
	USART_tx_string(str); //pass string to function
	USART_tx_string("\n"); //line feed
	USART_send('5'); //sends the value to the terminal 
	USART_tx_string("\n"); //line feed
	snprintf(outs,sizeof(outs),"%f\r\n", tmp);//prints the floating point value 
	USART_tx_string(outs); //pass array to function
	USART_tx_string("\n"); //linefeed

	TCNT1 = 49911; //reset tcnt
}

void USART_init( void )
{
	UBRR0H = 0; //set lower bits
	UBRR0L = F_CPU/16/BAUD - 1; //BAUD prescaler 
	UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); /* 8-bit data */
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);    //enable rx and tx 
}


//sends the data to the serial port 
void USART_tx_string(char *data)
{
	while((*data != '\0'))
	{
		while(!(UCSR0A & (1<<UDRE0)));
			UDR0 = *data;
				data++;
	}
}

void USART_send(char val)
{

	while(!(UCSR0A & (1<<UDRE0)));
	 UDR0 = val;
}