/*
 * mbis001_lab3_part1.c
 *
 * Created: 4/9/19 5:29:47 PM
 * Author : markbis
 */ 

#include <avr/io.h>

unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

unsigned char funcCount(unsigned char cnt, unsigned char x){
	for(unsigned i = 0; i < 8; i++){
		if(GetBit(x,i)){
			cnt++;
		}
	}
	return cnt;
}

int main(void)
{
    /* Replace with your application code */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0x00;
	
	unsigned char counter = 0x00;
	unsigned char result = 0x00;
	unsigned char tempA = 0x00;
	unsigned char tempB = 0x00;
	
    while (1) 
    {
		tempA = PINA & 0xFF;
		tempB = PINB & 0xFF;
		result = funcCount(counter, tempA);
		result = result + funcCount(counter, tempB);
		
		PORTC = result;
		
    }
	return 0;
}

