int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);

  if (switchState == LOW) {
    // The button is not pressed
    digitalWrite(3, HIGH); // green
    digitalWrite(4, LOW); // red
    digitalWrite(5, LOW); // red
  } else {
    // the button is pressed
    digitalWrite(3, LOW); // green
    digitalWrite(4, LOW); // red
    digitalWrite(5, HIGH); // red

    delay(250);

    // Toggle LEDs
    digitalWrite(4, HIGH); // red
    digitalWrite(5, LOW); // red

    delay(250);

  }
} // end loop
