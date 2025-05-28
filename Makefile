CC = gcc

CFLAGS = -Wall -Wextra -pedantic

LIBS = -lncursesw -lpthread

TARGET = termspace

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

SRCS = $(wildcard *.c)
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

SYMLINK = ./$(TARGET)

all: clean $(BIN_DIR)/$(TARGET) symlink

setup:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

$(BIN_DIR)/$(TARGET): $(OBJS) | setup
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(OBJ_DIR)/%.o: %.c | setup
	$(CC) $(CFLAGS) -c -o $@ $<

symlink: $(BIN_DIR)/$(TARGET)
	ln -sf $(BIN_DIR)/$(TARGET) $(SYMLINK)

clean:
	rm -rf $(OBJ_DIR)/*.o $(SYMLINK)

distclean: clean
	rm -rf $(BUILD_DIR) $(SYMLINK)

install: $(BIN_DIR)/$(TARGET)
	cp $(BIN_DIR)/$(TARGET) /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/$(TARGET)

.PHONY: all setup symlink clean distclean install uninstall
