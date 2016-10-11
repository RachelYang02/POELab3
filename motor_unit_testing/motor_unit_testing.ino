// A4 = SDA
// A5 = SCL

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// request the DC motor from the motor shield
// may need to change (1) to whatever port # the motor is connected to
// M1 = 1, M2 = 2, M3 = 3, M4 = 4
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);

void setup() {
  // starts motor shield
  AFMS.begin();
  // sets default speed of the motor
  // ranges from 0 (stopped) to 255 (full speed)
  myMotor->setSpeed(100); 
}

void loop() {
  // run(direction)
  // direction can be FORWARD, BACKWARD, or RELEASE
  myMotor->run(FORWARD);
}
