# Getting to Blinky on a bare AVR microcontroller

This is "Getting to Blinky" an a bare AVR microcontroller.  Compilation and updating the AVR requires
gcc and avrDude.

The code in this project is a modified version of code available in the book "Make: AVR Programming"
by Elliot Williams.  A great book if you want to get away from the Arduino IDE.  The code from the book
can be found at https://github.com/hexagon5un/AVR-Programming

An external LED can be hooked up to a choice of pins, as long as the selected
pin is capable of digital output.  Pins in OUTPUT mode are in a low-impendance state,
capable of providing or sinking up to 40 mA of current.


<<<<<  The following needs updating >>>>>>>
Digital pin 13 is convenient (as it's right next to a ground pin), but it's pre-wired
to the built-in LED.  So we will use digital pin 12 for our own LED.

My go-to LED is a red through-hole LED with a resistor soldered onto the cathode.  The arrangement is constructed
by clipping the LED cathode lead short (about 1 cm) and then clipping one lead of the resistor as well.  The two
short leads are then soldered together to produce an LED with two similar-sized leads, but one of the leads containing
a resistor.  I'm currently using a 330 ohm resistor, which (according to Adafruit's Circuit Playground) will give me
about 9 mA of current at 5V assuming a 2V drop across the LED.
