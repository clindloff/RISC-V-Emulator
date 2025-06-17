CC = gcc
CFLAGS = -O3 -Wall -Wextra -I./include
SRC_DIR = ./src
INC_DIR = ./include
OBJ_DIR = ./obj
BIN_DIR = ./bin

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
HEADERS := $(wildcard $(INC_DIR)/*.h)
TARGET = $(BIN_DIR)/virtualizer

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
