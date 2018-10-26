#ifndef SIGFOXDATASINK_h
#define SIGFOXDATASINK_h


#include "dataSink.h" 

class SigFoxDataSink: public IDataSink {
public:
  virtual bool sendData(const char* data, int size);
};

#endif
