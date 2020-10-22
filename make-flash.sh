#!/bin/sh -ex

avrdude \
  -p atmega2560 \
  -c wiring \
  -P /dev/ttyACM0 \
  -b 115200 \
  -D \
  -v \
  -U flash:w:build/main.hex:i
