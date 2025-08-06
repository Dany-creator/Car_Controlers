#include "StateMachine.h"
#include "MotorControl.h"
#include "ServoControl.h"
#include "SerialCom.h"

void setup() {
  Serial.begin(115200);
  initMotors();
  initServo();
  initStateMachine();
}

void loop() {
  updateSerial();          // Lee comandos desde Raspberry
  updateStateMachine();    // Ejecuta el estado actual
}
