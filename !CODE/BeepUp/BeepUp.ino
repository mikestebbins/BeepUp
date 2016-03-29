/*
Plays a construction vehicle back-up tone when the button is held depressed

 circuit:
 * 8-ohm speaker on digital pin e

 created 2016-03-27
 by Mike Stebbins
 Very roughly based on code from Tom Igoe (http://www.arduino.cc/en/Tutorial/Tone)

This example code is in the public domain.

I left in the tones in Set-up and a For loop to select tones in loop, but commented them out

 */
#include "pitches.h"

#define tonePin 4
#define buttonPin 3 

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
//Serial.begin(9600);
pinMode(buttonPin,INPUT_PULLUP);
delay(500);
/*
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(tonePin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(tonePin);
  }
  */
  //Serial.println("here we go...");
}

void loop() {
  boolean buttonState = digitalRead(buttonPin);
  //Serial.println(buttonState);

  if (buttonState == HIGH)  {
    tone(tonePin,1000,750);
    delay(1100);
    noTone(tonePin);
    }
    else  {
      delay (250);  
    }
    delay(10);

 /*
  for (int i = 50; i <= 1000; i=i+5)  {
    tone(tonePin, i, 250);
    delay(200);
    Serial.println(i);
  }
  */
}

