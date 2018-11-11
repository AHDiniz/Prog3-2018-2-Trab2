/**
 * Prog3-2018-2-Trab2: Reading a CSV file with data about Brazilian elections in C++
 *
 * Alan Herculano Diniz
 * Rafael Belmock Pedruzzi
 *
 * candidate.cpp: candidate class implementation file
 */

#include "../include/candidate.h"

const string &Candidate::getName() const
{
    return name;
}

void Candidate::setName(const string &name)
{
    this->name = name;
}

const Party &Candidate::getParty() const
{
    return party;
}

void Candidate::setParty(const Party &party)
{
    this->party = party;
}

const int Candidate::getVotes() const
{
    return votes;
}

void Candidate::setVotes(const int votes)
{
    this->votes = votes;
}

const string &Candidate::getPercent() const
{
    return percent;
}

void Candidate::setPercent(const string &percent)
{
    this->percent = percent;
}

const bool Candidate::getElected() const
{
    return elected;
}

void Candidate::setElected(const bool elected)
{
    this->elected = elected;
}
