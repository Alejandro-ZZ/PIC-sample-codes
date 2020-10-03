ADC usage
=============
This project shows how to read analog values using internal ADC (chanel AN0) of PIC16F877A and print them in a LCD 16x2 display.

Conections
-----------------

1. LCD 16x2 display

| PIC16F877A<br>Pin name | PIC16F877A<br>Pin number | LCD-16x2<br>Pin name |
|:----------------------:|:------------------------:|----------------------|
|           RD1          |            20            | Register select (RS) |
|           RD2          |            21            | Read/Write (RW)      |
|           RD0          |            19            | Enable (E)           |
|           RD4          |            27            | Data 4 (D4)          |
|           RD5          |            28            | Data 5 (D5)          |
|           RD6          |            29            | Data 6 (D6)          |
|           RD7          |            30            | Data 7 (D7)          |

2. Potentiometer

To probe the code, conect a 50k ohms potentiometer as shown in pot_conections.jpg image.
