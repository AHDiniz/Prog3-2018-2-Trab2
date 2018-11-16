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
#include <sstream>

#include "party.h"

using namespace std;

class Party;

class Candidate
{
    string name; // The candidate's name
    Party *party; // The candidate's party
    int votes; // The amount of votes
    string percent; // The percentage of valid votes
    bool elected; // Tells if the candidate was elected or not

public:
    /**
     * Candidate's constructor method:
     * 
     * Inputs: values and references to every attribute of the object
     * Output: a new candidate
     * Conditions: none
     * Side effects: a new Candidate is created, dynamically if new is used
     */
    Candidate(const string &name, Party &party, int votes, const string &percent, bool elected);
    Candidate(int v = 0, const string p = "0%", bool e = false);
    Candidate(Candidate &c);
    ~Candidate() { delete party; }

    // Candidate's name getter:
    const string &getName() const;
    // Candidate's name setter:
    void setName(const string &name);
    // Candidate's party getter:
    const Party &getParty() const;
    // Candidate's party setter:
    void setParty(const Party &party);
    // Candidate's votes getter:
    const int getVotes() const;
    // Candidate's vote setter:
    void setVotes(const int votes);
    // Candidate's percentage getter:
    const string &getPercent() const;
    // Candidate's percentage setter:
    void setPercent(const string &percent);
    // Candidate's elected bool getter:
    const bool getElected() const;
    // Candidate's elected bool setter:
    void setElected(const bool elected);
    string toString();
    static bool compare(const Candidate *a, const Candidate *b);
};

#endif
