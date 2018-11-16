/**
 * Prog3-2018-2-Trab2: Reading a CSV file with data about Brazilian elections in C++
 *
 * Alan Herculano Diniz
 * Rafael Belmock Pedruzzi
 *
 * election.cpp: election class implementation file
 */

#include <algorithm>
#include "../include/election.h"

Election::Election(map<string, Coalition *, CoalitionComparator> *coalitions, const int vacancies)
{
    this->coalitions = coalitions;
    this->vacancies = vacancies;

    for (map<string, Coalition *, CoalitionComparator>::iterator coIt = coalitions->begin(); coIt != coalitions->end(); coIt++)
    {
        for (const Party *p : coIt->second->getParties())
        {
            for (Candidate *c : p->getCandidates())
            {
                mostVoted->push_back(c);
            }
        }
    }
    sort(mostVoted->begin(), mostVoted->end(), Candidate::compare);
}

string Election::numberOfVacancies() const
{

}

string Election::electedCandidates() const
{

}

string Election::mostVotedCandidates() const
{
    
}

string Election::electedByMajority() const
{

}

string Election::electedByProportion() const
{

}

string Election::votesByCoalition() const
{

}

string Election::votesByParty() const
{

}

int Election::amountOfVotes() const
{

}
