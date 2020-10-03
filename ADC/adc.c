#include <16F877A.h>

// Sets ADC converter with a resolution of 8 bits
#device ADC=8 

//====================== General Definitions ======================
#fuses XT,NOWDT,NOPROTECT,NOLVP,PUT,BROWNOUT
#use delay(clock=4000000)
#use fast_io (A)

#include <lcd.c>

//====================== Variable definitions ======================

int8	Valor,unidad,decena;
float	voltaje;

//====================== Funtions ======================
void IniPuertos(){	
	lcd_init();
	set_tris_C(0xFF);	// All port C as input
}

void IniConversorAD(){  
setup_adc(ADC_CLOCK_INTERNAL);  // Setup the converter 
setup_adc_ports(AN0);    		// Sets pin RA0 as analog input 
set_tris_A(0xFF);  				// All port A as input 
}

void LeerSenal(){
set_adc_channel(0);		// Select chanel 0 from ADC 
delay_us(10);   		// Delay needed between selecting channel and acquisition
Valor=read_adc();  		// Signal acquisition
}

// Converts value read from ADC to voltage value
void ProcesarSenal(){
	
	voltaje=(Valor*5.0)/255.0;
}


//====================== Main Program ======================

void main() {

	//Setup code
	IniPuertos();
	IniConversorAD();

	//Main code that runs repeatedly
	while(TRUE){
		
		// Read ADC value
		LeerSenal();
	
		// Converts to voltage value
		ProcesarSenal();

		// Set cursor position to (0,0)
		lcd_putc("\f");

		// Shows voltage value read with 4 decimals
		printf(lcd_putc,"VOLTS:%0.4f",voltaje);
		delay_ms(250);

	}
}
