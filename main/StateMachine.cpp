#include "StateMachine.h"
#include "MotorControl.h"
#include "ServoControl.h"
#include "SerialCom.h"

CarState currentState;

void initStateMachine() {
  currentState = IDLE;
}

void changeState(CarState newState) {
  currentState = newState;
}

void updateStateMachine() {
  switch(currentState) {
    case IDLE:
      stopMotors();
      break;
    case SALIDA_ESTACIONAMIENTO:
      salidaEstacionamiento();
      break;
    case DAR_VUELTA:
      darVuelta();
      break;
    case ESQUIVAR_CONO:
      esquivarCono();
      break;
    case AJUSTE_TRAYECTORIA:
      ajusteTrayectoria();
      break;
    case ESTACIONAMIENTO_FINAL:
      estacionamientoFinal();
      break;
  }
}
