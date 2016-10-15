#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Adafruit_PWMServoDriver.h>


////////// MOTOR SETUP //////////
// NOTE: pins A4 and A5 are unavailable
// A4 = SDA and A5 = SCL

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// request the DC motor from the motor shield
Adafruit_DCMotor *myMotor_L = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor_R = AFMS.getMotor(4);

// Initialize speeds
int speed_R = 100;
int speed_L = speed_R;


////////// IR SETUP //////////
const int ir_R = A0;
const int ir_L = A1;
int val_R = 0;
int val_L = 0;
// there seems to be some discontinuity between the sensor
// readings, this compensation aligns them 
int comp = -20;

void setup() {
  Serial.begin(9600);
  // starts motor shield
  AFMS.begin();
  // sets default speed of the motor
  // ranges from 0 (stopped) to 255 (full speed)
  myMotor_R->setSpeed(speed_R);
  myMotor_L->setSpeed(speed_L); 
  // Due to wiring issues, "BACKWARD" = "FORWARD" for us
  myMotor_R->run(BACKWARD);
  myMotor_L->run(BACKWARD);
}


void loop() {
  // read from IR sensors
  val_R = analogRead(ir_R) - comp;
  val_L = analogRead(ir_L);

  // print to serial
  Serial.print(val_R);
  Serial.print("\t");
  Serial.println(val_L);
  
  // find new values for speeds
  speed_R = 0;
  speed_L = 0;

  // update motor speed
  myMotor_L->setSpeed(speed_L);
  myMotor_R->setSpeed(speed_R); 
  

}
