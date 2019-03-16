# Getting To Blinky on the BeagleBone Black

This is "Getting To Blinky" on the BeagleBone Black using Linux shell scripts.

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

## Scripting Away
The LED can be flashed from the command line using the following:
```
    cd /sys/class/gpio
    echo 49 > export
    cd gpio49
    echo out > direction
    echo 1 > value
    echo 0 > value
    cd ..
    echo 49 >unexport
```    
These commands have been captured in two shell scripts that meet the goals of "Getting to Blinky" - 
*blink.sh* and *cleanup.sh*.  Both scripts will need to be run as root.  An easy way to do this is to run the
command *sudo bash* to switch to root before running the scripts.

*blink.sh* sets up gpio pin 49 and starts the blinking.  Use CTRL-C to stop the 
script.  The LED may be left off or on, depending on the state of the script when it is terminated.

Run the script *cleanup.sh* to unexport the gpio pin and shut down the LED.


