#ifndef SIGFOXMESSAGE_h
#define SIGFOXMESSAGE_h

class SigfoxMessage
{
public:
  typedef float Longitude;
  typedef float Latitude;
  typedef unsigned short CentiCelsius; //10^(-2) i.e. x.xx 
  typedef unsigned char Humidity;
  
  void writeLongitude(Longitude longitude);
  void writeLatitude(Latitude latitude);
  void writeTemperature(CentiCelsius temperature);
  void writeHumidity(Humidity humidity);
  void writeFreefall(bool freefall);
  void writeOpened(bool opened);

  const char* message() const;

  void reset();
private:
  char _message[12];  
};

#endif
