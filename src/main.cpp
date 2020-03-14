#include <Arduino.h>
#include <Wire.h>
#include "main.h"
#include "tests.h"
#include "config.h"
#include "Sensores.h"
#include "Encoder.h"
#include "Motores.h"
#include "BluetoothSerial.h"

BluetoothSerial myBTSerial;
Sensores *mySensores;
Encoder *myEncoderLeft, *myEncoderRight;
Motores *myMotores;
PinesMotores myPinesMotores;

void setup(){
  myBTSerial.begin("Mousito01BT");
  Serial.begin(BAUD_RATE);

  setupSensores();
  setupIMU();
  setupEncoders();
  setupMotores();
}

void loop(){

  // testSensores(mySensores);
  // testBasicoMotores(&myPinesMotores, &myBTSerial);
  // testEncoders(myEncoderRight, myEncoderLeft, &myBTSerial);
  // testPWMMotores(&myPinesMotores, &myBTSerial);
  // testEncoders(myEncoderRight, myEncoderLeft, &myBTSerial);
  // testAnalogInput(36, &myBTSerial);
  // testIMU(ADDR_IMU, &myBTSerial);
  // testAvanza1(ADDR_IMU, &mySensores, myEncoderRight, myEncoderLeft, &myPinesMotores, &myBTSerial);
  //  myMotores->avanza(1);
  //  myMotores->fullStop();
  testEEPROM();

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

  mySensores = new Sensores();
}

void setupIMU(){
  Wire.beginTransmission(0x68);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
}

void setupEncoders(){
  myEncoderLeft = new Encoder(LEFT_ENCODER_A_PIN, LEFT_ENCODER_B_PIN, &doEncoderLeft);
  myEncoderRight = new Encoder(RIGHT_ENCODER_A_PIN, RIGHT_ENCODER_B_PIN, &doEncoderRight);
}

void setupMotores(){
  myPinesMotores.leftForward = LEFT_MOTOR_FWD_PIN;
  myPinesMotores.leftReverse = LEFT_MOTOR_REV_PIN;
  myPinesMotores.rightForward = RIGHT_MOTOR_FWD_PIN;
  myPinesMotores.rightReverse = RIGHT_MOTOR_REV_PIN;

  myPinesMotores.lfChannel = LEFT_MOTOR_FWD_CH;
  myPinesMotores.lrChannel = LEFT_MOTOR_REV_CH;
  myPinesMotores.rfChannel = RIGHT_MOTOR_FWD_CH;
  myPinesMotores.rrChannel = RIGHT_MOTOR_REV_CH;

  pinMode(myPinesMotores.leftForward, OUTPUT);
  pinMode(myPinesMotores.leftReverse, OUTPUT);
  pinMode(myPinesMotores.rightForward, OUTPUT);
  pinMode(myPinesMotores.rightReverse, OUTPUT);

  digitalWrite(myPinesMotores.leftForward, 0);
  digitalWrite(myPinesMotores.leftReverse, 0);
  digitalWrite(myPinesMotores.rightForward, 0);
  digitalWrite(myPinesMotores.rightReverse, 0);
  
  ledcSetup(myPinesMotores.lfChannel, 500, 8);
  ledcAttachPin(myPinesMotores.leftForward, myPinesMotores.lfChannel);
  ledcSetup(myPinesMotores.lrChannel, 500, 8);
  ledcAttachPin(myPinesMotores.leftReverse, myPinesMotores.lrChannel);
  ledcSetup(myPinesMotores.rfChannel, 500, 8);
  ledcAttachPin(myPinesMotores.rightForward, myPinesMotores.rfChannel);
  ledcSetup(myPinesMotores.rrChannel, 500, 8);
  ledcAttachPin(myPinesMotores.rightReverse, myPinesMotores.rrChannel);

  myMotores = new Motores(VICTOR, myPinesMotores, NULL, myEncoderLeft, myEncoderRight); 

}

void doEncoderLeft(){
  myEncoderLeft->signalReceived();
}

void doEncoderRight(){
  myEncoderRight->signalReceived();
}