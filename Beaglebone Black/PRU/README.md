# Getting To Blinky on the BeagleBone Black

This is "Getting To Blinky" on the BeagleBone Black (BBB) using a program run on a *programmable real-time unit* (PRU).
There are two PRUs on a BBB but we will only use PRU0.  The PRUs are high speed (200 MHz) and have
their own appropriately high speed GPIOs, also known as Enhanced GPIO (EGP).  There are a lot of tutorials 
that describe how to toggle an EGP, so we will focus on using the standard GPIO.  However, here are pointers
to other options:

To blink a built-in LED, refer to *hello.c* at https://markayoder.github.io/PRUCookbook/02start/start.html.

To blink an LED on an EGP, consider a variation of the code in *pwm1.c* at https://markayoder.github.io/PRUCookbook/05blocks/blocks.html#blocks_pwm.
Note that some EGP pins are already in use, primarily to support the HDMI port.  If you need all of the EGP pins,
modify the boot file /boot/uEnv.txt so that it looks as follows:
```
debian@beaglebone:/boot$ grep video uEnv.txt
###Disable auto loading of virtual capes (emmc/video/wireless/adc)
#disable_uboot_overlay_video=1
```

However, to blink an LED on a standard GPIO, we will use a variation of the program *gpio1.c* at https://markayoder.github.io/PRUCookbook/06io/io.html#_accessing_gpio.


## Hardware:
The BeagleBone can't supply much power for an LED without potentially jeprodizing the BeagleBone.
Therefore, we will use a FET between the BeagleBone and the LED, as shown in the following figure.

![schematic](../../Beaglebone%20Black/schematic.png)

## GPIO Pins - What's in a Name?
The gpio pin we will be using to control the LED will be pin 23 on the P9 header.  That pin is named GPIO1_17, but 
is known to the linux kernel as gpio49.  Why gpio49?  The gpio pins of the BeagleBone Black are grouped into 
3 banks of 32 pins each: GPIO0, GPIO1, and GPIO2 (think 32 bits per register).  
So gpio pin 17 in the GPIO1 register is 17+1*(32) = 49, or gpio49.

In summary, that particular connection on the BeagleBone Black can be referred to as:
* Pin 23 on the P9 Header (the board physical configuration)
* GPIO1_17 (the processor configuration of pin 17 in GPIO Bank 1)
* GPIO49 (as Linux sees it)

## Setting up the PRU (it might not be configured to run)
First, check the version of the kernel being used:
```
debian@beaglebone:/var/lib/cloud9$ uname -r
4.14.71-ti-r80
```
Now check to see what firmware is available:
```
debian@beaglebone:/var/lib/cloud9$ ls /lib/firmware/AM335X-PRU*
/lib/firmware/AM335X-PRU-RPROC-4-14-TI-00A0.dtbo          /lib/firmware/AM335X-PRU-RPROC-4-4-TI-PRUCAPE-00A0.dtbo
/lib/firmware/AM335X-PRU-RPROC-4-14-TI-PRUCAPE-00A0.dtbo  /lib/firmware/AM335X-PRU-RPROC-4-9-TI-00A0.dtbo
/lib/firmware/AM335X-PRU-RPROC-4-19-TI-00A0.dtbo          /lib/firmware/AM335X-PRU-RPROC-4-9-TI-PRUCAPE-00A0.dtbo
/lib/firmware/AM335X-PRU-RPROC-4-19-TI-PRUCAPE-00A0.dtbo  /lib/firmware/AM335X-PRU-UIO-00A0.dtbo
/lib/firmware/AM335X-PRU-RPROC-4-4-TI-00A0.dtbo           /lib/firmware/AM335X-PRU-UIO-4-19-00A0.dtbo
```
We won't be using the "UIO"-based firmware as it is intended for the *old* way of accessing the PRU.  Instead,
we will use the "RPROC"-based firmware for the 4.14 kernel version.  My BBB was already configured 
correctly with the appropriate line un-commented in /boot/uEnv.txt:
```
debian@beaglebone:/boot$ grep pru uEnv.txt
###pru_rproc (4.4.x-ti kernel)
#uboot_overlay_pru=/lib/firmware/AM335X-PRU-RPROC-4-4-TI-00A0.dtbo
###pru_rproc (4.14.x-ti kernel)
uboot_overlay_pru=/lib/firmware/AM335X-PRU-RPROC-4-14-TI-00A0.dtbo
###pru_uio (4.4.x-ti, 4.14.x-ti & mainline/bone kernel)
#uboot_overlay_pru=/lib/firmware/AM335X-PRU-UIO-00A0.dtbo
```

## Let's Go!
There are five files that are derived from https://markayoder.github.io/PRUCookbook/06io/io.html#_accessing_gpio:
* AM335x_PRU.cmd
* gpio_setup.sh
* gpio1.c
* Makefile
* resource_table_empty.h

Let's start with the easiest first.

resource_table_empty.h is an empty resource table file.  Nothing much to see here, but the PRU compiler requires it.

gpio_setup.sh is run as 
```
source gpio_setup.sh
```
This configures the P9_23 pin for output and defines some variables used in compilation.  Modifying the original
gpio_setup.sh to work with our GPIO pin of choice only required changing P9_11 to P9_23.

gpio1.c is the program that will run on the PRU
Starting with the gpio1.c program i the PRU Cookbook, we will change the gpio pin to pin 23 on header 9, 
also known as pin 17 in gpio group 1.  Hence change the line
```
#define P9_11   (0x1<<30)           // Bit position tied to P9_11
```
to be
```
#define P9_23   (0x1<<17)           // Bit position tied to P9_23
```
Since we need to be working with gpio bank 1 (i.e. group 1), the main program is changed to
```
void main(void)
{
    uint32_t *gpio1 = (uint32_t *)GPIO1;

    while(1) {
        gpio1[GPIO_SETDATAOUT/4] = P9_23;
        __delay_cycles(200000000);
        gpio1[GPIO_CLEARDATAOUT/4] = P9_23;
        __delay_cycles(200000000);
    }
}
```
We've replaced gpio0 with gpio1, P9_11 with P9_23, and 1E6 with 2E6 to get a 1 second delay. (The
PRU operates at 200 MHz.)

AM335x_PRU.cmd is the linker file, telling the linker where to put stuff in memory.  The defaults work well for us.

Makefile is the final file, and the most interesting.  It's configured to have options to stop the PRU, start the PRU,
and compile/install the program.  To do a complete build, just use the command *make*.  This will stop the PRU, compile
the code, load the program on the PRU, and then start the PRU.

While the LED is blinking, you run the command *make stop* and the PRU will stop.  Running *make start* will
start the PRU running without needing to reinstall the program.  Note that if you stop the PRU when the LED
is lit, it will stay on.  Restarting the PRU will start the blinking again.

