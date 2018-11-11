/**
 * Prog3-2018-2-Trab2: Reading a CSV file with data about Brazilian elections in C++
 *
 * Alan Herculano Diniz
 * Rafael Belmock Pedruzzi
 *
 * coalition.h: coalition class definition file
 */

#ifndef COALITION_H_

#define COALITION_H_

#include <string>
#include <set>

class Party;

class Coalition
{
    string name;
    set<Party *> parties;
    int votes;

public:
    const string &getName() const; 
    void setName(const string &name);
    const int &getVotes() const;
    void setVotes(const int &votes);
    const set<Party *> &getParties() const;
    void addCandidate(const string &name, const string &party, const int &votes, const string &percent, const bool &elected);
    const string &toString() const;
};

#endif // COALITION_H_