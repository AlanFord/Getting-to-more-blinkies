# Getting To Blinky on the BeagleBone Black

This is "Getting To Blinky" on the BeagleBone Black using a program written in C.

## Hardware:
The BeagleBone can't supply much power for an LED without potentially jeprodizing the BeagleBone.
Therefore, we will use a FET between the BeagleBone and the LED, as shown in the following figure.

![schematic](https://github.com/AlanFord/Getting-to-more-blinkies/blob/master/Beaglebone%20Black/schematic.png)

## GPIO Pins - What's in a Name?
The gpio pin we will be using to control the LED will be pin 23 on the P9 header.  That pin is named GPIO1_17, but 
is known to the linux kernel as gpio49.  Why gpio49?  The gpio pins of the BeagleBone Black are grouped into 
3 groups of 32 pins each: GPIO0, GPIO1, and GPIO2 (think 32 bits per register).  
So gpio pin 17 in the GPIO1 register is 17+1*(32) = 49, or gpio49.

In summary, that particular connection on the BeagleBone Black can be referred to as:
* Pin 23 on the P9 Header (the board physical configuration)
* GPIO1_17 (the processor configuration of pin 17 in GPIO Group 1)
* GPIO49 (as Linux sees it)

## Let's Go!
The program is blinky.c.  It takes one argument of *on*, *off*, or *flash*.  This program performs the same
steps that you could use from the shell to control the gpio port via the /sys/class/gpio/gpio49 hardware mapping.
Using a C language interface requires a bit more code that doing a shell script, but it's also a wee bit more friendly.

To run blinky, first make sure that gpio49 is exported and is set to output.  The following shell commands 
can be used to do this:
```
cd /sys/class/gpio
echo 49 > export
cd gpio49
echo out > direction
```    
Now just run blinky, using one of these three forms:
```
./blinky on
./blinky off
./blinky flash
```
The setup commands could be included in blinky.c rather than having to execute shell commands, but that's an
easy fix if you are interested in doing it.
