# Compilador
CC = gcc
# CFLAGS = -g -Wall -O0
CFLAGS = -g -O3  # Flag -Wall removida para funcionar no runcodes
INCLUDE = $(wildcard src/*.h)
SOURCES = $(wildcard src/*.c)
OBJ = $(SOURCES:$(SRC_DIR)/%.c = $(SRC_DIR)/%.o)

# Diretórios
SRC_DIR = src
BIN_DIR = bin

# Target
NOME_EXECUTAVEL = brain
TARGET = $(BIN_DIR)/$(NOME_EXECUTAVEL)


# Criar diretórios bin e build
$(BIN_DIR):
	mkdir -p $(BIN_DIR)


# Compilar arquivos .c em arquivos .o
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

# Set the default goal to 'all'
.DEFAULT_GOAL := all

all: $(OBJ) $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)
	

debug: $(OBJ) $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) -DDEBUG

run:
	$(TARGET)


.PHONY: clean


clean:
	@rm -f $(BUILD_DIR)/*.o ./*.zip $(BIN_DIR)/* core

zip: 
	@rm -f *.zip
	zip -r $(NOME_EXECUTAVEL).zip $(SRC_DIR)/* ./Makefile ./*.txt