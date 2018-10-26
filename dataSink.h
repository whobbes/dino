#ifndef DATASINK_h
#define DATASINK_h

class IDataSink {
public:
  virtual ~IDataSink() {}
  
  virtual bool sendData(const char* data, int size) = 0;
};

#endif
