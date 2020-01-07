#ifndef tests_h
  #define tests_h
  #include "Motores.h"

  void testBasicoMotores(PinesMotores *pinesMotores);
  void testSensores(Sensores *sensores);
  void testEncoders(Encoder *encoderRight, Encoder *encoderLeft);
  void testPWMMotores(PinesMotores *pinesMotores);
#endif