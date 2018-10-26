#include "humiditySigfoxSensor.h"
#include <Wire.h>
#define DHT_PIN   3

HumiditySigfoxSensor::HumiditySigfoxSensor():
  _dht(DHT_PIN, DHT22)
{}
  
void HumiditySigfoxSensor::initialise()
{
  _dht.begin();
}
  
void HumiditySigfoxSensor::logMessage(SigfoxMessage& sigfoxMessage)
{
  SigfoxMessage::Humidity humidity = static_cast<SigfoxMessage::Humidity>(_dht.readHumidity());
  sigfoxMessage.writeHumidity(humidity);

  SigfoxMessage::CentiCelsius temperature = static_cast<SigfoxMessage::CentiCelsius>(_dht.readTemperature() * 100);
  sigfoxMessage.writeTemperature(temperature);
}
