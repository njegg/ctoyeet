BUILD_DIR := ./build
SRC_DIRS := ./src

SRCS := $(shell find $(SRC_DIRS) -name '*.c')

CC := gcc

TARGET := yeet


all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(SRCS)
	@mkdir -p build
	$(CC) $(SRCS) -o $(BUILD_DIR)/$(TARGET)

test: all
	$(BUILD_DIR)/$(TARGET) tests/file.c
	@echo
	gcc out.c
	@echo ./a.out
	@echo
	@./a.out

clean:
	@trash out.c out.h a.out