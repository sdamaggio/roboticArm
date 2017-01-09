/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#define ELBOWSERVOPIN 2
#define WRISTSERVOPIN 3

Servo elbowServo;  // create servo object to control a servo
// max 78 straight elbow
// 114 90 degrees
// min 143 closed elbow 
Servo wristServo;
// 112 straight wrist alluminium touching the case
// 0 wrist closed up 

// twelve servo objects can be created on most boards

int pos = 90;    // variable to store the servo position
String message;

void setup() {
  Serial.begin(9600);
  elbowServo.attach(3);  // attaches the servo on pin 9 to the servo object
  message = "";
}

void loop() {
  delay(100);
  message = Serial.readString();
  delay(100);
  int newPos = message.toInt();
  if(newPos > 0 && newPos <= 360) {
    Serial.print("Servo position is: ");
    /*while(pos-newPos == 0) {
      elbowServo.write(pos);  
      delay(10);
      if(pos<=newPos)
        pos++;
      else 
        pos--;
    }*/
    pos = newPos;
    elbowServo.write(pos);  
    delay(500);
    newPos=0;
  }
  elbowServo.write(pos);  
  Serial.println(pos);  
}

