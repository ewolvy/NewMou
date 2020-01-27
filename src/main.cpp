#include <Arduino.h>
#include <Wire.h>
#include "main.h"
#include "tests.h"
#include "config.h"
#include "Sensores.h"
#include "Encoder.h"
#include "Motores.h"
#include "BluetoothSerial.h"

BluetoothSerial BTSerial;
Sensores sensores;
Encoder *encoderLeft, *encoderRight;
Motores *motores;
PinesMotores pinesMotores;

void setup(){
  BTSerial.begin("Mousito01BT");
  // Serial.begin(BAUD_RATE);

  setupSensores();
  setupIMU();
  setupEncoders();
  setupMotores();
}

void loop(){

  // testSensores(&sensores, &BTSerial);
  // testBasicoMotores(&pinesMotores, &BTSerial);
  // testEncoders(encoderRight, encoderLeft, &BTSerial);
  // testPWMMotores(&pinesMotores, &BTSerial);
  testEncoders(encoderRight, encoderLeft, &BTSerial);
  // testAnalogInput(36, &BTSerial);
  // testIMU(ADDR_IMU, &BTSerial);
  // testAvanza1(ADDR_IMU, &sensores, encoderRight, encoderLeft, &pinesMotores, &BTSerial);
  
    
  delay(1000);
}

void setupSensores(){
  pinMode(ENABLE_SENSOR_FRONTAL_DERECHA, OUTPUT);
  pinMode(ENABLE_SENSOR_DIAGONAL_IZQUIERDA, OUTPUT);
  pinMode(ENABLE_SENSOR_DIAGONAL_DERECHA, OUTPUT);
  digitalWrite(ENABLE_SENSOR_FRONTAL_DERECHA, LOW);
  digitalWrite(ENABLE_SENSOR_DIAGONAL_IZQUIERDA, LOW);
  digitalWrite(ENABLE_SENSOR_DIAGONAL_DERECHA, LOW);

  Wire.begin();

  sensores.addSensor(TYPE_VL6180X, NAME_SENSOR_FRONTAL_IZQUIERDA,
                     ADDR_SENSOR_FRONTAL_IZQUIERDA, 0);
  sensores.addSensor(TYPE_VL6180X, NAME_SENSOR_FRONTAL_DERECHA,
                     ADDR_SENSOR_FRONTAL_DERECHA, ENABLE_SENSOR_FRONTAL_DERECHA);
  sensores.addSensor(TYPE_VL6180X, NAME_SENSOR_DIAGONAL_IZQUIERDA,
                     ADDR_SENSOR_DIAGONAL_IZQUIERDA, ENABLE_SENSOR_DIAGONAL_IZQUIERDA);
  sensores.addSensor(TYPE_VL6180X, NAME_SENSOR_DIAGONAL_DERECHA,
                     ADDR_SENSOR_DIAGONAL_DERECHA, ENABLE_SENSOR_DIAGONAL_DERECHA);
}

void setupIMU(){
  Wire.beginTransmission(0x68);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
}

void setupEncoders(){
  encoderLeft = new Encoder(LEFT_ENCODER_A_PIN, LEFT_ENCODER_B_PIN, &doEncoderLeft);
  encoderRight = new Encoder(RIGHT_ENCODER_A_PIN, RIGHT_ENCODER_B_PIN, &doEncoderRight);
}

void setupMotores(){
  pinesMotores.leftForward = LEFT_MOTOR_FWD_PIN;
  pinesMotores.leftReverse = LEFT_MOTOR_REV_PIN;
  pinesMotores.rightForward = RIGHT_MOTOR_FWD_PIN;
  pinesMotores.rightReverse = RIGHT_MOTOR_REV_PIN;

  pinesMotores.lfChannel = LEFT_MOTOR_FWD_CH;
  pinesMotores.lrChannel = LEFT_MOTOR_REV_CH;
  pinesMotores.rfChannel = RIGHT_MOTOR_FWD_CH;
  pinesMotores.rrChannel = RIGHT_MOTOR_REV_CH;

  pinMode(pinesMotores.leftForward, OUTPUT);
  pinMode(pinesMotores.leftReverse, OUTPUT);
  pinMode(pinesMotores.rightForward, OUTPUT);
  pinMode(pinesMotores.rightReverse, OUTPUT);

  digitalWrite(pinesMotores.leftForward, 0);
  digitalWrite(pinesMotores.leftReverse, 0);
  digitalWrite(pinesMotores.rightForward, 0);
  digitalWrite(pinesMotores.rightReverse, 0);
  
  ledcSetup(pinesMotores.lfChannel, 500, 8);
  ledcAttachPin(pinesMotores.leftForward, pinesMotores.lfChannel);
  ledcSetup(pinesMotores.lrChannel, 500, 8);
  ledcAttachPin(pinesMotores.leftReverse, pinesMotores.lrChannel);
  ledcSetup(pinesMotores.rfChannel, 500, 8);
  ledcAttachPin(pinesMotores.rightForward, pinesMotores.rfChannel);
  ledcSetup(pinesMotores.rrChannel, 500, 8);
  ledcAttachPin(pinesMotores.rightReverse, pinesMotores.rrChannel);

  motores = new Motores(TESTEO, pinesMotores, NULL, encoderLeft, encoderRight); 

}

void doEncoderLeft(){
  encoderLeft->signalReceived();
}

void doEncoderRight(){
  encoderRight->signalReceived();
}