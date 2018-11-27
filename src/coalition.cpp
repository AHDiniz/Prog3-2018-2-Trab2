/**
 * Prog3-2018-2-Trab2: Reading a CSV file with data about Brazilian elections in C++
 *
 * Alan Herculano Diniz
 * Rafael Belmock Pedruzzi
 *
 * coalition.cpp: coalition class implementation file
 */

#include <algorithm>
#include <sstream>
#include <iostream>

#include "../include/coalition.h"
#include "../include/party.h"
#include "../include/candidate.h"

Coalition::Coalition(string n)
{
    name = n;
    votes = 0;
    // parties = new unordered_set<Party *>();
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

void Coalition::setVotes(const int &votes)
{
    this->votes = votes;
}

const unordered_set<Party *> &Coalition::getParties() const
{
    return *parties;
}

void Coalition::addCandidate(Candidate &candidate)
{
    std::unordered_set<Party *>::const_iterator position = this->parties->find((Party *)&(candidate.getParty())); // Looking for the party in the set
    if (position == this->parties->end())
    {
        this->parties->insert((Party *)&(candidate.getParty()));
        Party *p = *(this->parties->find((Party *)&(candidate.getParty())));
        p->setCoalition(*this);
        p->addCandidate(candidate);
    }
    else
    {
        Party *p = (Party *)*position;
        p->addCandidate(candidate);
    }
    this->votes += candidate.getVotes();
}

string Coalition::toString()
{
    stringstream ret;

    for (Party *p : *(this->parties))
    {
        for (Candidate *c : p->getCandidates())
        {
            ret << c->toString() << endl;
        }
    }

    return ret.str();
}

bool Coalition::compare(const Coalition *a, const Coalition *b)
{
    return (a != b) && a->getVotes() > b->getVotes();
}

// bool CoalitionComparator::operator()(const Coalition *a, const Coalition *b)
// {
//     return Coalition::compare(a,b);
// }