#include <Arduino.h>
#include "SerialCom.h"
#include "StateMachine.h"
//Segun la comunicacion que se hace con el Raspberry y la camara se esperan estos comandos
void updateSerial() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "START") changeState(SALIDA_ESTACIONAMIENTO);
    else if (cmd == "GO") changeState(DAR_VUELTA);
    else if (cmd == "AVOID") changeState(ESQUIVAR_CONO);
    else if (cmd == "ADJUST") changeState(AJUSTE_TRAYECTORIA);
    else if (cmd == "PARK") changeState(ESTACIONAMIENTO_FINAL);
    else if (cmd == "STOP") changeState(IDLE);
  }
}
