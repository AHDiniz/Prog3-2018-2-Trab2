/**
 * Prog3-2018-2-Trab2: Reading a CSV file with data about Brazilian elections in C++
 *
 * Alan Herculano Diniz
 * Rafael Belmock Pedruzzi
 *
 * party.cpp: party class implementation file
 */

#include <algorithm>

#include "../include/party.h"

Party::Party(const string &name, Coalition &coalition)
{
    this->setName(name);
    this->setCoalition(coalition);
}

Party::Party(const string name)
{
    this->name = name;
}

Party::Party(const Party &p)
{
    this->setName(p.name);
    this->setVotes(p.votes);
    this->setCoalition(p.getCoalition());
}

Coalition &Party::getCoalition() const
{
    return *(this->coalition);
}

void Party::setCoalition(Coalition &coalition)
{
    this->coalition = (Coalition *)&coalition;
}

const string &Party::getName() const
{
    return name;
}

void Party::setName(const string &name)
{
    this->name = name;
}

const int Party::getVotes() const
{
    return votes;
}

void Party::setVotes(const int votes)
{
    this->votes = votes;
}

const unordered_set<Candidate *> &Party::getCandidates() const
{
    return *candidates;
}

void Party::addCandidate(Candidate &candidate)
{
    candidates->insert(&candidate);
    votes += candidate.getVotes();
    candidate.setParty(*this);
}

bool Party::compare(const Party *a, const Party *b)
{
    return (a != b) && a->getVotes() > b->getVotes();
}
