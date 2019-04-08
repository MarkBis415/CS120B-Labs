/*
 * mbis001_lab2_part3.c
 *
 * Created: 4/3/2019 3:21:31 PM
 * Author : ucrcse
 */ 

#include <avr/io.h>

//Extension of part 2
int main(void)
{
    /* Replace with your application code */
    	DDRA = 0x00; PORTA = 0xFF;
    	DDRC = 0xFF; PORTC = 0x00
    	
    	unsigned char cntavail = 0x00;
    	unsigned char parkingSensor0 = 0x00;
    	unsigned char parkingSensor1 = 0x00;
    	unsigned char parkingSensor2 = 0x00;
    	unsigned char parkingSensor3 = 0x00;
    	
    	while (1)
    	{
	    	parkingSensor0 = PINA & 0x01; //to see if bit 1 is available
	    	parkingSensor1 = PINA & 0x02; // ' ' ' bit 2 ' '
	    	parkingSensor2 = PINA & 0x04; // ' ' ' bit 3 ' '
	    	parkingSensor3 = PINA & 0x08; // ' ' ' bit 4 ' '
	    	
	    	cntavail = parkingSensor0 + (parkingSensor1 >> 1) + (parkingSensor2 >> 2) + (parkingSensor3 >> 3)
	    	if(cntavail == 0x04){
				PORTC = 0x80;
			}
			else{
				cntavail = parkingSensor0 + parkingSensor1 + parkingSensor2 + parkingSensor3;
				cntavail = (~cntavail) & 0x0F;
				PORTC = cntavail;
			}
    	}
    	return 0;
}

