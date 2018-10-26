#ifndef LIGHTSIGFOXSENSOR_h
#define LIGHTSIGFOXSENSOR_h

#include "sigfoxSensor.h"
#include "sigfoxMessage.h"

class LightSigfoxSensor: public ISigfoxSensor
{
public:
  LightSigfoxSensor();
  void updatePacketOpenState();
  bool getPacketOpen();
  void initialise();
  virtual void logMessage(SigfoxMessage& sigfoxMessage);
private:
  bool packet_open;
};

#endif
