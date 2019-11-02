#include <Arduino.h>
#include "main.h"
#include "config.h"
#include "Sensores.h"
#include "Encoder.h"
#include "Motores.h"
// #include "BluetoothSerial.h"

// BluetoothSerial BTSerial;
Sensores sensores;
Encoder *encoderLeft, *encoderRight;
Motores *motores;
PinesMotores pinesMotores;

void setup(){
  // BTSerial.begin("Mousito01BT");
  Serial.begin(BAUD_RATE);
/* 
  sensores.addSensor(TYPE_VL53L0X, "Primero", 0, 0);
  sensores.addSensor(TYPE_VL53L0X, "Segundo", 0, 0);
  sensores.addSensor(TYPE_VL6180X, "Tercero", 0, 0);
  sensores.addSensor(TYPE_VL6180X, "Cuarto", 0, 0);
  sensores.addSensor(TYPE_VL6180X, "Quinto", 0, 0);
 */
  pinesMotores.leftForward = LEFT_MOTOR_FWD_PIN;
  pinesMotores.leftReverse = LEFT_MOTOR_REV_PIN;
  pinesMotores.rightForward = RIGHT_MOTOR_FWD_PIN;
  pinesMotores.rightReverse = RIGHT_MOTOR_REV_PIN;

  pinMode(pinesMotores.leftForward, OUTPUT);
  pinMode(pinesMotores.leftReverse, OUTPUT);
  pinMode(pinesMotores.rightForward, OUTPUT);
  pinMode(pinesMotores.rightReverse, OUTPUT);

  encoderLeft = new Encoder(LEFT_ENCODER_A_PIN, LEFT_ENCODER_B_PIN, &doEncoderLeft);
  encoderRight = new Encoder(RIGHT_ENCODER_A_PIN, RIGHT_ENCODER_B_PIN, &doEncoderRight);

  motores = new Motores(TESTEO, pinesMotores, NULL, encoderLeft, encoderRight);  
}

void loop(){
  // testMotores();
  // testEncoders();
  digitalWrite(LEFT_MOTOR_FWD_PIN, 0);
  digitalWrite(LEFT_MOTOR_REV_PIN, 0);
  digitalWrite(RIGHT_MOTOR_FWD_PIN, 0);
  digitalWrite(RIGHT_MOTOR_REV_PIN, 0);
  delay(2000);
  digitalWrite(LEFT_MOTOR_FWD_PIN, 1);
  digitalWrite(LEFT_MOTOR_REV_PIN, 0);
  digitalWrite(RIGHT_MOTOR_FWD_PIN, 1);
  digitalWrite(RIGHT_MOTOR_REV_PIN, 0);
  delay(1000);
  digitalWrite(LEFT_MOTOR_FWD_PIN, 0);
  digitalWrite(LEFT_MOTOR_REV_PIN, 0);
  digitalWrite(RIGHT_MOTOR_FWD_PIN, 0);
  digitalWrite(RIGHT_MOTOR_REV_PIN, 0);
  delay(1000);
  digitalWrite(LEFT_MOTOR_FWD_PIN, 0);
  digitalWrite(LEFT_MOTOR_REV_PIN, 1);
  digitalWrite(RIGHT_MOTOR_FWD_PIN, 0);
  digitalWrite(RIGHT_MOTOR_REV_PIN, 1);
  delay(1000);
}

void testEncoders(){
  Serial.print("Pulsos encoder derecho: ");
  Serial.println(encoderRight->getPulses());
  Serial.print("Pulsos encoder izquierdo: ");
  Serial.println(encoderLeft->getPulses());
}

void testMotores(){
  motores->avanza(1);
}

void testSensores(){
  if (sensores.getVL53L0XSensor("Primero") != NULL){
    Serial.println("Primera prueba OK");
  }
  if (sensores.getVL53L0XSensor("Tercero") == NULL){
    Serial.println("Segunda prueba OK");
  }
  if (sensores.getVL6180XSensor("Tercero") != NULL){
    Serial.println("Tercera prueba OK");
  }
}

void doEncoderLeft(){
  encoderLeft->signalReceived();
}

void doEncoderRight(){
  encoderRight->signalReceived();
}