#include "accelerometerSigfoxSensor.h"

#include <Wire.h> // For I2C comms

MMA8452Q AccelerometerSigfoxSensor::accel;
bool AccelerometerSigfoxSensor:: packet_dropped_flag = false;

void AccelerometerSigfoxSensor::logMessage(SigfoxMessage& sigfoxMessage)
{
  sigfoxMessage.writeFreefall(packet_dropped_flag);
  AccelerometerSigfoxSensor::packet_dropped_flag = false;
}

 
void AccelerometerSigfoxSensor::initialise(){

    // Accelerometer default to +/- 2G, 50Hz
  accel.init();
  accel.standby(); // need to be in this mode to change registers
  accel.writeRegister(FF_MT_CFG, 0xB8); // Freefall on X, Y and Z
  accel.writeRegister(FF_MT_THS, 0x03); // Threshold < 0.2g
  accel.writeRegister(FF_MT_COUNT, 0x02); // 2 count debounce i.e. 40ms@50Hz
  accel.writeRegister(CTRL_REG4, 0x04); // Enable Freefall interrupt
  accel.writeRegister(CTRL_REG5, 0x00); // INT2 pin select for interrupt
  accel.active(); // Resume data acquisition
}

void AccelerometerSigfoxSensor::freeFallDetectedISR()
{
  uint8_t reg = accel.readRegister(INT_SOURCE); // Checks where the interrupt comes from
  if ((reg & 0x04) == 0x04) { // If from Freefall interrupt
    accel.readRegister(FF_MT_SRC); // Clear accelerometer interrupt flag
    packet_dropped_flag = true; // Set freefall detected 
  }
}

void AccelerometerSigfoxSensor::setPacketDropped(bool packetDropped)
{
  packet_dropped_flag = packetDropped;
}

bool AccelerometerSigfoxSensor::packetDropped()
{
  return packet_dropped_flag;
}

