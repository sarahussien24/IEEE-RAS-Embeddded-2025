# Makefile for AVR Motor Control Project

### Project Configuration ###
PROJECT     = motor_control
MCU         = atmega32
F_CPU       = 1000000
BAUD        = 9600

### Directory Structure ###
SRCDIR      = src
INCDIR      = inc
BUILDDIR    = build
DEPDIR      = $(BUILDDIR)/dep

### Toolchain Configuration ###
CC          = avr-gcc
OBJCOPY     = avr-objcopy
OBJDUMP     = avr-objdump
SIZE        = avr-size
AVRDUDE     = avrdude

### Source Files ###
SRC         = $(wildcard $(SRCDIR)/*.c)
MAIN        = main.c
SOURCES     = $(SRC) $(MAIN)

### Object Files ###
OBJECTS     = $(addprefix $(BUILDDIR)/,$(notdir $(SOURCES:.c=.o)))
DEPFILES    = $(addprefix $(DEPDIR)/,$(notdir $(SOURCES:.c=.d)))

### Include Paths ###
INCLUDES    = -I$(INCDIR)

### Compiler/Linker Flags ###
CFLAGS      = -mmcu=$(MCU) -DF_CPU=$(F_CPU)UL -DBAUD=$(BAUD) -Os -Wall \
              -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums \
              -ffunction-sections -fdata-sections $(INCLUDES)
LDFLAGS     = -mmcu=$(MCU) -Wl,-Map,$(BUILDDIR)/$(PROJECT).map \
              -Wl,--gc-sections

### AVRDUDE Settings ###
PROGRAMMER  = usbasp
PORT        = usb
AVRDUDE_FLAGS = -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD)

### Build Targets ###
.PHONY: all clean flash flash_fuses size disasm

all: size $(BUILDDIR)/$(PROJECT).hex

$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR) $(DEPDIR)
	$(CC) $(CFLAGS) -MMD -MF $(DEPDIR)/$(notdir $(<:.c=.d)) -c $< -o $@

$(BUILDDIR)/%.o: %.c | $(BUILDDIR) $(DEPDIR)
	$(CC) $(CFLAGS) -MMD -MF $(DEPDIR)/$(notdir $(<:.c=.d)) -c $< -o $@

$(BUILDDIR)/$(PROJECT).elf: $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(BUILDDIR)/$(PROJECT).hex: $(BUILDDIR)/$(PROJECT).elf
	$(OBJCOPY) -O ihex -R .eeprom -R .fuse -R .lock $< $@
	$(OBJCOPY) -j .eeprom --set-section-flags=.eeprom="alloc,load" \
	--change-section-lma .eeprom=0 -O ihex $< $(BUILDDIR)/$(PROJECT).eep

$(BUILDDIR)/$(PROJECT).lst: $(BUILDDIR)/$(PROJECT).elf
	$(OBJDUMP) -h -S $< > $@

$(BUILDDIR) $(DEPDIR):
	mkdir -p $@

### Utility Targets ###
size: $(BUILDDIR)/$(PROJECT).elf
	@echo "Memory Usage:"
	@$(SIZE) --format=berkeley $<

disasm: $(BUILDDIR)/$(PROJECT).lst

clean:
	rm -rf $(BUILDDIR)

flash: $(BUILDDIR)/$(PROJECT).hex
	$(AVRDUDE) $(AVRDUDE_FLAGS) -U flash:w:$<:i

flash_fuses:
	$(AVRDUDE) $(AVRDUDE_FLAGS) -U lfuse:w:0x64:m -U hfuse:w:0xd9:m

### Include Dependency Files ###
-include $(DEPFILES)