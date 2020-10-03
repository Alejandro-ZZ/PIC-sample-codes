#include <16F877A.h>

#fuses XT,NOWDT,NOPROTECT,NOLVP,PUT,BROWNOUT
#use delay(clock=4000000)

// Defines connections between LCD and PIC
//     ||  LCD pins  || Port D pins
#define		lcd_rs_pin		  pin_D0
#define		lcd_rw_pin		  pin_D1
#define		lcd_enable_pin	pin_D2
#define		lcd_data4		   pin_D4
#define		lcd_data5		   pin_D5
#define		lcd_data6		   pin_D6
#define		lcd_data7		   pin_D7

#include <lcd.c>

float x=3.5;

void main() {
  
  //Setup code
  lcd_init(); 	//LCD display initialization
	
  	//Main code that runs repeatedly
	while(TRUE) {
    
    		//Shows at position (0,0) 'Number: 3.5'
    		//%0.1f means that x is a float type variable and shows just 1 decimal
		printf(lcd_putc,"\fNumber: %0.1f",x);	//Enviar datos-[\f vaya a la posicion (0,0)]
		delay_ms(350);
    
	}
}
