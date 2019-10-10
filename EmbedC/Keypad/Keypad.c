#include <avr/io.h> 
#include <util/delay.h> 
#include <stdlib.h> 
#include "LCD.h"

char get_key (void);
char READ_SWITCH(void);
void Circ_Init(void);






int main(void)
{
// use PortB for LCD interface
 //DDRB = 0xFF; // 1111.1111; set PB0-PB7 as outputs	 
 //DDRD=0b00001111; // Set Pd0-PD7 as inputs
 //DDRC=0b111111;// Set PC0-PC5 as o/p
 
 Circ_Init();
 LCD_Init(); // initialize LCD controller
 
 
 
 
 
  while(1)
 {
	 LCD_Clear();
	 char key=get_key();
	 LCD_Char(key);
		_delay_ms(700);
	 
	}
	
}		
		  
void Circ_Init(void)
{
	// use PortB for LCD interface
	DDRB = 0xFF; // 1111.1111; set PB0-PB7 as outputs	 
	DDRD=0b00000000; // Set PD4-PD7 as i/p
	DDRC=0xFF;// Set PC0-PC5 as o/p
	PORTD = 0xFF;    //enable all pull-ups  
	return;

}

/*
char READ_SWITCHES(void)	
{	
	//RowA = 0; RowB = 1; RowC = 1; RowD = 1; 	//Test Row A
	PORTD=0b01110000;
	

	if ((PINC & (1<<PC0))) { _delay_ms(10000); while ((0<<PD4)); return '7'; }
	if (!(PINC & (1<<PC1))) { _delay_ms(10000); while ((0<<PD5)); return '8'; }
	if (!(PINC & (1<<PC2))) { _delay_ms(10000); while ((0<<PD6)); return '9'; }
	if (!(PINC & (1<<PC3))) { _delay_ms(10000); while ((0<<PD7)); return '/'; }
	
	//RowA = 1; RowB = 0; RowC = 1; RowD = 1; 	//Test Row B
	PORTD=0b10110000;

	if (!(PINC & (1<<PC0))) { _delay_ms(10000); while ((0<<PD4)); return '4'; }
	if (!(PINC & (1<<PC1))) { _delay_ms(10000); while ((0<<PD5)); return '5'; }
	if (!(PINC & (1<<PC2))) { _delay_ms(10000); while ((0<<PD6)); return '6'; }
	if (!(PINC & (1<<PC3))) { _delay_ms(10000); while ((0<<PD7)); return 'x'; }
	
	//RowA = 1; RowB = 1; RowC = 0; RowD = 1; 	//Test Row C
	PORTD=0b11010000;

	if (!(PINC & (1<<PC0))) { _delay_ms(10000); while ((0<<PD4)); return '1'; }
	if (!(PINC & (1<<PC1))) { _delay_ms(10000); while ((0<<PD5)); return '2'; }
	if (!(PINC & (1<<PC2))) { _delay_ms(10000); while ((0<<PD6)); return '3'; }
	if (!(PINC & (1<<PC3))) { _delay_ms(10000); while ((0<<PD7)); return '-'; }
	
	//RowA = 1; RowB = 1; RowC = 1; RowD = 0; 	//Test Row D
	PORTD=0b11100000;

	if (!(PINC & (1<<PC0))) { _delay_ms(10000); while ((0<<PD4)); return 'C'; }
	if (!(PINC & (1<<PC1))) { _delay_ms(10000); while ((0<<PD5)); return '0'; }
	if (!(PINC & (1<<PC2))) { _delay_ms(10000); while ((0<<PD6)); return '='; }
	if (!(PINC & (1<<PC3))) { _delay_ms(10000); while ((0<<PD7)); return '+'; }

	return 'n';           	// Means no key has been pressed
}
*/


char READ_SWITCHES()
{
	PORTC = 0b00000000;//Declare PC0-PC7 as o/p
	PORTD = 0b11110000;// Declare PD0-PD7 as i/p
	//PORTD|=(0<<PD7);
	//PORTD|=(0<<PD6);
	
	if (!(PIND & (1<<PD4)))
	{
		PORTC=0b00001110;
		PORTC=PORTC;
		if (!(PIND & (1<<PD4)))
		return '1';
		PORTC=0b00001101;
		PORTC=PORTC;
		if (!(PIND & (1<<PD4)))
		return '2';
		PORTC=0b00001011;
		PORTC=PORTC;
		if (!(PIND & (1<<PD4)))
		return '3';
		PORTC=0b00000111;
		PORTC=PORTC;
		if (!(PIND & (1<<PD4)))
		return '+';
	}
	else if (!(PIND & (1<<PD5)))
	{
		PORTC=0b00001110;
		PORTC=PORTC;
		if (!(PIND & (1<<PD5)))
		return '4';
		PORTC=0b00001101;
		PORTC=PORTC;
		if (!(PIND & (1<<PD5)))
		return '5';
		PORTC=0b00001011;
		PORTC=PORTC;
		if (!(PIND & (1<<PD5)))
		return '6';
		PORTC=0b00000111;
		PORTC=PORTC;
		if (!(PIND & (1<<PD5)))
		return '-';
	}
	
	else if (!(PIND & (1<<PD6)))
	{
		PORTC=0b00001110;
		PORTC=PORTC;
		if (!(PIND & (1<<PD6)))
		return '7';
		PORTC=0b00001101;
		PORTC=PORTC;
		if (!(PIND & (1<<PD6)))
		return '8';
		PORTC=0b00001011;
		PORTC=PORTC;
		if (!(PIND & (1<<PD6)))
		return '9';
		PORTC=0b00000111;
		PORTC=PORTC;
		if (!(PIND & (1<<PD6)))
		return '*';
	}
	
	else if (!(PIND & (1<<PD7)))
	{
		PORTC=0b00001110;
		PORTC=PORTC;
		if (!(PIND & (1<<PD7)))
		return '=';
		PORTC=0b00001101;
		PORTC=PORTC;
		if (!(PIND & (1<<PD7)))
		return '0';
		PORTC=0b00001011;
		PORTC=PORTC;
		if (!(PIND & (1<<PD7)))
		return 'c';
		PORTC=0b00000111;
		PORTC=PORTC;
		if (!(PIND & (1<<PD7)))
		return '/';
	}

	
	
	return 'n';           	// Means no key has been pressed
}

	 

char get_key(void)
{
	char key = 'n';
	while(key=='n')
	{
		key=READ_SWITCHES();
		//LCD_Char(key);
	}
	return key;
}

	

