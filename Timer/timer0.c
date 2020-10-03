#include <16F877A.h>


//======================== General Definitions ========================
#fuses XT,NOWDT,NOPROTECT,NOLVP
#use delay(clock=4000000)

//Quick configuration of I/O ports
#use fast_io (B)	
#use fast_io (C)
#use fast_io (D)


#define		lcd_rs_pin		pin_D0
#define		lcd_rw_pin		pin_D1
#define		lcd_enable_pin	pin_D2
#define		lcd_data4		pin_D4
#define		lcd_data5		pin_D5
#define		lcd_data6		pin_D6
#define		lcd_data7		pin_D7			

#include 	<lcd.c>


//======================== Variable declarations ========================

	int16 x=0;
	int clock=0;
  
  
//======================== Funtions ========================
void IniPuertos(){	

	set_tris_D(0);			// Puerto D como salida.
	lcd_init();
}

#INT_TIMER0
void INTERRUPCION_1ms(){		//Attention to interruption every 1ms
	SET_TIMER0(6);
	x++;
	if (x==1000){
		clock++;
		x=0;
	}
}	


//======================== Main Program ========================

void main() {
	
	//Setup code
	IniPuertos();

  // Set working mode on RTCC_INTERNAL and pre-scaler of 4
	setup_timer_0(RTCC_INTERNAL | RTCC_DIV_4);
  
  //Start conunting from 6 to 255
	SET_TIMER0(6);	
  
  // Clear interruption flag of TIMER0
	clear_interrupt(INT_TIMER0);
  
  // Enable interruption
	enable_interrupts(INT_TIMER0);
	enable_interrupts(GLOBAL);	
	
	//Main code that runs repeatedly
	while(TRUE) {
		
		// Go to position (0,0)
		lcd_putc("\f");
	
		// Print the seconds count
		printf(lcd_putc,"Tiempo:%u",clock);
		delay_us(10);

	}
}
