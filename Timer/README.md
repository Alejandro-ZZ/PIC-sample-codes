Timer usage
=======================
This project uses interruptions made by Timer0 to created a kind of cronometer. 
Timers are an important peripherial of most of the microcontrollers; they are 
modules that counts, in an autonomate way, machine cicles `N` or input pulses 
(in specific pins). The PIC16f877A has three of them called: Timer0, Timer1 and Timer2. 

Machine cicles
---------------------
In this case, interruption is made every milisecond. It means that funcion tagged 
with `#INT_TIMER0` is called every 1ms. This time is calculate with two amoungs:
time that takes one machine cicle (`Tc`) and how many of them have to count (`N`).

		Tc = 4(Tos)

`Tos` is the crystal's period (inverse of its frequency). In most of this projects 
it's used an external quartz crystal of 4MHz (this is applied with line `#use delay(clock=4000000)`).
Thus:

		Tc = 4(1/4MHz) = 1us

Due we want the interruption to be called every 1ms (`Tint = 1ms`):

		Tint = Tc * N 

		1ms = 1us * N

		N = 1000

`Tint` is the interruption period (how often it's called). 

Timer0
-----------------------------
The following equation is used to calculate the initial value of the timer0 (`Vinit`). 
This expression is for Timer0 and it might change for other timers. 

		N = (256 - Vinit) * Prediv

`Prediv` is a pre-scaler (or pre-divisor) of the clock frequency. For timer0 values available are:

| Pre-scaler<br>Configuration | Pre-scaler<br>Value |
|:---------------------------:|:-------------------:|
|          RTCC_DIV_2         |          2          |
|          RTCC_DIV_4         |          4          |
|          RTCC_DIV_8         |          8          |
|          RTCC_DIV_16        |          16         |
|          RTCC_DIV_32        |          32         |
|          RTCC_DIV_64        |          64         |
|          RTCC_DIV_128       |          128        |
|          RTCC_DIV_256       |          256        |

Using a `Prediv` of 4 (`RTCC_DIV_4`):

		Vinit = 256 - (N / Prediv) = 256 - (1000 / 4)
		Vinit = 6

Timer1
-----------------------------------
As mentioned, the expression of `N` and the pre-scaler values can be differents for
each timer. For example for timer1 the number of machine cilce needed to call the 
interrupt is known by the following equation:

		N = (65536 - Vinit) * Prediv

And the pre-scalers available are the one below.

| Pre-scaler<br>Configuration | Pre-scaler<br>Value |
|:---------------------------:|:-------------------:|
|          T1_DIV_BY_1        |          1          |
|          T1_DIV_BY_2        |          2          |
|          T1_DIV_BY_4        |          4          |
|          T1_DIV_BY_8        |          8          |

Conections
--------------------------

**LCD display**

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
