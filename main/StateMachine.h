#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

enum CarState {
  IDLE,
  SALIDA_ESTACIONAMIENTO,
  DAR_VUELTA,
  ESQUIVAR_CONO,
  AJUSTE_TRAYECTORIA,
  ESTACIONAMIENTO_FINAL
};

extern CarState currentState;

void initStateMachine();
void updateStateMachine();
void changeState(CarState newState);

#endif
