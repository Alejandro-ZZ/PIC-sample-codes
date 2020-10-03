LCD sample
==============
Basic template to use a display LCD 16x2 with PIC16F877A using the lcd.c library

Connections
-------------------

| PIC16F877A<br>Pin name | PIC16F877A<br>Pin number | LCD-16x2<br>Pin name |
|:----------------------:|:------------------------:|----------------------|
|           RD0          |            19            | Register select (RS) |
|           RD1          |            20            | Read/Write (RW)      |
|           RD2          |            21            | Enable (E)           |
|           RD4          |            27            | Data 4 (D4)          |
|           RD5          |            28            | Data 5 (D5)          |
|           RD6          |            29            | Data 6 (D6)          |
|           RD7          |            30            | Data 7 (D7)          |

**NOTE:** Remember conect a pull-up resistor to MCLR/Vpp (pin 1) of the PIC16F877A to avoid it resets.
