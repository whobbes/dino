#include "serialDataSink.h" 
#include <ArduinoLowPower.h> // Low power
#include <Wire.h>

char digitToAscii(char digit) {
    if (digit <= 9)
    {
      return digit + '0';
    }
    else
    {
      return digit + 'A' - 10;
    }
}

void byteToAscii(char* dest, char data) {
   dest[1] = digitToAscii(data&0x0F);
   dest[0] = digitToAscii((data&0xF0) >> 4);
}

bool SerialDataSink::sendData(const char* data, int size){
  char serialOutput[25];
  int i=0;

  for (; i < ((size > 12) ? 12 : size); ++i)
  {
    byteToAscii(&serialOutput[i * 2], data[i]);
  }

  serialOutput[2*i] = 0;
  
  Serial.println(serialOutput);
  return true;
}

