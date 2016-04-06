GCCFLAGS=-g -Os -Wall -mmcu=atmega168
LINKFLAGS=-Wl,-u,vfprintf -lprintf_flt -Wl,-u,vfscanf -lscanf_flt -lm
AVRDUDEFLAGS=-c avr109 -p m168 -b 115200 -P /dev/ttyUSB0

dc_motor.ass:	dc_motor.hex
	avr-objdump -S -d dc_motor.o > dc_motor.ass

dc_motor.hex:	dc_motor.cpp
	avr-g++ ${GCCFLAGS} ${LINKFLAGS} -o dc_motor.o dc_motor.cpp ${LINKOBJECTS}
	avr-objcopy -j .text -O ihex dc_motor.o dc_motor.hex



clobber: clobber_files
help: make_help
all:	dc_motor-upload

dc_motor-upload:	dc_motor.hex
	avrdude ${AVRDUDEFLAGS} -U flash:w:dc_motor.hex:a

clobber_files:
							-rm -f *.o *.hex *.ass

make_help:
						@echo "========================================="
						@echo "all:  makes files and upload to AVR"
						@echo "clobber:  clears out old files"
						@echo "========================================="
