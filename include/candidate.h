/**
 * Prog3-2018-2-Trab2: Reading a CSV file with data about Brazilian elections in C++
 *
 * Alan Herculano Diniz
 * Rafael Belmock Pedruzzi
 *
 * candidate.h: candidate class definition file
 */

#ifndef CANDIDATE_H_

#define CANDIDATE_H_

#include <string>

#include "party.h"

using namespace std;

class Party;

class Candidate
{
    string name;
    Party &party;
    int votes;
    string percent;
    bool elected;

public:
    const string &getName() const;
    void setName(const string &name);
    const Party &getParty() const;
    void setParty(const Party &party);
    const int getVotes() const;
    void setVotes(const int votes);
    const string &getPercent() const;
    void setPercent(const string &percent);
    const bool getElected() const;
    void setElected(const bool elected);
};

#endif
