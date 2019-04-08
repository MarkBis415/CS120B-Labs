/*
 * mbis001_lab2_part1.c
 *
 * Created: 4/3/2019 3:10:18 PM
 * Author : ucrcse
 */ 

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTA = 0x00;
	
	unsigned char pa0 = 0x00;
	unsigned char pa1 = 0x00;
	while(1){
		if((pa1 == 0x00) && (pa0 == 0x01)){
			PORTB = 0x01;
		}
		else{
			PORTB = 0x00;
		}
	}
	return 0;
}

