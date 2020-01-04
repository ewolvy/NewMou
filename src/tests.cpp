#include <Arduino.h>
#include "tests.h"
#include "Motores.h"

void testBasicoMotores(PinesMotores pinesMotores){
  // Poner ambos motores hacia alante
  digitalWrite(pinesMotores.leftForward, 1);
  digitalWrite(pinesMotores.leftReverse, 0);
  digitalWrite(pinesMotores.rightForward, 1);
  digitalWrite(pinesMotores.rightReverse, 0);
  delay(1000);
  digitalWrite(pinesMotores.leftForward, 0);
  digitalWrite(pinesMotores.leftReverse, 0);
  digitalWrite(pinesMotores.rightForward, 0);
  digitalWrite(pinesMotores.rightReverse, 0);
  delay(1000);

  // Poner ambos motores hacia atrás
  digitalWrite(pinesMotores.leftForward, 0);
  digitalWrite(pinesMotores.leftReverse, 1);
  digitalWrite(pinesMotores.rightForward, 0);
  digitalWrite(pinesMotores.rightReverse, 1);
  delay(1000);
  digitalWrite(pinesMotores.leftForward, 0);
  digitalWrite(pinesMotores.leftReverse, 0);
  digitalWrite(pinesMotores.rightForward, 0);
  digitalWrite(pinesMotores.rightReverse, 0);
}

void testSensores(Sensores *sensores){
  if (sensores->getVL6180XSensor("Lateral izquierdo") != NULL){
    Serial.println(sensores->getDistance("Lateral izquierdo"));
  }
  if (sensores->getVL6180XSensor("Frontal derecho") != NULL){
    Serial.println(sensores->getDistance("Frontal derecho"));
  }
  if (sensores->getVL6180XSensor("Frontal izquierdo") != NULL){
    Serial.println(sensores->getDistance("Frontal izquierdo"));
  }
  if (sensores->getVL6180XSensor("Lateral derecho") != NULL){
    Serial.println(sensores->getDistance("Lateral derecho"));
  }
  Serial.println();
}

void testEncoders(Encoder *encoderRight, Encoder *encoderLeft){
  Serial.print("Pulsos encoder derecho: ");
  Serial.println(encoderRight->getPulses());
  Serial.print("Pulsos encoder izquierdo: ");
  Serial.println(encoderLeft->getPulses());
}
