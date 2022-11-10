BUILD_DIR := ./build
SRC_DIRS := ./src
TARGET := yeet

SRCS := $(shell find $(SRC_DIRS) -name '*.c')

CC := gcc

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(SRCS)
	@mkdir -p build
	@echo "Compiling..."
	@$(CC) $(SRCS) -o $(BUILD_DIR)/$(TARGET)

test: all
	$(BUILD_DIR)/$(TARGET) tests/file.c
	@echo
	gcc out.c
	@echo ./a.out
	@echo
	@./a.out

clean:
	@trash out.c out.h a.out