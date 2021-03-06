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
#include <unordered_set>

#include "candidate.h"
#include "coalition.h"

using namespace std;

class Candidate;
class Coalition;

class Party
{
    Coalition *coalition;                  // The name of the party's coalition
    string name;                           // The name of the party
    int votes = 0;                         // The amount of votes of the party
    unordered_set<Candidate *> *candidates = new unordered_set<Candidate *>(); // The candidates of the party

  public:
    /**
     * Party's constructor:
     * 
     * Inputs: the party's name and coalition
     * Output: a new party object
     * Conditions: none
     * Side effects: new party created, dynamically if new is used
     */
    Party(const string &name, Coalition &coalition);
	// Party's defaut constructor
    Party(const string name = "");
	// Party's copy constructor:
    Party(const Party &p);
    ~Party()
    {
        delete candidates;
    }

    // Coalition name getter:
    Coalition &getCoalition() const;
    // Coalition name setter:
    void setCoalition(Coalition &coalition);
    // Name getter:
    const string &getName() const;
    // Name setter:
    void setName(const string &name);
    // Votes getter:
    const int getVotes() const;
    // Votes setter:
    void setVotes(const int votes);
    // Candidates set getter:
    const unordered_set<Candidate *> &getCandidates() const;
    // Adding a candidate to the set:
    void addCandidate(Candidate &candidate);
	// Comparation method:
    static bool compare(const Party *a, const Party *b);
};

#endif
