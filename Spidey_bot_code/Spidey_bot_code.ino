#include <Servo.h>

// Note: Legs are decided from BACK view

// Front Right Leg
Servo fr_g,fr_m,fr_b;
// Front Left
Servo fl_g,fl_m,fl_b;
// Back Right 
Servo br_g,br_m,br_b;
// Back Left
Servo bl_g,bl_m,bl_b;
int pos=0;

void setup() {
  fr_b.attach(13); fr_m.attach(12); fr_g.attach(11);
  fl_b.attach(10); fl_m.attach(9); fl_g.attach(8);
  br_b.attach(7); br_m.attach(6); br_g.attach(5);
  bl_b.attach(4); bl_m.attach(3); bl_g.attach(2);

  Serial.begin(9600);
  Serial.println("Welcome to SPIDEY Controller: \n 1. Forward\n 2. Backward\n 3. Turn Left\n 4. Turn Right\n 5. StandUP");
  standUp();
}

void loop() {
  while(Serial.available()==0){
    
  }
  int choice = Serial.parseInt();
  switch(choice){
    case 1: forward();
    case 2: backward();
    case 3: turnLeft();
    case 4: turnRight();
    case 5: standUp();
    default: Serial.println("Invalid Input ...");
  }
  
}
void forward(){
  //for Front Left ARM,
  // Turn Up fl_g, then turn 
}
void backward(){

}
void turnLeft(){

}
void turnRight(){

}
void standUp(){
  int initial_zero=0;
  fr_b.write(0); fr_m.write(0); fr_g.write(0);
  fl_b.write(0); fl_m.write(0); fl_g.write(0);
  br_b.write(0); br_m.write(0); br_g.write(0);
  bl_b.write(0); bl_m.write(0); bl_g.write(0);

  // making Body motors in middle
  for (int pos = 0; pos <= 90; pos += 1) {
    fr_b.write(pos);
    fl_b.write(pos);
    br_b.write(pos);
    bl_b.write(pos);
    delay(15);
  }
  delay(500);
  // Making middle motors 135 
  for (int pos = 0; pos <= 135; pos += 1) {
    fr_m.write(pos);
    fl_m.write(pos);
    br_m.write(pos);
    bl_m.write(pos);
    delay(15);
  }
  delay(500);
  // Making Ground motors at 90
  for (int pos = 0; pos <= 90; pos += 1) {
    fr_g.write(pos);
    fl_g.write(pos);
    br_g.write(pos);
    bl_g.write(pos);
    delay(15);
  }
}

/*
for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  digitalWrite(led, LOW); // turn the LED off by making the voltage LOW
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
*/