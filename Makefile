###################################################################
### USB Port
###################################################################
PORT=/dev/ttyUSB0
#PORT/dev/ttyACM0

###################################################################
### Board Info
###################################################################
MCU=atmega328p
BOARD=arduino
BAUD=115200
F_CPU=16000000UL

###################################################################
### Flags
###################################################################
CFLAGS=-g -Wall -mcall-prologues -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os
LDFLAGS=-Wl,-gc-sections -Wl,-relax

###################################################################
### Programs
###################################################################
CC=avr-gcc
OBJ_COPY=avr-objcopy
PGMR=avrdude

###################################################################
### Target File
###################################################################
TARGET=main

###################################################################
### Object File List
### Note: Must list all
###
### Example: OBJECT_FILES=main.o libgpio.o 
###################################################################
OBJECT_FILES=main.o libgpio.o libspi.o

###################################################################
### Operations:
###
### Example:
### $ make all
### avr-gcc -g -Wall -mcall-prologues -mmcu=atmega328p -DF_CPU=16000000UL -Os   -c -o main.o main.c
### avr-gcc -g -Wall -mcall-prologues -mmcu=atmega328p -DF_CPU=16000000UL -Os   -c -o libgpio.o libgpio.c
### avr-gcc -g -Wall -mcall-prologues -mmcu=atmega328p -DF_CPU=16000000UL -Os main.o libgpio.o -Wl,-gc-sections -Wl,-relax -o main.obj
### avr-objcopy -R .eeprom -O ihex main.obj main.hex
### rm main.obj main.o libgpio.o
###################################################################
all: $(TARGET).hex

clean:
	rm -f *.o *.hex *.obj *.hex

%.hex: %.obj
	$(OBJ_COPY) -R .eeprom -O ihex $< $@

%.obj: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) $(LDFLAGS) -o $@

program: $(TARGET).hex
	$(PGMR) -v -p $(MCU) -c $(BOARD) -P $(PORT) -b $(BAUD) -U flash:w:$(TARGET).hex:i




