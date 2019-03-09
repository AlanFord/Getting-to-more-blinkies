# Getting To Blinky on the Arduino Uno

This is "Getting To Blinky" on the Arduino Uno using the Arduino programming IDE.

First, note that the program (or really a fragment) must be kept in a directory (folder)
of the same name.  Hence the subdirectory "getting-to-blinky" that contains the program
of the same name.

An external LED can be hooked up to a choice of pins, as long as the selected
pin is capable of digital output.  Pins in OUTPUT mode are in a low-impendance state,
capable of providing or sinking up to 40 mA of current.

Digital pin 13 is convenient (as it's right next to a ground pin), but it's pre-wired
to the built-in LED.  So we will use digital pin 12 for our own LED.

My go-to LED is a red through-hole LED with a resistor soldered onto the cathode.  The arrangement is constructed
by clipping the LED cathode lead short (about 1 cm) and then clipping one lead of the resistor as well.  The two
short leads are then soldered together to produce an LED with two similar-sized leads, but one of the leads containing
a resistor.  I'm currently using a 330 ohm resistor, which (according to Adafruit's Circuit Playground) will give me
about 9 mA of current at 5V assuming a 2V drop across the LED.
