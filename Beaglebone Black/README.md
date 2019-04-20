# Getting To Blinky on the BeagleBone Black

This is "Getting To Blinky" on the BeagleBone Black.

Four approaches are available, using Linux shell scripts, using a C program, using Linux kernel mods, and 
programming a PRU.  Each is stored in a different folder.

The BeagleBone can't supply much power for an LED without potentially jeprodizing the BeagleBone.
Therefore, we will use a FET between the BeagleBone and the LED, as shown in the following figure.

![schematic](../Beaglebone%20Black/schematic.png)

The gpio pin we will be using to control the LED will be pin 23 on the P9 header.  That pin is named GPIO1_17, but 
is known to the linux kernel as gpio49.  Why gpio49?  The gpio pins of the BeagleBone Black are grouped into 
3 groups of 32 pins each: GPIO0, GPIO1, and GPIO2 (think 32 bits per register).  
So gpio pin 17 in the GPIO1 register is 17+1*(32) = 49, or gpio49.

In summary, that particular connection on the BeagleBone Black can be referred to as:
* Pin 23 on the P9 Header (the board physical configuration)
* GPIO1_17 (the processor configuration of pin 17 in GPIO Group 1)
* GPIO49 (as Linux sees it)


