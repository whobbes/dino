#ifndef COMPOSITEDATASINK_h
#define COMPOSITEDATASINK_h

#include "serialDataSink.h" 
#include "sigFoxDataSink.h" 

class CompositeDataSink: public IDataSink {
public:
  virtual bool sendData(const char* data, int size);
private:
  SerialDataSink _serialDataSink;
  SigFoxDataSink _sigfoxDataSink;
};

#endif
