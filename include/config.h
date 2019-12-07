#ifndef config_h
  #define config_h

  //definicion del hardware tanto pines y dimensiones

  #define ENABLE_SENSOR_LATERAL_DERECHO 18
  #define ENABLE_SENSOR_FRONTAL_DERECHA 13
  #define ENABLE_SENSOR_FRONTAL_IZQUIERDA 14
  #define ENABLE_SENSOR_DIAGONAL_DERECHA 19
  #define ENABLE_SENSOR_DIAGONAL_IZQUIERDA 27
  #define DELAY_ARRANQUE_SENSOR 500

  #define SENSOR_SDA 21 
  #define SENSOR_SCL 22
/*
  #define OLED_SDA 4    // For TTGo ESP32 LoRa-OLED
  #define OLED_SCL 15  // Hardware I2C does NOT work!  RMB
  #define OLED_RST 16
 */  
  #define BAUD_RATE 9600  // Serial baud rate

  #define LEFT_ENCODER_A_PIN 17  //este es el que genera la interrupción
  #define LEFT_ENCODER_B_PIN 16 
  #define RIGHT_ENCODER_A_PIN 2  //este es el que genera la interrupción
  #define RIGHT_ENCODER_B_PIN 4
  
  #define FRECUENCIA_PWM 31250  //frecuencia de los pwm del arduino nano
  #define RESOLUCION_N_BITS_PWM 8

  // #define LEFT_MOTOR_REV_PIN 26
  #define LEFT_MOTOR_FWD_PIN 25

  // #define RIGHT_MOTOR_REV_PIN 36
  #define RIGHT_MOTOR_FWD_PIN 12

  #define LEFT_MOTOR_REV_CH 0
  #define LEFT_MOTOR_FWD_CH 1
  #define RIGHT_MOTOR_REV_CH 2
  #define RIGHT_MOTOR_FWD_CH 3
  #define AXIS_DISTANCE 40.50  // En milimetros
  #define PULSES_TO_MM 0.073408  // es la relacion de pulsos del encoder y mm recorridos viene de: (PI * wheelDiameter) / (wheelRatio)

  // definici�n de valores a ajustar PID y velocidades
  #define TOP_SPEED 700// sacada de hacer rodar a los motores sin carga con 2 baterias en serie 700mm/s
  #define MIN_SPEED 100 // velocidad minima antes de que se paren los motores
  #define REC_SPEED 200 // velocidad de reconociento
  #define RACE_SPEED 600 //
  #define RETURN_SPEED 250 // 

  #define KP_POS_LINEAR 3.0
  #define KD_POS_LINEAR 1.0
  #define KI_POS_LINEAR 5.0
  #define KP_POS_ANGULAR 1.0
  #define KD_POS_ANGULAR 1.0
  #define KI_POS_ANGULAR 5.0

  #define KP_SPEED_LINEAR 2.0
  #define KD_SPEED_LINEAR 4.0
  #define KP_SPEED_ANGULAR 40.0
  #define KI_SPEED_ANGULAR 1.0
  #define KD_SPEED_ANGULAR 0.0

  #define RECONOCIMIENTO 0
  #define CARRERA 1
  #define VUELTA_A_CASA 2
  #define TESTEO 99
  #define JUANJO 253
  #define SERGIO 254
  #define VICTOR 255

  #define NORTE 0
  #define SUR 1
  #define ESTE 2
  #define OESTE 3

  #define DIMENSION_CELDA 180.0
#endif