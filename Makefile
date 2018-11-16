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

test: $(SRC)/main.cpp $(SRC)/candidate.cpp $(SRC)/party.cpp
	$(CC) -o $(BIN)/$(TARGET) $^ $(FLAGS)
