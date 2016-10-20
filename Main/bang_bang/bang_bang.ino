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
int speed_R = 10;
int speed_L = speed_R;
int proportional_gain = 1;


////////// IR SETUP //////////
const int ir_R = A0;
const int ir_L = A1;
int val_R = 0;
int val_L = 0;

////////// TUNING PARAMETERS //////////
// there seems to be some discontinuity between the sensor
// readings, this compensation aligns them 
int comp = -15;
int sense_buffer = 5;

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
  val_R = analogRead(ir_R)-comp;
  val_L = analogRead(ir_L);

  // print IR values to serial
  Serial.print(val_R);
  Serial.print("\t");
  Serial.println(val_L);
  
  // find new values for speed
  // if sensor values are equal, go forward
  if (val_L == val_R){
    speed_L = 20;
    speed_R = 20;
    }
   //if right > left, go left
  else if (val_R > val_L + sense_buffer){
    speed_L = 10;
    speed_R = 50;
    }
  //if left > right, go right
  else if (val_L > val_R + sense_buffer){
    speed_L = 50;
    speed_R = 10;
  }

  // update motor speed
  myMotor_L->setSpeed(speed_L);
  myMotor_R->setSpeed(speed_R); 
  

}
