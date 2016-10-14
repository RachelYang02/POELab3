// A4 = SDA
// A5 = SCL

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// request the DC motor from the motor shield
// may need to change (1) to whatever port # the motor is connected to
// M1 = 1, M2 = 2, M3 = 3, M4 = 4
Adafruit_DCMotor *myMotor_L = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor_R = AFMS.getMotor(4);

void setup() {
  // starts motor shield
  AFMS.begin();
}

void loop() {
  // sets default speed of the motor
  // ranges from 0 (stopped) to 255 (full speed)
  myMotor_L->setSpeed(100);
  myMotor_R->setSpeed(100); 

  // run(direction)
  // direction can be FORWARD, BACKWARD, or RELEASE
  // as of right now, seems to be that FORWARD is actually, in our perspective, a backwards motion. Keep in mind.
  myMotor_L->run(FORWARD);
  myMotor_R->run(FORWARD);

}
