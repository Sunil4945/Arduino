// Include the necessary libraries
#include <Arduino.h>

// Define the analog pin where LM35 temperature sensor is connected
const int lm35Pin = A0;
// Define the onboard LED pin
const int ledPin = 13;

// Variables to store temperature readings and previous state
int temperature = 0;
int previousState = LOW;

void setup() {
  // Initialize the serial communication for debugging purposes
  Serial.begin(9600);

  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the analog value from the LM35 sensor
  int sensorValue = analogRead(lm35Pin);

  // Convert the analog reading to temperature in degrees Celsius
  temperature = (sensorValue * 500) / 1023; // LM35 output is 10mV per degree Celsius

  // Print temperature value for debugging
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  // Check temperature conditions and control LED blinking
  if (temperature < 30) {
    blinkLED(250); // Blink LED every 250 milliseconds
  } else {
    blinkLED(500); // Blink LED every 500 milliseconds
  }
}

// Function to blink LED at a specified interval
void blinkLED(int interval) {
  static unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Toggle the LED state
    if (previousState == LOW) {
      previousState = HIGH;
    } else {
      previousState = LOW;
    }

    // Set the LED state
    digitalWrite(ledPin, previousState);
  }
}
