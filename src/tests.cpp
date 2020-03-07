#include <Arduino.h>
#include <Wire.h>
#include <BluetoothSerial.h>
#include "tests.h"
#include "Motores.h"
#include "config.h"

void testBasicoMotores(PinesMotores *pinesMotores, BluetoothSerial *BTSerial ){
  // Poner ambos motores hacia alante
  BTSerial->println(pinesMotores->leftForward);
  BTSerial->println(pinesMotores->leftReverse);
  BTSerial->println(pinesMotores->rightForward);
  BTSerial->println(pinesMotores->rightReverse);
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
  Serial.print("Pared izquierda: ");
  Serial.println(sensores->hasLeftWall() ? "Sí" : "No");
  Serial.print("Pared derecha: ");
  Serial.println(sensores->hasRightWall() ? "Sí" : "No");
  Serial.print("Pared frontal: ");
  Serial.println(sensores->hasFrontWall() ? "Sí" : "No");
}

void testIMU(uint8_t MPU, BluetoothSerial *BTSerial ){
  int16_t AcX, AcY, AcZ, GyX, GyY, GyZ;
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12, true);  
  AcX=Wire.read()<<8|Wire.read();    
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read();  
  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read();  
  
  BTSerial->print("Accelerometer: ");
  BTSerial->print("X = "); BTSerial->print(AcX);
  BTSerial->print(" | Y = "); BTSerial->print(AcY);
  BTSerial->print(" | Z = "); BTSerial->println(AcZ); 
  
  BTSerial->print("Gyroscope: ");
  BTSerial->print("X = "); BTSerial->print(GyX);
  BTSerial->print(" | Y = "); BTSerial->print(GyY);
  BTSerial->print(" | Z = "); BTSerial->println(GyZ);
  BTSerial->println(" ");
}

void testEncoders(Encoder *encoderRight, Encoder *encoderLeft, BluetoothSerial *BTSerial ){
  BTSerial->print("Pulsos encoder derecho: ");
  BTSerial->println(encoderRight->getPulses());
  BTSerial->print("Pulsos encoder izquierdo: ");
  BTSerial->println(encoderLeft->getPulses());
}

void testPWMMotores(PinesMotores *pinesMotores, BluetoothSerial *BTSerial ){
  BTSerial->println("25 % PWM");
  ledcWrite(pinesMotores->lfChannel, 64);
  ledcWrite(pinesMotores->rfChannel, 64);
  delay(100);

  BTSerial->println("50 % PWM");
  ledcWrite(pinesMotores->lfChannel, 128);
  ledcWrite(pinesMotores->rfChannel, 128);
  delay(100);

  BTSerial->println("75 % PWM");
  ledcWrite(pinesMotores->lfChannel, 192);
  ledcWrite(pinesMotores->rfChannel, 192);
  delay(100);

  BTSerial->println("100 % PWM");
  ledcWrite(pinesMotores->lfChannel, 255);
  ledcWrite(pinesMotores->rfChannel, 255);
  delay(100);

  BTSerial->println("0 % PWM");
  ledcWrite(pinesMotores->lfChannel, 0);
  ledcWrite(pinesMotores->rfChannel, 0);
  delay(1000);  

  BTSerial->println("25 % PWM reverse");
  ledcWrite(pinesMotores->lrChannel, 64);
  ledcWrite(pinesMotores->rrChannel, 64);
  delay(100);

  BTSerial->println("50 % PWM reverse");
  ledcWrite(pinesMotores->lrChannel, 128);
  ledcWrite(pinesMotores->rrChannel, 128);
  delay(100);

  BTSerial->println("75 % PWM reverse");
  ledcWrite(pinesMotores->lrChannel, 192);
  ledcWrite(pinesMotores->rrChannel, 192);
  delay(100);

  BTSerial->println("100 % PWM reverse");
  ledcWrite(pinesMotores->lrChannel, 255);
  ledcWrite(pinesMotores->rrChannel, 255);
  delay(100);

  BTSerial->println("0 % PWM reverse");
  ledcWrite(pinesMotores->lrChannel, 0);
  ledcWrite(pinesMotores->rrChannel, 0);
  delay(1000);  
}

void testAnalogInput(uint8_t pin, BluetoothSerial *BTSerial ){
  BTSerial->println(analogRead(pin));
}

void testAvanza1(uint8_t MPU, Sensores *sensores, Encoder *encoderRight, Encoder *encoderLeft, PinesMotores *pinesMotores, BluetoothSerial *BTSerial ){
  BTSerial->println("avanza1");
}