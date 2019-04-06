# Getting to Blinky on a bare AVR microcontroller

This is "Getting to Blinky" an a bare AVR microcontroller.  Compilation and updating the AVR requires
gcc and avrDude.

The code in this project is a modified version of code available in the book "Make: AVR Programming"
by Elliot Williams.  A great book if you want to get away from the Arduino IDE.  The code from the book
can be found at https://github.com/hexagon5un/AVR-Programming

An external LED can be hooked up to a choice of pins, as long as the selected
pin is capable of digital output.  Pins in OUTPUT mode are in a low-impendance state,
capable of providing or sinking up to 40 mA of current.

This project uses an ATMEGA328P-PU, similar to the generic ATMEGA328 but requires a little less power.
However, they do have different chip signatures so must be specified differently during compilation.

The equivalent to the Digital pin 12 used in the Arduino Blinky sketch is Port B Pin 4 (the ATmega328 uses the same pin mapping
as the ATmega168).  Unfortunately, Port B Pin 4 is also used during programming (it's the MISO pin).
So we will use Port B Pin 6 (or PB6) for our own LED. Note that on the 28-pin DIP package
PB6 is mapped to pin 9.

![ATmega328p pinout](./schematic.png)

My go-to LED is a red through-hole LED with a resistor soldered onto the cathode.  The arrangement is constructed
by clipping the LED cathode lead short (about 1 cm) and then clipping one lead of the resistor as well.  The two
short leads are then soldered together to produce an LED with two similar-sized leads, but one of the leads containing
a resistor.  I'm currently using a 330 ohm resistor, which (according to Adafruit's Circuit Playground) will give me
about 9 mA of current at 5V assuming a 2V drop across the LED.

## The Software Toolchain
Frankly, this is easiest on Linux, possibly just in a virtual machine (the following steps will refer to Unbuntu).
Following steps described in the book "Make: AVR Programming", use the following command to configure
all the necessary software:
```
sudo apt update
sudo apt install avrdude avrdude-doc binutils-avr avr-libc gcc-avr gdb-avr
sudo apt install make
```
The last line (the installation of make) may not be necessary if it's already installed.

## Configuring the makefile
A few things to watch out for if you aren't using the same hardware that I've used:
* Line 7 of the makefile should reflect the processor you are using (mine is atmega328p)
* Line 8 is set to 1 MHz.  It can be faster, but may need more capacitors, etc.
* Line 9 is set to 9600 baud.  Slow, but reliable.
* Line 23 sets the programmer to avrispmkII for the AVR ISP Mark II programmer. Change if needed.

## Configuring the Hardware
Power (+5V) is supplied to pin 7.  Pins 8 and 22 are grounded.  Programmer pins are connected as
follows:
```
GND --> ground
5V --> power rail
MISO --> pin 18
SCK --> pin 19
RESET -->pin 1
MOSI --> pin 17
```
The LED/resistor is connected between pins 9 (PB6) and 8 (GND).

## Using make
Pretty simple - the following commands will get the job done:
```
make all
make flash
```

