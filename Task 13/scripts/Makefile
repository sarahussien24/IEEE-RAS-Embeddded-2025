MCU     = atmega32
CC      = avr-gcc
CFLAGS  = -Os -DF_CPU=8000000UL -mmcu=$(MCU)
TARGET  = program
SRC_DIR = ../program
OUT_DIR = ../build
BIN_DIR = ../build/bin

# Ensure the build directories exist
$(shell mkdir -p $(BIN_DIR))


# Recursive wildcard function to find all .c files in SRC_DIR and subdirectories
define rwildcard
$(wildcard $(1)/*.c) $(foreach d,$(wildcard $(1)/*/),$(call rwildcard,$d))
endef

# Use the rwildcard function to find all .c files in the program directory
SRC  := $(call rwildcard,$(SRC_DIR))
OBJ  := $(patsubst $(SRC_DIR)/%.c,$(OUT_DIR)/Debug/%.o,$(SRC))


# Rule to Build all Program Files
all: sync $(OUT_DIR)/$(TARGET).hex
	@mv $(OUT_DIR)/*.elf $(BIN_DIR)
	@mv $(OUT_DIR)/*.hex $(BIN_DIR)
	@echo
	@echo "----------------------------------------------------------"
	@echo "---------- HEX File was Generated [Successful] -----------"
	@echo "----------------------------------------------------------"
	@echo


# Rule to Compile all C files to Object files
$(OUT_DIR)/Debug/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


# Rule to show compiling files
src: $(SRC)
	@echo
	@echo "***************************************************"
	@echo "****** [Compiling the following '.c' files] *******"
	@echo "***************************************************"
	@$(foreach file,$(SRC), echo $(file);)
	@echo "***************************************************"
	@echo


# Rule to Build all Object files
build : src $(OBJ)
	@echo
	@echo "******************************************************"
	@echo "****** [the following '.o' files was generated] ******"
	@echo "******************************************************"
	@$(foreach file,$(OBJ), echo $(file);)
	@echo "******************************************************"
	@echo


# Rule to generate ELF file from Object files
$(OUT_DIR)/$(TARGET).elf: build
	@echo
	@echo "----------------------------------------------------"
	@echo "------------   [Generating ELF file]   -------------"
	@echo "----------------------------------------------------"
	$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo


# Rule to generate HEX file from ELF file
$(OUT_DIR)/$(TARGET).hex: $(OUT_DIR)/$(TARGET).elf
	@echo
	@echo "----------------------------------------------------"
	@echo "------------   [Generating HEX file]   -------------"
	@echo "----------------------------------------------------"
	avr-objcopy -O ihex -R .eeprom $(OUT_DIR)/$(TARGET).elf $(OUT_DIR)/$(TARGET).hex
	@echo


# Rule to clean all output files
clean:
	@rm -rf $(OUT_DIR)
	@echo
	@echo "----------------------------------------------------"
	@echo "-------- [Output directory was cleaned now] --------"
	@echo "----------------------------------------------------"


# Rule to sync directories before building
sync: copy_dirs
	@echo
	@echo "----------------------------------------------------"
	@echo "------- [Source files ready for Compilation] -------"
	@echo "----------------------------------------------------"


# Rule to copy directories
copy_dirs:
	@echo "----------------------------------------------------"
	@echo "----- [Copying directory 'program' to 'output'] ----"
	@if [ ! -d $(SRC_DIR) ]; then echo "ERROR: Source directory '$(SRC_DIR)' not found!"; exit 1; fi
	@echo "SRC_DIR is: $(SRC_DIR)"
	@cp -r $(SRC_DIR) $(OUT_DIR)
	@mv $(OUT_DIR)/program $(OUT_DIR)/Debug
	@echo "----------------------------------------------------"