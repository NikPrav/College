//Prints a decimal number 
//on the display
#include <avr/io.h>
#include <util/delay.h>

 

void sevdisp(int num)
{
	switch(num)
	{
		case 1:PORTD= 0b11100100;
		PORTB = ((1 <<  PB0));
		break;
		case 2:PORTD=0b10010000;
		PORTB = ((0 <<  PB0));
		break;
		case 3:PORTD=0b11000000;
		PORTB = ((0 <<  PB0));
		break;
		case 4:PORTD=0b01100100;
		PORTB = ((0 <<  PB0));
		break;
		case 5:PORTD=0b01001000;
		PORTB = ((0 <<  PB0));
		break;
		case 6:PORTD=0b00001000;
		PORTB = ((0 <<  PB0));
		break;
		case 7:PORTD=0b11100000;
		
		PORTB = ((1 <<  PB0));
		break;
		case 8:PORTD=0b00000000;
		PORTB = ((0 <<  PB0));
		break;
		case 9:PORTD=0b01100000;
		PORTB = ((0 <<  PB0));
		break;
		case 0:PORTD=0b00000000;
		PORTB = ((1 <<  PB0));
		break;
	}
	
}
		


int main (void)
{
	
	
 //set PD2-PD7 as output pins 0xFC=0b11111100 (binary)
  DDRD   |= 0b11111100;
  //set PB0 as output pin
  DDRB    |= ((1 << DDB0));
 
  while (1) {		
	
		for(int i=0;i<10;++i)
		{
			sevdisp(i);
			_delay_ms(100);
		}
	} 
  
  
	/*1= 0b11100100
	2=
	3=
	4=0b01100100
	5=
	6=
	7=
	8=
	9=0b01100000
	0=0b00000000
	*/
  /* . */
  return 0;

}
