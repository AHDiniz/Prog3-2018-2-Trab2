/**
 * Prog3-2018-2-Trab2: Reading a CSV file with data about Brazilian elections in C++
 *
 * Alan Herculano Diniz
 * Rafael Belmock Pedruzzi
 *
 * reader.h: reader class definition file
 */

#ifndef READER_H_

#define READER_H_

#include "election.h"

using namespace std;

static class Reader
{
public:
    Election readFile(const string filePath, const string encoding);
};

#endif // READER_H_
