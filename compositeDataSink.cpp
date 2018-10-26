#include "compositeDataSink.h" 

bool CompositeDataSink::sendData(const char* data, int size)
{
  _serialDataSink.sendData(data, size);
  _sigfoxDataSink.sendData(data, size);
}
