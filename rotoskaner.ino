#include <Wire.h>
#include <Servo.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_StepperMotor *rawStepper = AFMS.getStepper(200, 1);

#include <AccelStepper.h>

Servo myServo;

void forwardstep() {
  rawStepper->onestep(FORWARD, MICROSTEP);
}
void backwardstep() {  
  rawStepper->onestep(BACKWARD, MICROSTEP);
}

AccelStepper stepper(forwardstep, backwardstep);

int pos;

void setup() {
  AFMS.begin();  // create with the default frequency 1.6KHz
//  myMotor->setSpeed(10);  // 10 rpm   
//  myServo.attach(10);
  pos = 0;
  stepper.setMaxSpeed(500);
  stepper.setAcceleration(100);
}

void loop() {
  //myMotor->onestep(FORWARD, MICROSTEP); 
  //myMotor->step(1, FORWARD, MICROSTEP); 

  if (stepper.distanceToGo() == 0) {
    pos += 16; // 16 microstepow == 1 stopien
    delay(1000);
    stepper.moveTo(pos);
  }
  stepper.run();

  /*

  delay(1000);   
  myServo.write(130); 
  delay(1000);   
  myServo.write(70); 
  */
  
//  myMotor->onestep(FORWARD, INTERLEAVE); 
//  delay(1000);
}

