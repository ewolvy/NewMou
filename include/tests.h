#ifndef tests_h
  #define tests_h
  #include "Motores.h"
  #include <BluetoothSerial.h>

  void testBasicoMotores(PinesMotores *pinesMotores, BluetoothSerial *BTSerial );
  void testSensores(Sensores *sensores);
  void testIMU(uint8_t MPU, BluetoothSerial *BTSerial );
  void testEncoders(Encoder *encoderRight, Encoder *encoderLeft, BluetoothSerial *BTSerial );
  void testPWMMotores(PinesMotores *pinesMotores, BluetoothSerial *BTSerial );
  void testAnalogInput(uint8_t pin, BluetoothSerial *BTSerial );
  void testAvanza1(uint8_t MPU, Sensores *sensores, Encoder *encoderRight, Encoder *encoderLeft, PinesMotores *pinesMotores, BluetoothSerial *BTSerial );
#endif