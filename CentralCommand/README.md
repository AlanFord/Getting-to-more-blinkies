# Getting To Blinky on the Central Command

This is "Getting To Blinky" on an STM32 home-built dev board.

The Central Command is a dev board built as part of a class exercise for the Contextual Electronics
on-line electronics course.  Central Command is constructed around an STM32F030R8 32-bit ARM MCU.
The dev board uses an FTDI device for USB communication and has breakouts for all source of wonderful
I/O.  Programming the Central Command dev board can be accomplished using the 
ST-LINK/V2-1 hardware debugger/programmer that comes with any of STMicroelectronics NUCLEO
development boards.  With only one judicious jumper selection, the ST-LINK/V2-1 can be used to program
home-brew boards built around the STmicro chips.

## Central Command
The schematics are found in [schematics](../blob/master/CentralCommand/Central Command Schematic.pdf) 
and the board layout is found in [schematics](../blob/master/CentralCommand/Central Command Layout.pdf).  
Header P101 breaks out I2C2 peripheral for 
an I2C sensor connection.  Headers P302 and P303 provide chained I2C connections for external boards over
the I2C1 peripheral.  USART1 and SPI connections are available on headers P104 and P105, respectively.  The USART2 
peripheral is dedicated to USB communications via the FTDI FT232RQ device.  Finally, headers P102 and P103
provide access to a number of GPIO pins.

A user LED is available on pin PB10.  Power can be provided over the USB port or via header P202.  P202 can
accomodate an external power supply between +3.75V and +6V.  The power supply can provide up to
250 mA to the board.  A reset button is provided and header P304
provides access to the BOOT0 pin.  Header P301 accomodates an ST-LINK programming connection.

## Pin Configurations
The STM32F030R8 package has 48 pins, but this is not sufficient for each pin to have a unique functions and
still provide access to all of the STM32F030R8 functions.  To remedy this, each pin has a primary (default)
function and a set of possible alternate functions.  The collection of peripherals used by Central Command
requires the use of a number of alternate functions for several pins.  

The default pin layout is

![pin layout](../CentralCommand/Pinout.png)

The pin layout for Central Command can
be summarized (using ST32CUBEMX) as
![pin layout](../CentralCommand/DefaultPinout.png)

The datasheet for the stm32f030r8 mcu indicates that the max current for the i/o pins is 25 mA.  That will easily
suffice for our little LED/resistor combiniation.  Similar to the work with the Arduino UNO, the LED will be connected
between ground and digitial IO pin D12 (PA_6) because D13 (PA_5) is already taken up controlling the 
on-board user LED.
