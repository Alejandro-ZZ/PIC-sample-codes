#include <16F877A.h>

#FUSES	XT,NOWDT,NOPROTECT,NOLVP,PUT,BROWNOUT

#USE	delay(clock=4000000)

//Quick configuration of I/O ports
#use	fast_io(B)
#use	fast_io(C)

//Hexadecimal numbers that represent 0-9 in the 7 segments display 
int8 const Deco[10]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67};

//Number to show at 7 segment displays
int num = 59;

void IniPuertos(){

	set_tris_B(0x00);	//Port B as output
	set_tris_D(0x00);	//Port D as output
	output_B(0x00);		//Port B start with 0V output
  
}

void main(){
	
  //Setup code
	Inipuertos();
  
  //Main code that runs repeatedly
	while(true){		
    
    //Display unit
		output_bit(pin_B1,1);
		output_D(Deco[num%10]);
    
		delay_ms(50);
		output_bit(pin_B1,0);
    
    //Display ten
		output_bit(pin_B0,1);
		output_D(Deco[int(num/10)]);
    
		delay_ms(50);
		output_bit(pin_B0,0);
    
	}
}
