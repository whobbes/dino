#ifndef SERIALDATASINK_h
#define SERIALDATASINK_h


#include "dataSink.h" 

class SerialDataSink: public IDataSink {
public:
  virtual bool sendData(const char* data, int size);
};

#endif
