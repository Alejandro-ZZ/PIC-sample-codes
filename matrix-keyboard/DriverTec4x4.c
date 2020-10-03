/////////////////////////////////////////////////////////////////////////////
////                                                                     ////
////            LIBRERÍA DE ATENCIÓN A TECLADO MATRICIAL                 ////
////                                                                     ////
////  Tecla= LeerTeclado()   retorna el código del pulsador oprimido	 ////
////                         (entre 0 y 15), o retorna 16 si ninguno     ////
////                         se oprimió.                                 ////
////                                                                     ////
////                         Esta función debe llamarse con frecuencia   ////
////                         para no desatender el Teclado.              ////
////                                                                     ////
////*********************************************************************//// 
////  Rutina desarrollada por Miguel Angel Montilla                      ////
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
				break;					// Salir del ciclo 'for'
			}
			NTecla++;
			Shift_Right(&RotaCol,1,1);
		}
		Shift_Left(&RotaFil,1,1);
		Fil--;
	}
	return(NTecla);
}