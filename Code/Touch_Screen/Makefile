GCCFLAGS=-g -Os -Wall -mmcu=atmega168
LINKFLAGS=-Wl,-u,vfprintf -lprintf_flt -Wl,-u,vfscanf -lscanf_flt -lm
AVRDUDEFLAGS=-c avr109 -p m168 -b 115200 -P /dev/cu.usbserial-A104OKJW
LINKOBJECTS=Adafruit_GFX.cpp

touch.ass:	touch.hex
	avr-objdump -S -d touch.o > touch.ass

touch.hex:	touch.c
	avr-g++ ${GCCFLAGS} ${LINKFLAGS} -o touch.o touch.c ${LINKOBJECTS}
	avr-objcopy -j .text -O ihex touch.o touch.hex



clobber: clobber_files
help: make_help
all:	touch-upload

touch-upload:	touch.hex
	avrdude ${AVRDUDEFLAGS} -U flash:w:touch.hex:a

clobber_files:
							-rm -f *.o *.hex *.ass

make_help:
						@echo "========================================="
						@echo "all:  makes files and upload to AVR"
						@echo "clobber:  clears out old files"
						@echo "========================================="
