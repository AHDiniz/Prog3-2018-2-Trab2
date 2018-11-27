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
    string name;		// Coalition's identificator. Basicaly the names of the parties within it.
    unordered_set<Party *> *parties = new unordered_set<Party *>();	// Coalition's parties set.
    int votes;			// Coalition's number of votes.

  public:
    // Coalition's default constructor:
    Coalition(string n = "");
    ~Coalition()
    {
        delete parties;
    }

	// Name getter:
    const string &getName() const;
	// Name setter:
    void setName(const string &name);
	// Votes getter:
    const int &getVotes() const;
	// Votes setter:
    void setVotes(const int &votes);
	// Parties getter:
    const unordered_set<Party *> &getParties() const;
	// Adding a candidate to the set:
    void addCandidate(Candidate &candidate);
	// Coalition's to string method:
    string toString();
	// Coalition's comparator:
    static bool compare(const Coalition *a, const Coalition *b);
};

#endif // COALITION_H_
