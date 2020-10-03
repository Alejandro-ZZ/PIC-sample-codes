
Count project
============
This project implements multiplexing with common cathode 7-segment displays and PIC16F877A. 
The purpose is to know how many people are in a place and indicate if the place is empty, 
full or available within its capacity.


Components description
---------------
* Cargar, button used to set a default value when needed.
* Salio, sensor whose output is 0V when a person cross the place's output. Otherwise it's output is 5V.
* Entro, sensor whose output is 0V when a person cross the place's input. Otherwise it's output is 5V.
* Lleno, LED indicator that is turned ON when the place is full.
* Disponible, LED indicator that is turned ON when the place is available within its capacity.
* Vacio, LED indicator that is turned ON when the place is empty.
