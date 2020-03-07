/*
Clase para ayudar a utilizar los sensores usados en el micromouse. Actualmente soporta:
  - VL6180X
Para poder inicializar varios sensores que tienen la misma dirección se debe
proporcionar la dirección a la que se quiere cambiar al crearlo.

Ejemplo de uso:
  sensores.addSensor(TYPE_VL6180X, "Lateral izquierda", 0x51, 23);
       Parámetros: Tipo de sensor, nombre asignado,  dirección, pin para inicializar

Una vez inicializado se puede solicitar la lectura con el método getDistance("nombre")
*/
#ifndef sensores_h
  #define sensores_h

  #include "VL6180X.h"
  
  // Definiciones de la clase
  #define DELAY_ARRANQUE_SENSOR 500
  #define WALL_FRONT_DISTANCE 200.0
  #define WALL_DIAGONAL_DISTANCE 120.0
  #define TOTAL_SENSORES 4
  #define SENSOR_DIAGONAL_DERECHA 0
  #define SENSOR_DIAGONAL_IZQUIERDA 1
  #define SENSOR_FRONTAL_DERECHA 2
  #define SENSOR_FRONTAL_IZQUIERDA 3

  class Sensores{
    public:
      Sensores();
      boolean hasLeftWall();
      boolean hasRightWall();
      boolean hasFrontWall();
      uint16_t getDistance(VL6180X *sensor);
    private:
      void initializeVL6180X(VL6180X *sensor, const uint8_t address, const uint8_t pin);
      uint8_t getType(const char name[]);
      VL6180X sensores[TOTAL_SENSORES];
  };
#endif