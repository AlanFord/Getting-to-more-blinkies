# Getting-to-more-blinkies
Getting to blinky on all of the micro controllers and single-board computers that I have.


Having collected a number of dev boards and single-board computers over the last couple of years, I realized that I hadn't completed a successful project on some of them.  So to refresh my memory and freshen my skills, this will be "getting to blinky" on all of my various boards (appologies to Contextual Electronics for repurposing the name).

Initially the goal will be to blink an LED.  The LED must be external to the board (using a canned routine to blink a
default on-board LED would be cheating).  This, by extension, may require a little bit of electronics to ensure that each 
board's current-handling capability isn't exceeded.

The boards will start with, at a minimum, an Arduino Uno, an Arduino Mega, a couple of STMicro dev boards, a bare ATTiny, 
Beaglebone Black, Pocket Beagle, Raspberry Pi 3+, Raspberry Pi Zero, a STMicro board built for a Contextual Electronics
class, and a HackRVA.org conference badge.  I may also have an Intel Edison buried deep in a pile in my study.  For the
boards that support it, I may try a couple of approaches using low level register changes, high level function calls,
and maybe an RTOS.  For the beaglebones, using both the main processor and the PRUs are fair game!
