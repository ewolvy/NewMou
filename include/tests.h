#ifndef tests_h
  #define tests_h
  #include "Motores.h"

  void testBasicoMotores(PinesMotores *pinesMotores);
  void testSensores(Sensores *sensores);
  void testIMU(uint8_t MPU);
  void testEncoders(Encoder *encoderRight, Encoder *encoderLeft);
  void testPWMMotores(PinesMotores *pinesMotores);
  void testAnalogInput(uint8_t pin);
#endif