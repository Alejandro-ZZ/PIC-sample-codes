Keyboar sample
================

This project shows how to implements an application with a matrix keyboard 
(using DriverTec4x4 library), LCD 16x2 display and PIC16F877A. Each keyboard 
key pressed is shown in the LCD display as a character.

Conections
-----------------

1. LCD 16x2 display

| PIC16F877A<br>Pin name | PIC16F877A<br>Pin number | LCD-16x2<br>Pin name |
|:----------------------:|:------------------------:|----------------------|
|           RD0          |            19            | Register select (RS) |
|           RD1          |            20            | Read/Write (RW)      |
|           RD2          |            21            | Enable (E)           |
|           RD4          |            27            | Data 4 (D4)          |
|           RD5          |            28            | Data 5 (D5)          |
|           RD6          |            29            | Data 6 (D6)          |
|           RD7          |            30            | Data 7 (D7)          |

2. Keyboard

| PIC16F877A<br>Pin name | PIC16F877A<br>Pin number | Keyboard<br>Column |
|:----------------------:|:------------------------:|:------------------:|
|           RB3          |            36            |         C1         |
|           RB2          |            35            |         C2         |
|           RB1          |            34            |         C3         |
|           RB0          |            33            |         C4         |

| PIC16F877A<br>Pin name | PIC16F877A<br>Pin number | Keyboard<br>Line |
|:----------------------:|:------------------------:|:----------------:|
|           RB4          |            37            |        L1        |
|           RB5          |            38            |        L2        |
|           RB6          |            39            |        L3        |
|           RB7          |            40            |        L4        |
