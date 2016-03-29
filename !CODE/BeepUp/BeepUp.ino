/*
Plays a construction vehicle back-up tone when the button is held depressed

 circuit:
 * 8-ohm speaker on digital pin e

 created 2016-03-27
 by Mike Stebbins
TODO FIX THIS Very roughly based on code from Tom Igoe (http://www.arduino.cc/en/Tutorial/Tone)
 */


#define tonePin 0
#define ledPin 1
#define buttonPin 2 
#define frequency 3000
#define onTime 300
#define offTime 300

void setup() {
  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(tonePin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  delay(100);
}

void loop() {
  boolean buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH)  {
    digitalWrite(ledPin,HIGH);
    beep(tonePin,frequency,onTime);
    delay(offTime);
    }
    else  {
      digitalWrite(ledPin,LOW);
      delay (250);  
    }
    delay(10);
}

// the sound producing function
void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{   // http://web.media.mit.edu/~leah/LilyPad/07_sound_code.html
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


