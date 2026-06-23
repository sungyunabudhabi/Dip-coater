#include <Stepper.h>

// Define number of steps
const int stepsPerRev = 2048;

// Initialize stepper motor
Stepper byj(stepsPerRev, 4, 6, 5, 7);

// Dispenses 0.42ml of fluid
void dispense() {
  int steps = 1.5*stepsPerRev;
  byj.step(-steps);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(100);
  byj.step(steps);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(100);
}

void setup() {
  // put your setup code here, to run once:
  byj.setSpeed(10);
  delay(1000);
  for (int i = 0; i < 10; i++)  {
    byj.step(stepsPerRev*8);
  }
  //dispense();
}

void loop() {
  // put your main code here, to run repeatedly:
}
