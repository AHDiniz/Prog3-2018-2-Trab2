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

Election::Election(map<string, Coalition *> *coalitions, const unsigned vacancies)
{
    this->coalitions = coalitions;  // Setting coalitions set.
    this->vacancies = vacancies;    // Setting number of vacancies.

    // Copying each candidate to the mostVoted vector:
    for (map<string, Coalition *>::iterator coIt = coalitions->begin(); coIt != coalitions->end(); coIt++)
    {
        for (const Party *p : coIt->second->getParties())
        {
            for (Candidate *c : p->getCandidates())
            {
                mostVoted.push_back(c);
            }
        }
    }
    // Sorting mostVoted:
    sort(mostVoted.begin(), mostVoted.end(), Candidate::compare);
}

Election::~Election()
{
    // Deleting each candidate:
    for (Candidate *c : mostVoted)
    {
        delete c;
    }

    // Deleting each party and coalition:
    for (map<string, Coalition *>::iterator coIt = coalitions->begin(); coIt != coalitions->end(); coIt++)
    {
        for (const Party *p : coIt->second->getParties())
        {
            delete p;
        }
        delete coIt->second;
    }
    // Deleting coalitions set:
    delete coalitions;
}

string Election::numberOfVacancies() const
{
    stringstream ret;
    ret << "Número de vagas: " << vacancies << endl;
    return ret.str();
}

string Election::electedCandidates() const
{
    stringstream ret;
    ret << "Vereadores eleitos:" << endl;

    unsigned i = 0;
    for (Candidate *c : mostVoted)
    {
        if (i == vacancies)
            break;
        if (c->getElected())
            ret << ++i << " - " << c->toString() << endl;
    }

    return ret.str();
}

string Election::mostVotedCandidates() const
{
    stringstream ret;
    ret << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;

    unsigned i = 1;
    for (Candidate *c : mostVoted)
    {
        ret << i++ << " - " << c->toString() << endl;
        if (i > vacancies)
            break;
    }
    return ret.str();
}

string Election::electedByMajority() const
{
    stringstream ret;
    ret << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl;
    ret << "(com sua posição no ranking de mais votados)" << endl;

    unsigned i = 0;
    for (Candidate *c : mostVoted)
    {
        if (i == vacancies)
            break;
        if (!c->getElected())
        {
            ret << ++i << " - " << c->toString() << endl;
        }
    }

    return ret.str();
}

string Election::electedByProportion() const
{
    stringstream ret;
    ret << "Eleitos, que se beneficiaram do sistema proporcional:" << endl;
    ret << "(com sua posição no ranking de mais votados)" << endl;

    unsigned i = 1;
    for (Candidate *c : mostVoted)
    {
        if (c->getElected() && i > vacancies)
        {
            ret << i << " - " << c->toString() << endl;
        }
        i++;
    }

    return ret.str();
}

string Election::votesByCoalition() const
{
    stringstream ret;
    ret << "Votação (nominal) das coligações e número de candidatos eleitos:" << endl;

    vector<Coalition *> cList;

    for (map<string, Coalition *>::iterator it = coalitions->begin(); it != coalitions->end(); it++)
    {
        cList.push_back(it->second);
    }

    sort(cList.begin(), cList.end(), Coalition::compare);

    unsigned i = 0;
    for (Coalition *c : cList)
    {
        ret << ++i << " - Coligação: ";

        ret << c->getName() << ", " << c->getVotes() << " votos, ";

        int e = 0; // Elected candidates counter
        for (Party *party : c->getParties())
            for (Candidate *candidate : party->getCandidates())
                if (candidate->getElected())
                    e++;
        string s = (e >= 2) ? " candidatos eleitos" : " candidato eleito";
        ret << e << s << endl;
    }

    return ret.str();
}

string Election::votesByParty() const
{
    stringstream ret;
    ret << "Votação (nominal) dos partidos e número de candidatos eleitos:" << endl;

    vector<Party *> pList;

    for (map<string, Coalition *>::iterator it = coalitions->begin(); it != coalitions->end(); it++)
    {
        for (Party *party : it->second->getParties())
        {
            pList.push_back(party);
        }
    }

    sort(pList.begin(), pList.end(), Party::compare);

    int amountOfParties = 1;
    for (Party *party : pList)
    {
        ret << amountOfParties++ << " " << party->getName() << ", " << party->getVotes() << " votos, ";
        int e = 0;
        for (Candidate *candidate : party->getCandidates())
            if (candidate->getElected())
                ++e;
        string s = (e >= 2) ? " candidatos eleitos" : " candidato eleito";
        ret << e << s << endl;
    }

    return ret.str();
}

int Election::amountOfVotes() const
{
    int votes = 0;

    for (map<string, Coalition *>::iterator it = coalitions->begin(); it != coalitions->end(); it++)
    {
        votes += it->second->getVotes();
    }

    return votes;
}
