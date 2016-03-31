/*
- Plays a construction vehicle back-up tone when the button is held depressed
  in order to delight a 2-old-boy.
- To save battery when the power switch is inevitably left turned on, I removed
  the power LED with pliers and set it up to go into deep sleep after 16 minutes.

Circuit:
* 8-ohm speaker attached to Gnd and Pin 0
* button attached to Gnd and Pin 2

created 2016-03-30
by Mike Stebbins

Code based on the following code for Trinkets:
- sound code: http://web.media.mit.edu/~leah/LilyPad/07_sound_code.html
- deep sleep code: https://learn.adafruit.com/trinket-slash-gemma-space-invader-pendant/source-code
*/

#include <avr/power.h>
#include <avr/sleep.h>

#define tonePin 0
#define ledPin 1
#define buttonPin 2 
#define frequency 3300
#define onTime 250
#define offTime 250
#define ledOnOrOff 0

long millisToSleepAfter = 1000000L;  // 1000000L = 16.6 minutes
long timeThen = 1L;

void setup() {
  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(tonePin, OUTPUT);
  if (ledOnOrOff == 1)  {
    pinMode(ledPin, OUTPUT);
  }
  delay(20);
  timeThen = (long)millis();
}

void loop() {

  if ((long)(millis() - timeThen ) >= millisToSleepAfter)  {  //take a deep sleep nap
    GIMSK = _BV(PCIE);     // Enable pin change interrupt
    power_all_disable();   // All peripherals off
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sei();                 // Keep interrupts disabled
    sleep_mode();          // Power down CPU (pin 1 will wake)
  }
  
  boolean buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH)  {
    if (ledOnOrOff == 1)  {
      digitalWrite(ledPin,HIGH);
    }
    beep(tonePin,frequency,onTime);
    delay(offTime);
    }
    else  {
      if (ledOnOrOff == 1)  {
        digitalWrite(ledPin,LOW);
      }
      delay (10);  
    }
    delay(10);
}

// the sound producing function
void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{   
          int x;   
          long delayAmount = (long)(1000000/frequencyInHertz);
          long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
          for (x=0;x<loopTime;x++)  
          {  
              digitalWrite(speakerPin,HIGH);
              delayMicroseconds(delayAmount);
              digitalWrite(speakerPin,LOW);
              delayMicroseconds(delayAmount);
          }  
}


