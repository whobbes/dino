#include "sigfoxMessage.h"
#include <cstring>

void SigfoxMessage::writeLongitude(Longitude longitude)
{
  memcpy(&_message[0], &longitude, sizeof(longitude));
}
  
void SigfoxMessage::writeLatitude(Latitude latitude)
{
  memcpy(&_message[4], &latitude, sizeof(latitude));
}
  
void SigfoxMessage::writeTemperature(CentiCelsius temperature)
{
  memcpy(&_message[8], &temperature, sizeof(temperature));
}
  
void SigfoxMessage::writeHumidity(Humidity humidity)
{
  memcpy(&_message[10], &humidity, sizeof(humidity));
}

void SigfoxMessage::writeFreefall(bool freefall)
{
  char value = _message[11] & 0xFE;
  value |= (freefall ? 0x01 : 0x00);
   memcpy(&_message[11], &value, sizeof(value));
}

void SigfoxMessage::writeOpened(bool opened)
{
   char value = _message[11] & 0xFD;
  value |= (opened ? 0x02 : 0x00);
   memcpy(&_message[11], &value, sizeof(value));
}


const char* SigfoxMessage::message() const
{
  return _message;
}

void SigfoxMessage::reset()
{
  memset(_message, 0, sizeof(_message));
}

