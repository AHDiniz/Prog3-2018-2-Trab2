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

class Reader
{
  public:
    static Election *readFile(const string filePath, const string encoding);

  private:
    static inline void ltrim(string &s);
    static inline void rtrim(string &s);
    static inline void trim(string &s);
};

#endif // READER_H_
