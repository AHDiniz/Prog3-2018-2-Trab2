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
    vector<Candidate *> mostVoted;        // List of candidates ordered decreasingly by the number of votes
    unsigned vacancies;                   // Number of vacant positions/elected candidates

  public:
    /**
     * Election object's constructor method:
     * 
     * Inputs: the map of coalitions and it's names and the number of vacancies
     * Output: an election object
     * Conditions: if new is used, remember to destroy the structure
     */
    Election(map<string, Coalition *> *coalitions, const unsigned vacancies);
    ~Election(); // Election destructor

	// Method that tells the number of elected candidates:
    string numberOfVacancies() const;
	// Method that tells who was elected:
    string electedCandidates() const;
	// Method that tells the most voted candidates:
    string mostVotedCandidates() const;
	// Method that tells who would be elected by majority but weren't:
    string electedByMajority() const;
	// Method that tells which candidates were elected because of the proportiona system:
    string electedByProportion() const;
	// Method that tells the amount of votes and elected candidates in each coalition:
    string votesByCoalition() const;
	// Method that tells the amount of votes that each party had:
    string votesByParty() const;
	// Method that returns the amont of votes in all coalitions:
    int amountOfVotes() const;
};

#endif // ELECTION_H_
