/**
 * Prog3-2018-2-Trab2: Reading a CSV file with data about Brazilian elections in C++
 *
 * Alan Herculano Diniz
 * Rafael Belmock Pedruzzi
 *
 * coalition.cpp: coalition class implementation file
 */

#include <algorithm>

#include "../include/coalition.h"
#include "../include/party.h"
#include "../include/candidate.h"

using namespace std;

Coalition::Coalition(int v)
{
    votes = v;
    parties = new unordered_set<Party *>();
}

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

const unordered_set<Party *> &Coalition::getParties() const
{
    return *parties;
}

void Coalition::addCandidate(const string &name, const string &party, const int votes, const string &percent, const bool elected)
{
    this->votes += votes;

    for (Party *p : *parties)
    {
        if (party._Equal(p->getName()))
        {
            Candidate c(name, *p, votes, percent, elected);
            p->addCandidate(c);
            return;
        }
    }
    Party p(party, this->name);
    Candidate c(name, p, votes, percent, elected);
    p.addCandidate(c);
    parties->insert(&p);
}
