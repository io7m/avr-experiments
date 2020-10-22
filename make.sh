#!/bin/sh -ex

mkdir -p build

CFLAGS="-Os -Wall -Werror -Wextra -Wpedantic -std=c11 -Wno-error=unused-parameter -mmcu=atmega2560 -DARDUINO=10814 -DF_CPU=16000000 -DBAUD=9600 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR"
LDFLAGS="-mmcu=atmega2560"

avr-gcc ${CFLAGS} -o build/blink_task.o -c blink_task.c
avr-gcc ${CFLAGS} -o build/uart.o -c uart.c
avr-gcc ${CFLAGS} -o build/main.o -c main.c
avr-gcc ${LDFLAGS} -o build/main build/main.o build/uart.o build/blink_task.o
avr-objcopy -j .text -j .data -O ihex build/main build/main.hex
