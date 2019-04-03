/*
 * mbis001_lab2_part1.c
 *
 * Created: 4/3/2019 3:10:18 PM
 * Author : ucrcse
 */ 

#include <avr/io.h>


int main(void)
{
	DDRB = 0xFF;
	PORTB = 0x00;
	while(1){
		PORTB = 0x0F;
	}
}

