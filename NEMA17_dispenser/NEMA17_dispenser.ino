#include <TMC2209.h>

TMC2209 nema;

const uint32_t MICROSTEPS = 16;
const int32_t RUN_VELOCITY = 2237;        //about 30RPM 
const float MICROSTEPS_PER_SEC = 1600;    //RUN_VELOCITY*12,000,000 / 2^24
const float ROTATIONS = 1.5;              //VOLUME = 0.2808 * ROTATIONS (ml)

const int EN_PIN = ;

unsigned long startTime = 0;
long requiredTime = (200 * MICROSTEPS / MICROSTEPS_PER_SEC) * ROTATIONS * 1000;
bool isMoving = false;

void dispense() {
  nema.enable();
  delay(1000);
  startTime = millis();
  nema.disableInverseMotorDirection();
  nema.moveAtVelocity(RUN_VELOCITY);
  while (millis() - startTime <= requiredTime) {
    }
  nema.moveAtVelocity(0);
  delay(1000);

  startTime = millis();
  nema.enableInverseMotorDirection();
  nema.moveAtVelocity(RUN_VELOCITY);
  while (millis() - startTime <= requiredTime){
  }
  nema.moveAtVelocity(0);
  nema.disable();
}

void setup() {
  // put your setup code here, to run once:
  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);
  // Start the hardware serial port at the driver's default speed
  Serial3.begin(115200); 
  
  // Point the library to your hardware serial port
  nema.setup(Serial3);

  nema.setRunCurrent(80);
  nema.setMicrostepsPerStep(16);

  dispense();
}

void loop() {
  // put your main code here, to run repeatedly:

}
