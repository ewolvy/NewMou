#include <Arduino.h>
#include <Wire.h>
#include "main.h"
#include "tests.h"
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

  pinMode(ENABLE_SENSOR_FRONTAL_DERECHA, OUTPUT);
  pinMode(ENABLE_SENSOR_FRONTAL_IZQUIERDA, OUTPUT);
  pinMode(ENABLE_SENSOR_DIAGONAL_DERECHA, OUTPUT);
  digitalWrite(ENABLE_SENSOR_FRONTAL_DERECHA, LOW);
  digitalWrite(ENABLE_SENSOR_FRONTAL_IZQUIERDA, LOW);
  digitalWrite(ENABLE_SENSOR_DIAGONAL_DERECHA, LOW);

  Wire.begin();

  sensores.addSensor(TYPE_VL6180X, "Diagonal izquierdo", 0x50, 0);
  sensores.addSensor(TYPE_VL6180X, "Frontal derecho", 0x51, ENABLE_SENSOR_FRONTAL_DERECHA);
  sensores.addSensor(TYPE_VL6180X, "Frontal izquierdo", 0x52, ENABLE_SENSOR_FRONTAL_IZQUIERDA);
  sensores.addSensor(TYPE_VL6180X, "Diagonal derecho", 0x53, ENABLE_SENSOR_DIAGONAL_DERECHA);

  pinesMotores.leftForward = LEFT_MOTOR_FWD_PIN;
  pinesMotores.leftReverse = LEFT_MOTOR_REV_PIN;
  pinesMotores.rightForward = RIGHT_MOTOR_FWD_PIN;
  pinesMotores.rightReverse = RIGHT_MOTOR_REV_PIN;

  pinMode(pinesMotores.leftForward, OUTPUT);
  pinMode(pinesMotores.leftReverse, OUTPUT);
  pinMode(pinesMotores.rightForward, OUTPUT);
  pinMode(pinesMotores.rightReverse, OUTPUT);

  // encoderLeft = new Encoder(LEFT_ENCODER_A_PIN, LEFT_ENCODER_B_PIN, &doEncoderLeft);
  // encoderRight = new Encoder(RIGHT_ENCODER_A_PIN, RIGHT_ENCODER_B_PIN, &doEncoderRight);

  // motores = new Motores(TESTEO, pinesMotores, NULL, encoderLeft, encoderRight);  
}

void loop(){

  // testSensores(&sensores);

  testBasicoMotores(pinesMotores);

  // testEncoders(encoderRight, encoderLeft);


  delay(1000);
}

// void doEncoderLeft(){
//   encoderLeft->signalReceived();
// }

// void doEncoderRight(){
//   encoderRight->signalReceived();
// }