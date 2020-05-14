echo "Deploying to AVR Device on /dev/ttyUSB0"

avrdude -q -v -V -p m328p -C /usr/share/arduino/hardware/tools/avrdude.conf -D -c arduino -b 57600 -P /dev/ttyUSB0 -U flash:w:/home/pi/avr_projects/mcu0/bin/mcu0.hex:i