# Directories containing source files
SRC_DIRS := Algrebra Algorithms DataStructures libft Utils 

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Iinclude

# Output directory
OUTPUT_DIR := lib
NAME = UniC.a

# Source files
SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))

# Object files
OBJS := $(patsubst %.c,%.o,$(SRCS))

# Target library
TARGET := $(OUTPUT_DIR)/$(NAME)

# Default target
all: $(TARGET)

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create static library
$(TARGET): $(OBJS)
	mkdir -p $(OUTPUT_DIR)
	ar rcs $@ $^

# Clean build artifacts
clean:
	rm -rf $(OUTPUT_DIR) $(OBJS)