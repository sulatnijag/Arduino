#include <Stepper.h>

#define STEPS 2038 // the number of steps in one revolution of your motor (28BYJ-48)

Stepper stepper(STEPS, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps:
}

void loop() {
  Serial.println("Going to 2038");
  stepper.setSpeed(10); // 1 rpm
  stepper.step(2038); // do 2038 steps -- corresponds to one revolution in one minute
  Serial.println("Reached to 2038");
  //delay(5000); // wait for one second

  /*
  Serial.println("Going to -1000");
  //stepper.setSpeed(50); // 1 rpm
  stepper.step(-1000); // do 2038 steps -- corresponds to one revolution in one minute
  Serial.println("Reached to -1000");
  //delay(5000); // wait for one second
  */
  /*
  Serial.println("Going to 500");
  //stepper.setSpeed(50); // 1 rpm
  stepper.step(500); // do 2038 steps -- corresponds to one revolution in one minute
  Serial.println("Reached to 500");
  //delay(5000); // wait for one second
  

  */
  Serial.println("2038");
  //stepper.setSpeed(6); // 6 rpm
  stepper.step(-2038); // do 2038 steps in the other direction with faster speed -- corresponds to one revolution in 10 seconds
  
}
