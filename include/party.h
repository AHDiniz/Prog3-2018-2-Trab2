/**
 * Prog3-2018-2-Trab2: Reading a CSV file with data about Brazilian elections in C++
 *
 * Alan Herculano Diniz
 * Rafael Belmock Pedruzzi
 *
 * party.h: party class definition file
 */

#ifndef PARTY_H_

#define PARTY_H_

#include <string>
#include <set>

#include "candidate.h"

using namespace std;

class Candidate;

class Party
{
    string coalition;
    string name;
    int votes=0;
    set<Candidate *> candidates;

public:
    const string &getCoalition() const;
    void setCoalition(const string &coalition);
    const string &getName() const;
    void setName(const string &name);
    const int getVotes() const;
    void setVotes(const int votes);
    const set<Candidate *> &getCandidates() const;
    void addCandidate(Candidate &candidate);
};

#endif
