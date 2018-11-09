// Programação III - 2018 / 2 Trab-2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// party.h: party class implementations

#include <algorithm>

#include "../inc/party.h"

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
    candidate.setParty(*this);
}
