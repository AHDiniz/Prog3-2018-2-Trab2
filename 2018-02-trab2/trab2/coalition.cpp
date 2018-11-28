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

#include "coalition.h"
#include "party.h"
#include "candidate.h"

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
    // Looking for the party in the set:
    std::unordered_set<Party *>::const_iterator position = this->parties->find((Party *)&(candidate.getParty()));
    if (position == this->parties->end())   // If it is't in the set, it is inserted and the candidate is added to it:
    {
        this->parties->insert((Party *)&(candidate.getParty()));
        Party *p = *(this->parties->find((Party *)&(candidate.getParty())));
        p->setCoalition(*this);
        p->addCandidate(candidate);
    }
    else    // Else, add candidate to the founded party:
    {
        Party *p = (Party *)*position;
        p->addCandidate(candidate);
    }
    this->votes += candidate.getVotes();    // Updating coalition's number of votes.
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
    // Compares coalitions by the number of votes:
    return (a != b) && a->getVotes() > b->getVotes();
}
