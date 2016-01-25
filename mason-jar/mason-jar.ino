// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
//int led = 13;

// the setup routine runs once when you press reset:
//void setup() {
//  // initialize the digital pin as an output.
//  pinMode(led, OUTPUT);
//}

// the loop routine runs over and over again forever:
//void loop() {
//  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);               // wait for a second
//  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000);               // wait for a second
//}



//ATtiny85 MASON JAR Mood Light 
//Date : 28/12/2014

const int redPin = 2; 
const int grnPin = 1; 
const int bluPin = 0;
const int LDRpin = 3;
int lightThresh = 250; // Light threshold. 0 - 1023. Lower number = activation at lower light level.

void setup()
{
  pinMode(redPin, OUTPUT);    
  pinMode(grnPin, OUTPUT);    
  pinMode(bluPin, OUTPUT);
  pinMode(LDRpin, INPUT);
}

void loop() {
  if (analogRead(LDRpin) < lightThresh)
  {
    redtoyellow();
    yellowtogreen();
    greentocyan();
    cyantoblue();
    bluetomagenta();
    magentatored();
  }
  else if (analogRead(LDRpin) >= lightThresh)
  {
    digitalWrite(redPin, LOW);
    digitalWrite(grnPin, LOW);
    digitalWrite(bluPin, LOW);
  }
}

void redtoyellow()
{
  digitalWrite(redPin, HIGH);
  digitalWrite(bluPin, LOW);

  // fade up green
  for(byte i=1; i<100; i++) {
    byte on  = i;
    byte off = 100-on;
    for( byte a=0; a<100; a++ ) {
      digitalWrite(grnPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(grnPin,LOW);
      delayMicroseconds(off);
    }
  }
}



void yellowtogreen()
{
  digitalWrite(grnPin, HIGH);
  digitalWrite(bluPin,LOW);

  // fade down red
  for(byte i=1; i<100; i++) {
    byte on  = 100-i;
    byte off = i;
    for( byte a=0; a<100; a++ ) {
      digitalWrite(redPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(redPin, LOW);
      delayMicroseconds(off);
    }
  }
}


void greentocyan()
{
  digitalWrite(grnPin, HIGH);
  digitalWrite(redPin, LOW);

  // fade up blue
  for(byte i=1; i<100; i++) {
    byte on  = i;
    byte off = 100-on;
    for( byte a=0; a<100; a++ ) {
      digitalWrite(bluPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(bluPin, LOW);
      delayMicroseconds(off);
    }
  }
}



void cyantoblue()
{
  digitalWrite(bluPin, HIGH);
  digitalWrite(redPin, LOW);

  // fade down green
  for(byte i=1; i<100; i++) {
    byte on  = 100-i;
    byte off = i;
    for( byte a=0; a<100; a++ ) {
      digitalWrite(grnPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(grnPin,LOW);
      delayMicroseconds(off);
    }
  }
}


void bluetomagenta()
{
  digitalWrite(bluPin, HIGH);
  digitalWrite(grnPin,LOW);

  // fade up red
  for(byte i=1; i<100; i++) {
    byte on  = i;
    byte off = 100-on;
    for( byte a=0; a<100; a++ ) {
      digitalWrite(redPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(redPin, LOW);
      delayMicroseconds(off);
    }
  }
}



void magentatored()
{
  digitalWrite(redPin,HIGH);
  digitalWrite(grnPin, LOW);

  // fade down blue
  for(byte i=1; i<100; i++) {
    byte on  = 100-i;
    byte off = i;
    for( byte a=0; a<100; a++ ) {
      digitalWrite(bluPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(bluPin, LOW);
      delayMicroseconds(off);
    }
  }
}

