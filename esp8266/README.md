# Getting To Blinky on the ESP8266

This is "Getting To Blinky" on the ESP8266 using the Arduino programming IDE.

Sidenote - a good introduction to programming the ESP8266, including web development, can be found at:
https://ludzinc.blogspot.com/2019/07/easier-esp8266-development.html

First, note that the program (or really a fragment) must be kept in a directory (folder)
of the same name.  Hence the subdirectory "blink" that contains the program
of the same name.

## Auto
This program is going to be really simple - primarily a stripped-down version
of one of the sample programs.  So why do it?  The primary purpose is to capture all
of the details associated with just getting the Arduino IDE to talk to the board.
I'm using a NODEMCU generic knockoff.  As such, on my Mac I needed to:
1. Install the latest Silicon Labs USB-USART driver - see 
https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers
2. If you have installed an old kext to handle usb-to-serial communications (needed on
older OSX), delete it with the command:
sudo rm -rf /Library/Extensions/usbserial.kext
3. Add the ESP8266 board to the Arduino IDE following the instructions at 
https://randomnerdtutorials.com/esp8266-web-server/
4. For my board, the following was really important.
  * Tools > Board > NodeMCU 1.0 (ESP-12E Module) 
  * Tools > Flash Size > 4M (3M SPIFFS) 
  * Tools > CPU Frequency > 80 Mhz 
  * Tools > Upload Speed > 921600 
  * Tools > Port > /dev/cu.SLAB_USBtoUART 
5. Compile the program and start Blinking!

## Manual
This program is going to be more complicated - I want to demonstrate a web server that presents a 
web page.  The page will provide radio buttons for controlling the LED.
