# Compilador
CC = gcc
CFLAGS = -g -Wall -O0
# CFLAGS = -g -O0  # Flag -Wall removida para funcionar no runcodes
INCLUDE = $(wildcard src/*.h)
SOURCES = $(wildcard src/*.c)
OBJ = $(SOURCES:$(SRC_DIR)/%.c = $(SRC_DIR)/%.o)

# Target
NOME_EXECUTAVEL = brain
TARGET = $(BIN_DIR)/$(NOME_EXECUTAVEL)

# Diretórios
SRC_DIR = src
BIN_DIR = bin

# Criar diretórios bin e build
$(BIN_DIR):
	mkdir -p $(BIN_DIR)


# Compilar arquivos .c em arquivos .o
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJ) $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

debug: $(OBJ) $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) -DDEBUG

run: $(TARGET)
	$(TARGET)

.PHONY: clean

clean:
	@rm -f $(BUILD_DIR)/*.o ./*.zip $(TARGET) core

zip: 
	@rm -f *.zip
	zip -r edIII.zip $(SRC_DIR)/* ./Makefile