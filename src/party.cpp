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

Party::Party(const string &name, const string &coalition)
{
    this->name = name;
    this->coalition = coalition;
}

const string &Party::getCoalition() const
{
    return this->coalition;
}

void Party::setCoalition(const string &coalition)
{
    this->coalition = coalition;
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

const set<Candidate *> &Party::getCandidates() const
{
    return candidates;
}

void Party::addCandidate(Candidate &candidate)
{
    candidates.insert(&candidate);
    votes += candidate.getVotes;
    candidate.setParty(*this);
}
