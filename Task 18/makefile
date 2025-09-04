MCU=atmega32
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-mmcu=$(MCU) -Os -Wall
OBJ=main.o MCAL/timer0.o MCAL/timer1.o MCAL/adc.o MCAL/gpio.o MCAL/wdt.o HAL/lcd.o HAL/ultrasonic.o
TARGET=main.elf
HEX=main.hex

all: $(HEX)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

$(HEX): $(TARGET)
	$(OBJCOPY) -O ihex -R .eeprom $(TARGET) $(HEX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET) $(HEX)