/*
 * This is "Getting to Blinky" for the Arduino Uno.
 * The code could be built with a delay() function, but
 * that's just a waste of processor cycles.  Instead we
 * will track the time between loops and activate the LED
 * when needed.
 * 
 * Note the use of "int" vs "long".  On the Arduino UNO (a 16 bit device)
 * an int is 16 bits and a long is 32 bits.  Be warned, if this code is moved to
 * a 32 bit device the int may become 32 bits.
 * 
 * Also, the use of the unsigned long type allows the time (in milliseconds) to range
 * from 0 to just under 4.3E9, or a little more than 49 days.
 * 
 * An external LED can be hooked up to a choice of pins, as long as the selected
 * pin is capable of digital output.  Pins in OUTPUT mode are in a low-impendance state,
 * capable of providing or sinking up to 40 mA of current.
 * 
 * Digital pin 13 is convenient (as it's right next to a ground pin), but it's pre-wired
 * to the built-in LED.  So we will use digital pin 12 for our own LED.
 */
const int LED_PIN = 12;
int ledState = LOW;  // LOW must be pre-defined somewhere

const unsigned long intervalMillis = 1000;  // long different from int on an arduino?
unsigned long previousMillis = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);  // OUTPUT must be pre-defined somewhere
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= intervalMillis) {
    toggleLED();
    previousMillis = currentMillis;
  }
  
}

void toggleLED() {
  if (ledState == LOW)
    ledState = HIGH;
   else
    ledState = LOW;
   digitalWrite(LED_PIN, ledState);
}
