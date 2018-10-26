#include "sigFoxDataSink.h" 
#include <SigFox.h> // Radio

bool SigFoxDataSink::sendData(const char* data, int size){
  SigFox.begin();

  SigFox.beginPacket();
  SigFox.write(data, ((size > 12) ? 12 : size));
  int ret = SigFox.endPacket();
  SigFox.end();
  return ret == 1;
}

