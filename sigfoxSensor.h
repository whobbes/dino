#ifndef SIGFOXSENSOR_h
#define SIGFOXSENSOR_h

#include "sigfoxMessage.h"

class ISigfoxSensor {
public:
  virtual ~ISigfoxSensor() {}
  virtual void initialise() = 0;
  virtual void logMessage(SigfoxMessage& message) = 0;
};

#endif
