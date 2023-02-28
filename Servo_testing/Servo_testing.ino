#include <Servo.h>
int led=13;
Servo myservo;
int pos=0;
void setup() {
  pinMode(led,OUTPUT);
  myservo.attach(7);
}

void loop() {
  digitalWrite(led, HIGH); // turn the LED on (HIGH is the voltage level)
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  digitalWrite(led, LOW); // turn the LED off by making the voltage LOW
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
