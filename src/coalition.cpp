/**
 * Prog3-2018-2-Trab2: Reading a CSV file with data about Brazilian elections in C++
 *
 * Alan Herculano Diniz
 * Rafael Belmock Pedruzzi
 *
 * coalition.cpp: coalition class implementation file
 */

#include "../include/coalition.h"
#include "../include/party.h"
#include "../include/candidate.h"

using namespace std;

const string &Coalition::getName() const
{
    return this->name;
}

void Coalition::setName(const string &name)
{
    this->name = name;
}

const int &Coalition::getVotes() const
{
    return this->votes;
}

void Coalition::setVotes(const int& votes)
{
    this->votes = votes;
}

const set<Party *> &Coalition::getParties() const
{
    return this->parties;
}

void Coalition::addCandidate(const string &name, const string &party, const int votes, const string &percent, const bool elected)
{
    this->votes++;

    for (Party *p : this->parties)
    {
        if (p->getName().compare(party) == 0)
        {
            Candidate c(name, party, votes, percent, elected);
            p->addCandidate(c);
            return;
        }
    }
    Party p(party, this->name);
    Candidate c(name, party, votes, percent, elected);
    p.addCandidate(c);
    this->parties.insert(p);
}
