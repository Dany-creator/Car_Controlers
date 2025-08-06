#include "MotorControl.h"
#include <Arduino.h>

// Pines ejemplo No se cual motor o controlador usan
const int motorLeftPWM = 5;
const int motorRightPWM = 6;
const int motorLeftDir = 7;
const int motorRightDir = 8;

void initMotors() {
  pinMode(motorLeftPWM, OUTPUT);
  pinMode(motorRightPWM, OUTPUT);
  pinMode(motorLeftDir, OUTPUT);
  pinMode(motorRightDir, OUTPUT);
}

void setMotorSpeed(int speedLeft, int speedRight) {
  digitalWrite(motorLeftDir, speedLeft >= 0 ? HIGH : LOW);
  digitalWrite(motorRightDir, speedRight >= 0 ? HIGH : LOW);
  analogWrite(motorLeftPWM, abs(speedLeft));
  analogWrite(motorRightPWM, abs(speedRight));
}

void stopMotors() {
  analogWrite(motorLeftPWM, 0);
  analogWrite(motorRightPWM, 0);
}

// Maniobras específicas en sus casos:
void salidaEstacionamiento() {
  // Establecer una secuencia para salir del estacionamiento
  setMotorSpeed(120, 120);
}

void darVuelta() {
  // En las esquinas
  setMotorSpeed(150, 150);
}

void esquivarCono() {
  // La Raspberry indica cuando se necesita hacer giro; aquí solo ejecutamos
  // reducir velocidad y girar
  setMotorSpeed(100, 80);
}

void ajusteTrayectoria() {
  // Correcciones muy suaves
  setMotorSpeed(110, 115);
}

void estacionamientoFinal() {
  // Secuencia inversa de la salida esto necesita ajustarse
  setMotorSpeed(-100, -100);
}
