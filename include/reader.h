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
    Election *readFile(const string filePath, const string encoding);

private:
static inline void ltrim(std::string &s);
static inline void rtrim(std::string &s);
static inline void trim(std::string &s);
};

#endif // READER_H_
