/**
 * Prog3-2018-2-Trab2: Reading a CSV file with data about Brazilian elections in C++
 *
 * Alan Herculano Diniz
 * Rafael Belmock Pedruzzi
 *
 * election.h: election class definition file
 */

#ifndef ELECTION_H_

#define ELECTION_H_

#include <map>
#include <vector>
#include <string>
#include <sstream>
#include "coalition.h"
#include "party.h"
#include "candidate.h"

using namespace std;

class Election
{
  private:
    map<string, Coalition *> *coalitions; // Map with every coalition in the election
    vector<Candidate *> mostVoted;        // List of candidates ordered by the number of votes
    int vacancies;                        // Number of vacant positions/elected candidates

  public:
    /**
     * Election object's constructor method:
     * 
     * Inputs: the map of coalitions and it's names and the number of vacancies
     * Output: an election object
     * Conditions: if new is used, remember to destroy the structure
     */
    Election(map<string, Coalition *> *coalitions, const int vacancies);
    ~Election(); // Election destructor

    stringstream numberOfVacancies() const;
    stringstream electedCandidates() const;
    stringstream mostVotedCandidates() const;
    stringstream electedByMajority() const;
    stringstream electedByProportion() const;
    stringstream votesByCoalition() const;
    stringstream votesByParty() const;
    int amountOfVotes() const;
};

#endif // ELECTION_H_
