#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

void initMotors();
void setMotorSpeed(int speedLeft, int speedRight);
void stopMotors();

// Maniobras específicas
void salidaEstacionamiento();
void darVuelta();
void esquivarCono();
void ajusteTrayectoria();
void estacionamientoFinal();

#endif
