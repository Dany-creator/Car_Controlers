#include "ServoControl.h"
#include <Servo.h>

Servo steering;

const int servoPin = 9;

void initServo() {
  steering.attach(servoPin);
  steering.write(90); // Centrado segun como ustedes ajusten el servo claro
}

void setSteeringAngle(int angle) {
  steering.write(angle);
}
