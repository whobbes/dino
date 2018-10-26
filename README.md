# DINO
##### DO NOT DROP // DO NOT OPEN

######Proof of Concept project around asset tracking via IoT

The aim is to monitor a package and send regular messages with sensor values as well as event message if the box is dropped or opened. The messages sent can be seen via the SigFox Backend.

Last update: 2018/10/23

## Hardware
* MKRFOX1200 - main board
* WINGONEER MMA8452 - accelerometer
* DHT22 - digital temperature and humidity sensor
* Grove Light - analog light sensor
* AA batteries holder and connector - (optional, only for operating device on batteries)

## Software
* Arduino IDE
* MKRFOX1200 Board drivers
* Arduino libraries
	*  Arduino\_Low\_Power
	*  RTCZero
	*  DHT\_sensor_library
	*  SPI
	*  Wire
	*  Arduino\_Sigfox\_for_MKRFox1200

## Arduino Setup

### Wiring

* MKRFOX1200
	*  Power via USB - connect 5V source (optional)
	*  	Power via Batteries - connect 2*1.5V source (optional)
	*  External antenna - provided with arduino kit

* DHT22 Temperature and humidity
	*  VCC - 5v
	*  GND - GND
	*  OUT - pin 3
	
* Grove light
	*  VCC - 5v
	*  GND - GND
	*  SIG - pin A5
	*  NC - GND (optional)
	
* MMA8452 Accelerometer
	*  VCC_IN - 5v
	*  GND - GND
	*  SCL - pin 12 SCL
	*  SDA - pin 11 SDA
	*  INT2 - pin 1

N.B. see diagram.png

### Device flashing and activation
* Open dino.ino with Arduino IDE
* Select MKRFOX1200 port via Tools > Ports
* Then Upload sketch to board
* Register MKRFOX1200 [Sigfox Backend](https://backend.sigfox.com/activate) - Use PAC and ID printed in console when program starts

N.B. If encountering issue with flashing the device, enable bootloader more to load software by double tapping reset button.

##Backend

Follow instructions given at [arduino.cc](https://www.arduino.cc/en/Tutorial/SigFoxFirstConfiguration)

## Built with ❤ by

* Rajiv - rajiv.kurien@zuhlke.com
* Miles - miles.pool@zuhlke.com
* Chris - christopher.burdett-smith-whitting@zuhlke.com
* Wallace - wallacehobbes@gmail.com - [whobbes.com](whobbes.com)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgments
Thanks to Zühlke for allowing fun projects to be built and shared.