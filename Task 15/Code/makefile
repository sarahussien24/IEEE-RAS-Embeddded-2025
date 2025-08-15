MCU = atmega32
F_CPU = 8000000UL
BAUD = 9600

CC = avr-gcc
CFLAGS = -Wall -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU)

LD = avr-gcc
LDFLAGS = -mmcu=$(MCU)

AVRDUDE = avrdude
AVRDUDE_PROGRAMMER = usbasp
AVRDUDE_PORT = usb
AVRDUDE_BAUD = 19200

SRC = main.c \
      LCD/LCD.c \
      KEYPAD/KEYPAD.c

OBJ = $(SRC:.c=.o)

TARGET = calc

all: $(TARGET).hex

$(TARGET).elf: $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o $@

$(TARGET).hex: $(TARGET).elf
	avr-objcopy -O ihex -R .eeprom $< $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

flash: $(TARGET).hex
	$(AVRDUDE) -c $(AVRDUDE_PROGRAMMER) -p $(MCU) -P $(AVRDUDE_PORT) -b $(AVRDUDE_BAUD) -U flash:w:$(TARGET).hex

clean:
	rm -f $(OBJ) $(TARGET).elf $(TARGET).hex
