# Makefile for AVR Project

# Target microcontroller
MCU = atmega32

# Processor frequency
F_CPU = 8000000

# Output file name
TARGET = main

# Directories
DRIVERS_DIR = Drivers
DIO_DIR = $(DRIVERS_DIR)/DIO
EXTI_DIR = $(DRIVERS_DIR)/EXTI
SEVEN_SEG_DIR = $(DRIVERS_DIR)/Seven_Segment
LCD_DIR = $(DRIVERS_DIR)/LCD
LIBRARIES_DIR = Libraries
APPLICATION_DIR = Application

# Source files
SRC = $(APPLICATION_DIR)/main.c \
      $(DIO_DIR)/DIO.c \
      $(EXTI_DIR)/EXTI0.c \
      $(EXTI_DIR)/EXTI1.c \
      $(SEVEN_SEG_DIR)/SEVEN_SEG.c \
      $(LCD_DIR)/LCD.c

# Object files
OBJ = $(SRC:.c=.o)

# Include paths
INCLUDES = -I$(APPLICATION_DIR) \
           -I$(DIO_DIR) \
           -I$(EXTI_DIR) \
           -I$(SEVEN_SEG_DIR) \
           -I$(LCD_DIR) \
           -I$(LIBRARIES_DIR)

# Compiler
CC = avr-gcc

# Compiler flags
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU)UL -Os -Wall -std=gnu99 $(INCLUDES)

# Linker flags
LDFLAGS = -mmcu=$(MCU)

# Programmer
PROGRAMMER = usbasp

# AVRDUDE flags
AVRDUDE_FLAGS = -p $(MCU) -c $(PROGRAMMER)

# Default target
all: $(TARGET).hex

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files to create ELF file
$(TARGET).elf: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

# Convert ELF file to Intel Hex format
$(TARGET).hex: $(TARGET).elf
	avr-objcopy -O ihex -R .eeprom $< $@

# Flash the microcontroller
flash: $(TARGET).hex
	avrdude $(AVRDUDE_FLAGS) -U flash:w:$<

# Clean build files
clean:
	rm -f $(OBJ) *.elf *.hex

.PHONY: all flash clean