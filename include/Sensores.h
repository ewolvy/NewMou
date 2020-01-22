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
  #define MAX_SENSORES 5   // Número máximo de sensores de cada tipo

  #include "VL6180X.h"
  
  // Definiciones para los tipos de sensores
  #define TYPE_NONE 0
  #define TYPE_VL6180X 1
  #define DELAY_ARRANQUE_SENSOR 500

  class Sensores{
    public:
      boolean addSensor(const uint8_t type, const char *name, const uint8_t address, const uint8_t pin);
      VL6180X *getVL6180XSensor(const char name[]);
      uint16_t getDistance(const char name[]);
    private:
      void initializeVL6180X(VL6180X *sensor, const uint8_t address, const uint8_t pin);
      uint8_t getType(const char name[]);
      VL6180X vl6180x[MAX_SENSORES];
      uint8_t vl6180x_count = 0;
      char vl6180x_names[10][20];
  };
#endif