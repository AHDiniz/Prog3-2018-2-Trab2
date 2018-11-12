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
#include <unordered_set>
#include "../include/party.h"

class Party;

class Coalition
{
    string name;
    unordered_set<Party *> *parties;
    int votes;

public:
    Coalition(int v=0);

    const string &getName() const; 
    void setName(const string &name);
    const int &getVotes() const;
    void setVotes(const int &votes);
    const unordered_set<Party *> &getParties() const;
    void addCandidate(const string &name, const string &party, const int votes, const string &percent, const bool elected);
    const string &toString() const;

    ~Coalition() { delete parties; }
};

#endif // COALITION_H_
