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
    /**
     * Static method that reads a file, given it's location, with a given encoding. The file must have the format of the divulga.csv reports given by the brazilian Top Electoral Court (TSE).
     * 
     * Inputs: the location of the file that will be read and the encoding used to write the file.
     * Output: a new election object
     * Conditions: file existent
     * Side effects: new election and all it's coalitions, parties and candidates created.
     */
	static Election *readFile(const string filePath, const string encoding);

  private:
	// Trim methods:
    static inline void ltrim(string &s);
    static inline void rtrim(string &s);
    static inline void trim(string &s);
};

#endif // READER_H_
