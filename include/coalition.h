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
#include "party.h"
#include "candidate.h"

using namespace std;

class Party;
class Candidate;

class Coalition
{
    string name;
    unordered_set<Party *> parties;
    int votes;

public:
    Coalition(string n="");
    // ~Coalition()
    // {
    //     for(Party *p: parties)
    //     {
    //         delete p;
    //     }
    // }

    const string &getName() const; 
    void setName(const string &name);
    const int &getVotes() const;
    void setVotes(const int &votes);
    const unordered_set<Party *> &getParties() const;
    void addCandidate(Candidate &candidate);
    string toString();
    static bool compare(const Coalition *a, const Coalition *b);
};

// class CoalitionComparator
// {
// public:
//     bool operator()(const Coalition *a, const Coalition *b);
// };

#endif // COALITION_H_
