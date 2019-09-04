/*
  ESP8266 Blink by Simon Peter
  Blink the red LED on the ESP-12 module
  This example code is in the public domain

  The red LED on the ESP-12 module is connected to GPIO16

  Note that this sketch uses LED_BUILTIN to find the pin with the internal LED.
  That's why this program works on the ESP-01 as well as the ESP-12!
  For a discuss of on-board LEDs on a NODEMCU board, see
  https://circuitdigest.com/microcontroller-projects/getting-started-with-nodemcu-esp12
*/

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
  // but actually the LED is on; this is because
  // it is active low on the ESP-01)
  delay(1000);                      // Wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(3000);                      // Wait for three seconds (to demonstrate the active low LED)
}
