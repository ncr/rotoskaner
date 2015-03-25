#include <Wire.h>
#include <Servo.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_StepperMotor *rawStepper = AFMS.getStepper(200, 1);

#include <AccelStepper.h>

Servo myServo;

void forwardstep() {
  rawStepper->onestep(FORWARD, INTERLEAVE);
}
void backwardstep() {  
  rawStepper->onestep(BACKWARD, INTERLEAVE);
}

AccelStepper stepper(forwardstep, backwardstep);

void setup() {
  AFMS.begin();  // create with the default frequency 1.6KHz
//  myMotor->setSpeed(10);  // 10 rpm   
//  myServo.attach(10);
}

void loop() {
  //myMotor->onestep(FORWARD, MICROSTEP); 
  //myMotor->step(1, FORWARD, MICROSTEP); 

    if (stepper.distanceToGo() == 0)
    {
	// Random change to speed, position and acceleration
	// Make sure we dont get 0 speed or accelerations
	delay(1000);
	stepper.moveTo(rand() % 200);
	stepper.setMaxSpeed((rand() % 100) + 100);
	stepper.setAcceleration((rand() % 200) + 1);
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

