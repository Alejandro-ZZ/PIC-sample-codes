#include <16F877A.h>

// General definitions
#fuses XT,NOWDT,NOPROTECT,NOLVP,PUT,BROWNOUT
#use delay(clock=4000000)

//Quick configuration of I/O port B
#use fast_io (B)

// Defines connections between LCD and PIC
#define		lcd_rs_pin		pin_D0
#define		lcd_rw_pin		pin_D1
#define		lcd_enable_pin	pin_D2
#define		lcd_data4		pin_D4
#define		lcd_data5		pin_D5
#define		lcd_data6		pin_D6
#define		lcd_data7		pin_D7			

#include 	<lcd.c>
#include 	<DriverTec4x4.c>

// Variable definitions
int8 Tec;
char num;

//=================Funtions=================

void IniPuertos(){	
	set_tris_B(0x0F);		// Puerto mitad salida - Entrada.
	port_b_pullups(TRUE);	// Resistencias de pull-up en el puerto B.
	lcd_init();	
}

// Execute the required action for each key on the keyboard.
void ProcesarTeclado(){	
	    
	switch (Tec){
		case 0:					// Attention routine to key "1"
	    	num="1";
	    	break;
		case 1:					// Attention routine to key "2"
	    	num="2";
	    	break;
		case 2:					// Attention routine to key "3"
	    	num="3";
	    	break;
		case 3:					// Attention routine to key "A"
	    	num="A";
	    	break;
		case 4:					// Attention routine to key "4"
	    	num="4";
	    	break;
		case 5:					// Attention routine to key "5"
	    	num="5";
	    	break;
		case 6:					// Attention routine to key "6"
	    	num="6";
	    	break;
		case 7:					// Attention routine to key "B"
	    	num="B";
	    	break;
		case 8:					// Attention routine to key "7"
	    	num="7";
	    	break;
		case 9:					// Attention routine to key "8"
	    	num="8";
	    	break;
		case 10:				// Attention routine to key "9"
	    	num="9";
	    	break;
		case 11:				// Attention routine to key "C"
	    	num="C";
	    	break;
		case 12:				// Attention routine to key "*"
	    	num="*";
	    	break;
		case 13:				// Attention routine to key "0"
	    	num="0";
	    	break;
		case 14:				// Attention routine to key "#"
	    	num="#";
	    	break;
		case 15:				// Attention routine to key "D"
	    	num="D";
	}
}

//=================Main Program=================

void main() {

	//Setup code
	IniPuertos();

	//Main code that runs repeatedly
	while(TRUE) {

		// Tec save the code of keyboard key  pressed.
		// A value of 16 means that no keyboard key was pressed.
		Tec= LeerTeclado();	

		// Makes a specific function depending of Tec value
	 	ProcesarTeclado();

		lcd_gotoxy(1,1);
		printf(lcd_putc,"Keyboard sample");
		lcd_gotoxy(1,2);
		printf(lcd_putc,"Key pressed: %c", num);
	
	}
}
