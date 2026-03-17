#include <Arduino.h>

const int buzzerPin = A0;
const int numKeys = 13;

// Pins 2-13 (Digital) and A1 (used as Digital)
const int buttonPins[numKeys] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A1};

// Frequencies for C4, C#4, D4, D#4, E4, F4, F#4, G4, G#4, A4, A#4, B4, C5
const int frequencies[numKeys] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, 523};

void setup() {
  pinMode(buzzerPin, OUTPUT);
  for (int i = 0; i < numKeys; i++) {
    // INPUT_PULLUP removes the need for external resistors
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void loop() {
  bool anyKeyPressed = false;
  
  for (int i = 0; i < numKeys; i++) {
    // Check if button is pressed (LOW because of INPUT_PULLUP)
    if (digitalRead(buttonPins[i]) == LOW) {
      tone(buzzerPin, frequencies[i]);
      anyKeyPressed = true;
      break; // Ensures only one note plays at a time
    }
  }

  // If no buttons are held down, stop the sound
  if (!anyKeyPressed) {
    noTone(buzzerPin);
  }
}
