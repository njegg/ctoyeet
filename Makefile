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
	$(BUILD_DIR)/$(TARGET) ./examples/test/yeet_generator.c
	@printf "\nout.h:\n\n"
	@cat out.h
	@printf "\nout.c:\n\n"
	@cat out.c
	@echo
	gcc out.c -o out
	@echo ./out
	@echo
	@./out | column

clean:
	@rm out.c out.h out

