/**
 * Prog3-2018-2-Trab2: Reading a CSV file with data about Brazilian elections in C++
 *
 * Alan Herculano Diniz
 * Rafael Belmock Pedruzzi
 *
 * candidate.cpp: candidate class implementation file
 */

#include "../include/candidate.h"

Candidate::Candidate(const string &name, Party &party, int votes, const string &percent, bool elected)
{
    this->setName(name);
    this->setParty(party);
    this->setVotes(votes);
    this->setPercent(percent);
    this->setElected(elected);
}

Candidate::Candidate(int v, const string p, bool e)
{
    this->setVotes(v);
    this->setPercent(p);
    this->setElected(e);
}

Candidate::Candidate(Candidate &c)
{
    this->setName(c.getName());
    this->setParty(c.getParty());
    this->setVotes(c.getVotes());
    this->setPercent(c.getPercent());
    this->setElected(c.getElected());
}

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
    return *party;
}

void Candidate::setParty(const Party &party)
{
    if(this->party != NULL)
    {
        delete this->party;
    }
    this->party = new Party(party);
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

string Candidate::toString()
{
    stringstream ret;
    ret << name << " (" << party->getName() << ", " << votes << " votos)";

    Party p = this->getParty;
    string c = p.getCoalition;
    if(p.getName() != c)
    {
        ret << " - Coligação: " << c;
    }

    return ret.str;
}

static bool compare(const Candidate &a, const Candidate &b)
{
    return a.getVotes() > b.getVotes();
}
