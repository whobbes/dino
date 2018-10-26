#ifndef HUMIDITYSIGFOXSENSOR_h
#define HUMIDITYSIGFOXSENSOR_h

#include <DHT.h> // Humidity
#include "sigfoxSensor.h"
#include "sigfoxMessage.h"

class HumiditySigfoxSensor: public ISigfoxSensor
{
public:
  HumiditySigfoxSensor();
  void initialise();
  virtual void logMessage(SigfoxMessage& sigfoxMessage);
private:
  DHT _dht;
};

#endif
