#include <Servo.h>

const int buttonPin = 2;
int buttonState = 0;
int previousButtonState = 0;
Servo myServo1;  // create first servo object to control a servo
Servo myServo2;  // create second servo object to control another servo

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  myServo1.attach(9); // attaches the first servo on pin 9 to the servo object
  myServo2.attach(10); // attaches the second servo on pin 10 to the servo object
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != previousButtonState) {
    if (buttonState == HIGH) {
      Serial.println("button pressed");
      myServo1.write(90); // tell first servo to go to 90 degrees
      myServo2.write(180); // tell second servo to go to 180 degrees, the opposite direction from 0
    } else {
      Serial.println("button released");
      myServo1.write(0); // tell first servo to go back to 0 degrees
      myServo2.write(0); // tell second servo to also go to 0 degrees
    }
  }
  previousButtonState = buttonState;
}
