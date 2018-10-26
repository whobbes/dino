#ifndef ACCELEROMETERSIGFOXSENSOR_h
#define ACCELEROMETERSIGFOXSENSOR_h

#include "MMA8452Q.h" // Accelerometer
#include "sigfoxSensor.h"
#include "sigfoxMessage.h"

class AccelerometerSigfoxSensor: public ISigfoxSensor
{
public:
  void initialise();
  virtual void logMessage(SigfoxMessage& sigfoxMessage);

  static void freeFallDetectedISR();
  static bool packetDropped();
  static void setPacketDropped(bool packetDropped);
private:
  static MMA8452Q accel; // Accelerometer object
  static bool packet_dropped_flag;
};

#endif
