/*
 * mbis001_lab3_part4.c
 *
 * Created: 4/9/19 9:48:18 PM
 * Author : markbis
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char upperA = 0x00;
	unsigned char lowerA = 0x00;
	unsigned char pb = 0x00;
	unsigned char pc = 0x00;
	
    while (1) 
    {
		upperA = PINA & 0xF0;
		lowerA = PINA & 0x0F;
		
		pb = upperA >> 4;
		pc = lowerA << 4;
		
		PORTB = pb;
		PORTC = pc;
    }
	return 0;
}

