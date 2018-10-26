#include "lightSigfoxSensor.h"
#include <Arduino.h>

LightSigfoxSensor::LightSigfoxSensor(): packet_open(false) {}

void LightSigfoxSensor::initialise(){
  
}

void LightSigfoxSensor::updatePacketOpenState(){
  int value = analogRead(A5);
  if (value > 350){
    packet_open = true;
    }
}

bool LightSigfoxSensor::getPacketOpen(){
  return packet_open;  
}
  
void LightSigfoxSensor::logMessage(SigfoxMessage& sigfoxMessage){
  sigfoxMessage.writeOpened(packet_open);
  packet_open = false;
}
