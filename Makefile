# Prog3-2018-2-Trab2: Reading a CSV file with data about Brazilian elections in C++
#
# Alan Herculano Diniz
# Rafael Belmock Pedruzzi
#
# Project's build file

SRC = src

BIN = bin

CC = g++

FLAGS = -Wall -g -std=c++11

ifeq ($(OS), Windows_NT)
	TARGET = trab2.exe
else
	TARGET = trab2
endif

SOURCES = $(wildcard $(SRC)/*.cpp)

EXE = $(BIN)/$(TARGET)

INPUT = ./2018-02-trab2/testes/capela/in/divulga.csv

compile: $(EXE)

$(EXE): $(SOURCES)
	$(CC) -o $@ $^ $(FLAGS)

test: $(SRC)/main.cpp $(SRC)/party.cpp $(SRC)/candidate.cpp $(SRC)/coalition.cpp
	$(CC) -o $(BIN)/$(TARGET) $^ $(FLAGS)

run: $(EXE)
	./$(EXE) $(INPUT)

clean:
	rm $(BIN)/*.o
