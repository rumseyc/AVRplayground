GCCFLAGS=-g -Os -Wall -mmcu=atmega168
LINKFLAGS=-Wl,-u,vfprintf -lprintf_flt -Wl,-u,vfscanf -lscanf_flt -lm
AVRDUDEFLAGS=-c avr109 -p m168 -b 115200 -P /dev/cu.usbserial-A104OKJW

led_blink.ass:	led_blink.hex
	avr-objdump -S -d led_blink.o > led_blink.ass

led_blink.hex:	led_blink.c
	avr-g++ ${GCCFLAGS} ${LINKFLAGS} -o led_blink.o led_blink.c ${LINKOBJECTS}
	avr-objcopy -j .text -O ihex led_blink.o led_blink.hex



clobber: clobber_files
help: make_help
all:	led_blink-upload

led_blink-upload:	led_blink.hex
	avrdude ${AVRDUDEFLAGS} -U flash:w:led_blink.hex:a

clobber_files:
							-rm -f *.o *.hex *.ass

make_help:
						@echo "========================================="
						@echo "all:  makes files and upload to AVR"
						@echo "clobber:  clears out old files"
						@echo "========================================="
