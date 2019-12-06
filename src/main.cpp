#include <Arduino.h>
#include "main.h"
#include "config.h"
#include "Sensores.h"
#include "Encoder.h"
#include "Motores.h"
// #include "BluetoothSerial.h"

// BluetoothSerial BTSerial;
Sensores sensores;
// Encoder *encoderLeft, *encoderRight;
// Motores *motores;
// PinesMotores pinesMotores;

void setup(){
  // BTSerial.begin("Mousito01BT");
  Serial.begin(BAUD_RATE);

  pinMode(ENABLE_SENSOR_FRONTAL_DERECHA, OUTPUT);
  pinMode(ENABLE_SENSOR_FRONTAL_IZQUIERDA, OUTPUT);
  digitalWrite(ENABLE_SENSOR_FRONTAL_DERECHA, LOW);
  digitalWrite(ENABLE_SENSOR_FRONTAL_IZQUIERDA, LOW);

  Wire.begin();

  sensores.addSensor(TYPE_VL6180X, "Lateral izquierdo", 0x50, 0);
  sensores.addSensor(TYPE_VL6180X, "Frontal derecho", 0x51, ENABLE_SENSOR_FRONTAL_DERECHA);
  sensores.addSensor(TYPE_VL6180X, "Frontal izquierdo", 0x52, ENABLE_SENSOR_FRONTAL_IZQUIERDA);
  // sensores.addSensor(TYPE_VL6180X, "Cuarto", 0x53, 0);

  // pinesMotores.leftForward = LEFT_MOTOR_FWD_PIN;
  // pinesMotores.leftReverse = LEFT_MOTOR_REV_PIN;
  // pinesMotores.rightForward = RIGHT_MOTOR_FWD_PIN;
  // pinesMotores.rightReverse = RIGHT_MOTOR_REV_PIN;

  // pinMode(pinesMotores.leftForward, OUTPUT);
  // pinMode(pinesMotores.leftReverse, OUTPUT);
  // pinMode(pinesMotores.rightForward, OUTPUT);
  // pinMode(pinesMotores.rightReverse, OUTPUT);

  // encoderLeft = new Encoder(LEFT_ENCODER_A_PIN, LEFT_ENCODER_B_PIN, &doEncoderLeft);
  // encoderRight = new Encoder(RIGHT_ENCODER_A_PIN, RIGHT_ENCODER_B_PIN, &doEncoderRight);

  // motores = new Motores(TESTEO, pinesMotores, NULL, encoderLeft, encoderRight);  
}

void loop(){

  testSensores();
  delay(1000);

  // testMotores();
  // testEncoders();
}

// void testEncoders(){
//   Serial.print("Pulsos encoder derecho: ");
//   Serial.println(encoderRight->getPulses());
//   Serial.print("Pulsos encoder izquierdo: ");
//   Serial.println(encoderLeft->getPulses());
// }

// void testMotores(){
//   motores->avanza(1);
// }

void testSensores(){
  if (sensores.getVL6180XSensor("Lateral izquierdo") != NULL){
    Serial.println(sensores.getDistance("Lateral izquierdo"));
  }
  if (sensores.getVL6180XSensor("Frontal derecho") != NULL){
    Serial.println(sensores.getDistance("Frontal derecho"));
  }
  if (sensores.getVL6180XSensor("Frontal izquierdo") != NULL){
    Serial.println(sensores.getDistance("Frontal izquierdo"));
  }
  // if (sensores.getVL6180XSensor("Cuarto") != NULL){
  //   Serial.println("Cuarta prueba OK");
  // }
  Serial.println();
}

// void doEncoderLeft(){
//   encoderLeft->signalReceived();
// }

// void doEncoderRight(){
//   encoderRight->signalReceived();
// }