/*
 * This is "Getting to Blinky" for the STM32 Nucleo-F030R8
 * The code could be built with a wait() function, but
 * that's just a waste of processor cycles.  Instead we
 * will track the time between loops and activate the LED
 * when needed.
 *
 * Note that the user LED on the board (LD2) is connected to
 * the Arduino-equivalent pin D13 (just like on the UNO),
 * also labeled as PA_5.  In a manner similar to the earlier work with
 * the UNO, we will use D12 (PA_6).
 */

#include "mbed.h"
void toggleLED();
#define LOW 0
#define HIGH 1
Timer timer;

int ledState = LOW;
const unsigned long intervalMillis = 1000;
unsigned long previousMillis = 0;

/*
 * This line seems to take the place of the setup()
 * that was done for the arduino
 */
DigitalOut myled(PA_6);

int main()
{
    timer.start();
    while(1) {
        unsigned long currentMillis = timer.read_ms();

        if (currentMillis - previousMillis >= intervalMillis) {
            toggleLED();
            previousMillis = currentMillis;
        }
    }
}

void toggleLED()
{
    if (ledState == LOW)
        ledState = HIGH;
    else
        ledState = LOW;
    myled = ledState;
}