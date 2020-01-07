#include <Arduino.h>
#include "tests.h"
#include "Motores.h"

void testBasicoMotores(PinesMotores *pinesMotores){
  // Poner ambos motores hacia alante
  Serial.println(pinesMotores->leftForward);
  Serial.println(pinesMotores->leftReverse);
  Serial.println(pinesMotores->rightForward);
  Serial.println(pinesMotores->rightReverse);
  digitalWrite(pinesMotores->leftForward, 1);
  digitalWrite(pinesMotores->leftReverse, 0);
  digitalWrite(pinesMotores->rightForward, 1);
  digitalWrite(pinesMotores->rightReverse, 0);
  delay(1000);
  digitalWrite(pinesMotores->leftForward, 0);
  digitalWrite(pinesMotores->leftReverse, 0);
  digitalWrite(pinesMotores->rightForward, 0);
  digitalWrite(pinesMotores->rightReverse, 0);
  delay(1000);

  // Poner ambos motores hacia atrás
  digitalWrite(pinesMotores->leftForward, 0);
  digitalWrite(pinesMotores->leftReverse, 1);
  digitalWrite(pinesMotores->rightForward, 0);
  digitalWrite(pinesMotores->rightReverse, 1);
  delay(1000);
  digitalWrite(pinesMotores->leftForward, 0);
  digitalWrite(pinesMotores->leftReverse, 0);
  digitalWrite(pinesMotores->rightForward, 0);
  digitalWrite(pinesMotores->rightReverse, 0);
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

void testPWMMotores(PinesMotores *pinesMotores){
  Serial.println("25 % PWM");
  ledcWrite(pinesMotores->lfChannel, 64);
  ledcWrite(pinesMotores->rfChannel, 64);
  delay(1000);

  Serial.println("50 % PWM");
  ledcWrite(pinesMotores->lfChannel, 128);
  ledcWrite(pinesMotores->rfChannel, 128);
  delay(1000);

  Serial.println("75 % PWM");
  ledcWrite(pinesMotores->lfChannel, 192);
  ledcWrite(pinesMotores->rfChannel, 192);
  delay(1000);

  Serial.println("100 % PWM");
  ledcWrite(pinesMotores->lfChannel, 255);
  ledcWrite(pinesMotores->rfChannel, 255);
  delay(1000);

  Serial.println("0 % PWM");
  ledcWrite(pinesMotores->lfChannel, 0);
  ledcWrite(pinesMotores->rfChannel, 0);
  delay(1000);  

  Serial.println("25 % PWM reverse");
  ledcWrite(pinesMotores->lrChannel, 64);
  ledcWrite(pinesMotores->rrChannel, 64);
  delay(1000);

  Serial.println("50 % PWM reverse");
  ledcWrite(pinesMotores->lrChannel, 128);
  ledcWrite(pinesMotores->rrChannel, 128);
  delay(1000);

  Serial.println("75 % PWM reverse");
  ledcWrite(pinesMotores->lrChannel, 192);
  ledcWrite(pinesMotores->rrChannel, 192);
  delay(1000);

  Serial.println("100 % PWM reverse");
  ledcWrite(pinesMotores->lrChannel, 255);
  ledcWrite(pinesMotores->rrChannel, 255);
  delay(1000);

  Serial.println("0 % PWM reverse");
  ledcWrite(pinesMotores->lrChannel, 0);
  ledcWrite(pinesMotores->rrChannel, 0);
  delay(1000);  
}
