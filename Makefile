# Directories to search for source files
DIRS := Algebra Algorithms DataStructures libft Utils

# Find all .c files in the specified directories and their subdirectories
SRCS := $(shell find $(DIRS) -name '*.c')

# Object files corresponding to source files
OBJS := $(SRCS:.c=.o)

# Name of the static library
LIB := UniC.a

# Compiler and flags
CC := gcc
CFLAGS := -I. -g # -Wall -Wextra -Werror
LINK := -lm

# Default target
all: $(LIB)

# Rule to create the static library
$(LIB): $(OBJS)
	ar rcs $@ $^

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) $(LINK) -c $< -o $@

# Rule to clean up
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(LIB)

re: fclean all

test:
	$(CC) $(CFLAGS) main.c ./UniC.a -o main && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./main

.PHONY: all clean fclean re test