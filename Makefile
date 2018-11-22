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

all: $(BIN)/$(TARGET)

$(BIN)/main.o: $(SRC)/main.cpp
	$(CC) -c $^ -o $@ $(FLAGS)

$(BIN)/candidate.o: $(SRC)/candidate.cpp
	$(CC) -c $^ -o $@ $(FLAGS)

$(BIN)/party.o: $(SRC)/party.cpp
	$(CC) -c $^ -o $@ $(FLAGS)

$(BIN)/coalition.o: $(SRC)/coalition.cpp
	$(CC) -c $^ -o $@ $(FLAGS)

$(BIN)/election.o: $(SRC)/election.cpp
	$(CC) -c $^ -o $@ $(FLAGS)

$(BIN)/reader.o: $(SRC)/reader.cpp
	$(CC) -c $^ -o $@ $(FLAGS)

$(BIN)/$(TARGET): $(BIN)/main.o $(BIN)/candidate.o $(BIN)/party.o $(BIN)/coalition.o $(BIN)/election.o $(BIN)/reader.o
	$(CC) -o $@ $^ $(FLAGS)

test: $(SRC)/main.cpp $(SRC)/party.cpp $(SRC)/candidate.cpp $(SRC)/coalition.cpp
	$(CC) -o $(BIN)/$(TARGET) $^ $(FLAGS)
