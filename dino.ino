/*
* dino.ino
* DINO project aims to demonstrate usage of SigFox.
* A package is equipped with Sigfox enabled MCU.
* When it is opened or dropped a messsage is sent to SigFox backend.
*/

// Includes
#include <Arduino.h>
#include <SigFox.h>
#include <ArduinoLowPower.h>
#include <Wire.h>
#include "accelerometerSigfoxSensor.h"
#include "compositeDataSink.h" 
#include "sigfoxMessage.h"
#include "humiditySigfoxSensor.h"
#include "lightSigfoxSensor.h"

// Global settings
#define DEBUG // Debug ON
#define REPORT_FREQUENCY_MILLIS 60000 // Send message every 60s
#define LIGHT_SENSOR_POLL_MILLIS 5000 // Send message every 60s

// Prototypes
void freeFallDetectedISR();

// Only print messages when debug is ON
#ifdef DEBUG
# define LOG(x) Serial.println(x)
#else
# define LOG(x) do {} while (0)
#endif

CompositeDataSink dataSink;
AccelerometerSigfoxSensor accelerometer;
HumiditySigfoxSensor humidity;
LightSigfoxSensor light;
SigfoxMessage sigfoxMessage;


// Run once
void setup() {

    // Debug serial port start
    Serial.begin(9600);
    digitalWrite(LED_BUILTIN, HIGH);
    LOG("Setup start");
    delay(1000); // if not Serial not ready, slow!
    digitalWrite(LED_BUILTIN, LOW);
    while (!Serial) {};
  
    // Starting SigFox module
    if (!SigFox.begin()) {
      LOG("SigFox begin failed, rebooting!");
      NVIC_SystemReset();
      while (1);
    }
  
    // Enable debug and print useful data
    SigFox.debug();
    LOG("SigFox FW version " + SigFox.SigVersion());
    LOG("ID  = " + SigFox.ID());
    LOG("PAC = " + SigFox.PAC());
    LOG("");
  
    // Send the module to the deepest sleep
    SigFox.end();

   accelerometer.initialise();
   humidity.initialise();
   light.initialise();

  // Can be used to show info
  //pinMode(LED_BUILTIN, OUTPUT);

  // Attach pin 0 and 1 interrupts on voltage falling event
  pinMode(1, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(1), AccelerometerSigfoxSensor::freeFallDetectedISR, FALLING);

  LOG("Setup done");
}

// Run forever
void loop()
{
  // Create time triggers
  static unsigned long timeout = 0;
  static unsigned long timeout_light = 0;

  // Poll light sensor periodically
  if( millis() >= timeout_light){
      // Compute new time triggers
      timeout_light = millis() + LIGHT_SENSOR_POLL_MILLIS;

      //Read light sensor
      LOG("Polling light sensor");
      light.updatePacketOpenState();
  }

  // Send message via SigFox after 60s or when packet is dropped
  if ((millis() >= timeout) || accelerometer.packetDropped() || light.getPacketOpen())
  {

    // Compute new time triggers
    timeout = millis() + REPORT_FREQUENCY_MILLIS;
    timeout_light = millis() + LIGHT_SENSOR_POLL_MILLIS;
    
    // Populate and send SigFox Message
    LOG("Sending SigFox message");
    accelerometer.logMessage(sigfoxMessage);
    humidity.logMessage(sigfoxMessage);
    light.updatePacketOpenState();
    light.logMessage(sigfoxMessage);
    dataSink.sendData(sigfoxMessage.message(), 12);
  }
}
