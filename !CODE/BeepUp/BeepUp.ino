/*
 * 
Plays a construction vehicle back-up tone when the button is held depressed
in order to delight a 2-old-boy

 circuit:
 * 8-ohm speaker attached to Gnd and Pin 0
 * button attached to Gnd and Pin 2

 created 2016-03-28
 by Mike Stebbins
based roughly on Trinket sound code by: // http://web.media.mit.edu/~leah/LilyPad/07_sound_code.html
*/

#define tonePin 0
#define ledPin 1
#define buttonPin 2 
#define frequency 3000
#define onTime 250
#define offTime 250
#define ledOnOrOff 1

void setup() {
  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(tonePin, OUTPUT);
  if (ledOnOrOff == 1)  {
    pinMode(ledPin, OUTPUT);
  }
  delay(100);
}

void loop() {
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
      delay (250);  
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


