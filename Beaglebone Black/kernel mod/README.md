# Getting To Blinky on the BeagleBone Black

This is "Getting To Blinky" on the BeagleBone Black (BBB) using a loadable kernel module (LKM).

A good source of background is http://derekmolloy.ie/kernel-gpio-programming-buttons-and-leds/

## Hardware:
The BeagleBone can't supply much power for an LED without potentially jeprodizing the BeagleBone.
Therefore, we will use a FET between the BeagleBone and the LED, as shown in the following figure.

![schematic](../../Beaglebone%20Black/schematic.png)

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
###Installing Headers
The include files needed to compile an LKM are not included by default in the (BBB) IoT Debian image.
Install the include files as follows.  First, get the kernel version:
```
debian@beaglebone:/var/lib/cloud9$ uname -a
Linux beaglebone 4.14.71-ti-r80 #1 SMP PREEMPT Fri Oct 5 23:50:11 UTC 2018 armv7l GNU/Linux
debian@beaglebone:/var/lib/cloud9$ uname -r
4.14.71-ti-r80
```
Next, check to see if the appropriate linux headers are available:
```
debian@beaglebone:/var/lib/cloud9$ sudo apt update
[sudo] password for debian:
Ign:1 http://deb.debian.org/debian stretch InRelease
Get:2 http://deb.debian.org/debian stretch-updates InRelease [91.0 kB]
...
Reading package lists... Done
Building dependency tree       
Reading state information... Done

debian@beaglebone:/var/lib/cloud9$ apt search linux-headers-$(uname -r)
Sorting... Done
Full Text Search... Done
linux-headers-4.14.71-ti-r80/unknown 1stretch armhf
Linux kernel headers for 4.14.71-ti-r80 on armhf

debian@beaglebone:/var/lib/cloud9$ sudo apt install linux-headers-$(uname -r)                               
Reading package lists... Done
...
Unpacking linux-headers-4.14.71-ti-r80 (1stretch) ...
Setting up linux-headers-4.14.71-ti-r80 (1stretch) ...
```

###Compile And Run
Start with the led.c program described in Chapter 16 of "Exploring Beaglebone" by Derek Molloy.
The code can be found at https://github.com/derekmolloy/exploringBB/

D. Moloy's led.c is intended to blink GPIO60 (GPIO1_28).  We will switch back to our old standard of GPIO49.
* Copy the files led.c and Makefile from https://github.com/derekmolloy/exploringBB/tree/version2/chp16/LED.
* Edit led.c to change instances of "60" to "49" (i.e. *default=60* to *default=49*, *gpioLED = 60* to *gpioLED = 49*, etc.).
