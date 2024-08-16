#include <Arduino.h>


const int ledPin = 2; 
const int buttonPin = 4; 


volatile bool ledState = false;


void IRAM_ATTR handleButtonPress() {
  ledState = !ledState; 
  digitalWrite(ledPin, ledState); 
}

void setup() {
  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLDOWN);

  
  digitalWrite(ledPin, LOW);

  
  attachInterrupt(digitalPinToInterrupt(buttonPin), handleButtonPress, RISING);
}

void loop() {
  
  
}
