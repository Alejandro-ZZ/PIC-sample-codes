/////////////////////////////////////////////////////////////////////////////
////                                                                     ////
////            ATTENTION LIBRARY WITH MATRIX KEYBOARD                   ////
////                                                                     ////
////  LeerTeclado()  -> returns the code of the pressed button	         ////
////                    (between 0 and 15), or returns 16 if none        ////
////                    were pressed.                                    ////
////                                                                     ////
////                    This function should be called frequently        ////
////                    so as not to neglect the keyboard.               ////
////                                                                     ////
////*********************************************************************//// 
////  Routine developed by Miguel Angel Montilla                         ////
////                                                                     ////
/////////////////////////////////////////////////////////////////////////////

#use fast_io (B)

int8 LeerTeclado() {
	static int8 RotaCol, RotaFil, Fil, Col, Aux;
	static int1 TecladoPulsado;
	int8 NTecla;
	
	TecladoPulsado= false;
	NTecla= 0;	
	RotaFil= 0b11101111;
	Fil= 4;
	while(Fil!=0 && !TecladoPulsado){
		RotaCol= 0b11110111;
		output_b(RotaFil);
		Aux= input_B() | 0xF0;
		for(Col=4;Col!=0;Col--){
			if (Aux==RotaCol){
				TecladoPulsado= true;
				break;				
			}
			NTecla++;
			Shift_Right(&RotaCol,1,1);
		}
		Shift_Left(&RotaFil,1,1);
		Fil--;
	}
	return(NTecla);
}
