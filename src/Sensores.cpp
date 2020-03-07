#include "Sensores.h"
#include "config.h"
#include <SPI.h>
#include "VL6180X.h"

Sensores::Sensores(){
  initializeVL6180X(&sensores[SENSOR_FRONTAL_IZQUIERDA],
                    ADDR_SENSOR_FRONTAL_IZQUIERDA,
                    0);
  initializeVL6180X(&sensores[SENSOR_DIAGONAL_DERECHA],
                    ADDR_SENSOR_DIAGONAL_DERECHA,
                    ENABLE_SENSOR_DIAGONAL_DERECHA);
  initializeVL6180X(&sensores[SENSOR_DIAGONAL_IZQUIERDA],
                    ADDR_SENSOR_DIAGONAL_IZQUIERDA,
                    ENABLE_SENSOR_DIAGONAL_IZQUIERDA);
  initializeVL6180X(&sensores[SENSOR_FRONTAL_DERECHA],
                    ADDR_SENSOR_FRONTAL_DERECHA,
                    ENABLE_SENSOR_FRONTAL_DERECHA);
}

boolean Sensores::hasLeftWall(){
  return (getDistance(&sensores[SENSOR_DIAGONAL_IZQUIERDA]) < WALL_DIAGONAL_DISTANCE);
}

boolean Sensores::hasRightWall(){
  return (getDistance(&sensores[SENSOR_DIAGONAL_DERECHA]) < WALL_DIAGONAL_DISTANCE);
}

boolean Sensores::hasFrontWall(){
  return (getDistance(&sensores[SENSOR_FRONTAL_DERECHA]) < WALL_FRONT_DISTANCE &&
          getDistance(&sensores[SENSOR_FRONTAL_DERECHA]) < WALL_FRONT_DISTANCE);
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

uint16_t Sensores::getDistance(VL6180X *sensor){
  return sensor->readRangeSingleMillimeters();
}