# Getting To Blinky on the STM32 Nucleo-F030R8

This is "Getting To Blinky" on the STM32 Nucleo-F030R8 ARM dev board.

The Nucleo-F030R8 dev board is a nice little board that I originally acquired as part of a class exercise
at Contextual Electronics.  It uses an 32 bit ARM microcontroller and has headers compatible with
the Arduino UNO.  But what is really fascinating is that it includes an on-board ST-LINK/V2-1 hardware
debugger/programmer.  And with judicious jumper selections, the ST-LINK/V2-1 can be used to program
home-brew boards built around the STmicro chips.

Two approaches to "Getting to Blinky" will be demonsrated - MBED and HAL.  MBED is simpler,
but uses the web to compile and store the source code.  HAL is just a high-level abstraction
library; an IDE and toolchain is still needed.  This is accomplished using the TrueSTUDIO iDE.

The datasheet for the stm32f030r8 mcu indicates that the max current for the i/o pins is 25 mA.  That will easily
suffice for our little LED/resistor combiniation.  Similar to the work with the Arduino UNO, the LED will be connected
between ground and digitial IO pin D12 (PA_6) because D13 (PA_5) is already taken up controlling the 
on-board user LED.
