/*
 * mbis001_lab3_part2.c
 *
 * Created: 4/9/19 8:19:54 PM
 * Author : markbis
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char fuel = 0x00;
	unsigned char sensor = 0x00;
	
    while (1) 
    {
		fuel = PINA & 0x0F;
		switch (fuel) {
			case (0x00): 
				sensor = 0x40;
				break;
			case (0x01):
			case (0x02): 
				sensor = 0x60;
				break;
			case (0x03):
			case (0x04): 
				sensor = 0x70;
				break;
			case (0x05):
			case (0x06): 
				sensor = 0x38;
				break;
			case (0x07):
			case (0x08):
			case (0x09): 
				sensor = 0x3C;
				break;
			case (0x0A):
			case (0x0B):
			case (0x0C):
				sensor = 0x3E;
				break;
			case (0x0D):
			case (0x0E):
			case (0x0F):
				sensor = 0x3F;
				break;
			default:
				sensor = 0x00;
				break;
		}
		PORTC = sensor;
    }
	return 0;
}

