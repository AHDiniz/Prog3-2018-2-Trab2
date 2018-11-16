/**
 * Prog3-2018-2-Trab2: Reading a CSV file with data about Brazilian elections in C++
 *
 * Alan Herculano Diniz
 * Rafael Belmock Pedruzzi
 *
 * reader.cpp: reader class implementation file
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <locale>

#include "../include/reader.h"

Election Reader::readFile(const string filePath, const string encoding)
{
    map<string *, Coalition *, CoalitionComparator> *coalitions = new map<string *, Coalition *, CoalitionComparator>(); // Map with all coalitions
    bool elected; // Mark elected candidates
    string aux, name, coalition, party, percent; // Auxiliar reading variables
    int votes = 0; // Vote counter
    int vacancies = 0; // Number of elected candidates
    Coalition temp; // Auxiliar variable

    locale brLocale("pt_BR."+encoding);

    
}