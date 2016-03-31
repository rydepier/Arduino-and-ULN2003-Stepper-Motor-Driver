/**********************************************************/
// ULN2003 Motor Driver
//
// A simple implimetation that allows the number of steps
// the speed and the direction of rotation to be set
//
//
/**********************************************************/

#include <StepperMotor.h>
// motor driver connections
// IN1, IN2, IN3, IN4
StepperMotor motor(8,9,10,11);
int motorSpeed = 1; // motor gets slower as this number increases
int motorSteps = 4076; // 4076 is approx 360 degrees
// maximum speed about 15RPM at 5 volts with an Arduino
int motorDelay = 1000; // delay in ms before motor reverses
#define led 13 // onboard led
/**********************************************************/

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW); // turn off LED
  motor.setStepDuration(motorSpeed);
}
/**********************************************************/
void loop(){
  // approx 4076 steps for a full rotation
  // gear ratio is  63.68395:1
  // internal motor has 64 steps per revolution
  //
  // motor forwards
  digitalWrite(led, HIGH); // shows forward rotation
  motor.step(motorSteps); 
  delay(motorDelay);
  // reverse motor
  digitalWrite(led, LOW); // shows reverse rotation
  motor.step(-motorSteps);
  delay(motorDelay);
}
/**********************************************************/
