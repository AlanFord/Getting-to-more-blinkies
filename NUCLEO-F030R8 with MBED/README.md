# Getting To Blinky on the STM32 Nucleo-F030R8 Dev Board

This is "Getting To Blinky" on the STM32 Nucleo-F030R8 dev board.

The Nucleo-F030R8 dev board is a nice little board that I originally acquired as part of a class exercise
at Contextual Electronics.  It uses an 32 bit ARM microcontroller and has headers compatible with
the Arduino UNO.  But what is really fascinating is that it includes an on-board ST-LINK/V2-1 hardware
debugger/programmer.  And with judicious jumper selections, the ST-LINK/V2-1 can be used to program
home-brew boards built around the STmicro chips.

It's always best to hunt around the MBed site or the STMicro site and get the latest firmware for the ST-LINK/V2-1
portion of the board.  On a mac, the java flasher works well.

The Nucleo-F030R8 board appears to be compatible only with MBED 2, not MBED 5, hence no RTOS.
It's likely due to the limited flash (64kB) and sram (8kB).  But it will still work!

The easiest way to get the MBED process started is to plug the STM32 board into a usb port.
A "NODE_F030R8" drive will appear containing a MBED.HTM file.  Open that file and you will be delivered to
the https://os.mbed.com website.  Jump to the compiler and then make sure that your board select is set
to the Nucleo-F030R8.  After entering your code, compile, and the web page will download the 
executable bin file.  Drag that over to the board in the file manager and the loader will take over.

The datasheet for the stm32f030r8 indicates that the max current for the i/o pins is 25 mA.  That will easily
suffice for our little LED/resistor combiniation.  Similar to the work with the Arduino UNO, the LED will be connected
between ground and digitial IO pin D12 (PA_6) because D13 (PA_5) is already taken up controlling the 
on-board user LED.
