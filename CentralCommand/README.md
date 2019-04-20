# Getting To Blinky on the Central Command

This is "Getting To Blinky" on an STM32 home-built dev board.

The Central Command is a dev board built as part of a class exercise for the Contextual Electronics
on-line electronics course.  Central Command is constructed around an STM32F030R8 32-bit ARM MCU.
The dev board uses an FTDI device for USB communication and has breakouts for all source of wonderful
I/O.  Programming the Central Command dev board can be accomplished using the 
ST-LINK/V2-1 hardware debugger/programmer that comes with any of STMicroelectronics NUCLEO
development boards.  With only one judicious jumper selection, the ST-LINK/V2-1 can be used to program
home-brew boards built around the STmicro chips.

The datasheet for the stm32f030r8 mcu indicates that the max current for the i/o pins is 25 mA.  That will easily
suffice for our little LED/resistor combiniation.  Similar to the work with the Arduino UNO, the LED will be connected
between ground and digitial IO pin D12 (PA_6) because D13 (PA_5) is already taken up controlling the 
on-board user LED.
