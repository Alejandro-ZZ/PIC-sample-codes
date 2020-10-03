#include <16F877A.h>

//================================================================
//								General definitions										        //
//================================================================
#fuses XT,NOWDT,NOPROTECT,NOLVP,PUT,BROWNOUT
#use delay(clock=4000000)

#use	fast_io(B)	//Configuracion rapida entrada salida
#use	fast_io(C)	//configurar puertos rapidamente

#DEFINE hab_uni	PIN_B1
#DEFINE	hab_dec	PIN_B0	

#DEFINE	entro	input(PIN_B2)
#DEFINE	salio	input(PIN_B3)
#DEFINE	cargar	input(PIN_B4)

#DEFINE	lleno		PIN_B5
#DEFINE	vacio		PIN_B6
#DEFINE	disponible	PIN_B7
	

//================================================================
//								Variables declaration									        //
//================================================================

//Hexadecimal numbers that represent 0-9 in the 7 segments display 
int8 const Deco[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};

//================================================================
//								         Funtions								              //
//================================================================

void IniPuertos(){
	
	set_tris_B(0x1C);		//Declare port 'B' as 11111100
	set_tris_D(0x00);		//Declare port 'D' as output
	output_B(0x00);			//Port B start with 0V output
	port_b_pullups(TRUE);	//Set pull-up resistor at port B.
}

void IniVariables(){
	
	output_D(0);
	int unidad =0;
	int decena =0;
	int tiempo = 150;
}

//Display a 00-99 number 
void Mostrar(int unidades,int decenas){
	
	output_high(hab_uni);
	output_D(Deco[unidades]);
	delay_ms(50);

	output_low(hab_uni);
	output_high(hab_dec);
	output_D(Deco[decenas]);
	delay_ms(50);
	
	output_low(hab_dec);
	
}
//==========================================================
//																							          //
//									    Main program									  	//
//																							          //
//==========================================================

void main() {

	//Setup code
	IniPuertos();
	IniVariables();

		//Main code that runs repeatedly
		while(TRUE){

			//A person got in
			if (entro==0){
	
				delay_ms(tiempo);
				unidad++;
					
					if (unidad == 10){
					
						unidad = 0;
						decena++;
					}
					if (decena > 9){
						
						unidad=9;
						decena=9;
					}
				
			}

			//A person got out
			if (salio == 0){
				
				delay_ms(tiempo);

					if (unidad == 0 && decena > 0){
						
						unidad = 9;
						decena--;
					}
					else if (unidad == 0 && decena == 0){
					
						unidad=0;
						decena=0;
					}
					else{
						unidad--;
					}	
			}

			//Set 99 number as default if cargar button is pressed
			if (cargar == 0){
				
				delay_ms(tiempo);
				unidad = 9;
				decena = 9;

			}

		//Place is full
		if (unidad==9 && decena==9){
			output_high(disponible);
			output_high(vacio);
			output_low(lleno);
		}
		//Place is empty
		else if (unidad==0 && decena==0){
			output_high(disponible);
			output_low(vacio);
			output_high(lleno);
		}
		//Place available with persons
		else{
			output_low(disponible);
			output_high(vacio);
			output_high(lleno);
		}
		//Shows number of persons in a place
		Mostrar(unidad,decena);	
	}
}
