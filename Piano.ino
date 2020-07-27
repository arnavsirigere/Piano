#include "pitches.h"

int buzzer = 9;
int led = 10;
int duration = 100;
int keys[] = { 7, 6, 5, 4, 3 };
int notes[] = { NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5 };

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  for (int i = 0; i < 5; i++) {
    pinMode(keys[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i < 5; i++) {
    int key = keys[i];
    if (digitalRead(key) == LOW) {
      digitalWrite(led, HIGH);
      play(i);
      digitalWrite(led, LOW);
    }
  }
}

void play(int key) {
  tone(buzzer, notes[key], duration);
  //delay(250);
}
