# ====== Project Settings ======
TARGET = project

# MCU settings
MCU = atmega32
F_CPU = 8000000UL

# Compiler / Tools
CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

# Source & Include directories
SRC_DIRS = . GPIO ADC LCD
INC_DIRS = . GPIO ADC LCD
INCLUDES = $(foreach dir,$(INC_DIRS),-I$(dir))

# Collect all .c files
SRCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
OBJS = $(SRCS:.c=.o)

# Compiler flags
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -std=gnu11 $(INCLUDES)
LDFLAGS = -mmcu=$(MCU)

# Output files
ELF = $(TARGET).elf
HEX = $(TARGET).hex

# Programmer settings
PROGRAMMER = usbasp
PORT = usb
BAUD = 115200

# ====== Rules ======
all: $(HEX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(ELF): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(ELF)

$(HEX): $(ELF)
	$(OBJCOPY) -O ihex -R .eeprom $(ELF) $(HEX)

flash: $(HEX)
	$(AVRDUDE) -c $(PROGRAMMER) -p $(MCU) -P $(PORT) -U flash:w:$(HEX):i

size: $(ELF)
	avr-size --format=avr --mcu=$(MCU) $(ELF)

clean:
	rm -f $(OBJS) $(ELF) $(HEX)

.PHONY: all flash clean size
