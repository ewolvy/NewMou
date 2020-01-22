#include "Sensores.h"
#include <SPI.h>
#include "VL6180X.h"


boolean Sensores::addSensor(const uint8_t type, const char name[], const uint8_t address, const uint8_t pin){
  switch(type){

    case TYPE_VL6180X:
      if (vl6180x_count == MAX_SENSORES - 1) return false;
      vl6180x[vl6180x_count] = VL6180X();
      strcpy(vl6180x_names[vl6180x_count], name);
      initializeVL6180X(&vl6180x[vl6180x_count], address, pin);
      vl6180x_count++;
      break;
  }
  return true;
}

VL6180X *Sensores::getVL6180XSensor(const char name[]){
  uint8_t position = 0;
  while (position < vl6180x_count){
    if (strcmp(vl6180x_names[position], name) == 0){
      return &vl6180x[position];
    }
    position++;
  }
  return NULL;
}


void Sensores::initializeVL6180X(VL6180X *sensor, const uint8_t address, const uint8_t pin){
  if (pin != 0){
    digitalWrite(pin, HIGH);
    delay(DELAY_ARRANQUE_SENSOR);
  }
  sensor->init();
  sensor->configureDefault();
  sensor->setAddress(address);
  sensor->setTimeout(500);
  delay(DELAY_ARRANQUE_SENSOR);
}

uint16_t Sensores::getDistance(const char name[]){
  VL6180X *sensor618;
  switch(getType(name)){
    case TYPE_VL6180X:
      sensor618 = getVL6180XSensor(name);
      return sensor618->readRangeSingleMillimeters();
      break;
  }
  return 0;
}

uint8_t Sensores::getType(const char name[]){
  uint8_t position = 0;
  
  for (position = 0; position < vl6180x_count; position++){
    if (strcmp(vl6180x_names[position], name) == 0) return TYPE_VL6180X;
  }
  return TYPE_NONE;
}