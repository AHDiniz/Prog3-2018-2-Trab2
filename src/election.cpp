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

Election::Election(map<string, Coalition *> *coalitions, const int vacancies)
{
    this->coalitions = coalitions;
    this->vacancies = vacancies;

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
    sort(mostVoted.begin(), mostVoted.end(), Candidate::compare);
}

Election::~Election()
{
    for (Candidate *c : mostVoted)
    {
        delete c;
    }

    for (map<string, Coalition *>::iterator coIt = coalitions->begin(); coIt != coalitions->end(); coIt++)
    {
        for (const Party *p : coIt->second->getParties())
        {
            delete p;
        }
        delete coIt->second;
    }
    delete coalitions;
}

stringstream Election::numberOfVacancies() const
{
    stringstream ret;
    ret << "Número de vagas: " << vacancies;
    return ret;
}

stringstream Election::electedCandidates() const
{
    stringstream ret;
    ret << "Vereadores eleitos:" << endl;

    for (int i = 0; i < vacancies; i++)
    {
        Candidate *c = mostVoted.at(i);
        int p = i + 1;
        ret << p << " - " << c->toString() << endl;
    }

    return ret;
}

stringstream Election::mostVotedCandidates() const
{
    stringstream ret;
    ret << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;
    int i = 1;

    for (Candidate *c : mostVoted)
    {
        ret << i << " - " << c->toString() << endl;
        i++;
        if (i > vacancies)
            break;
    }
    return ret;
}

stringstream Election::electedByMajority() const
{
    stringstream ret;
    ret << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl;
    ret << "(com sua posição no ranking de mais votados)" << endl;

    for (int i = 0; i < vacancies; i++)
    {
        Candidate *c = mostVoted.at(i);
        if (!c->getElected())
        {
            int p = i + 1;
            ret << p << " - " << c->toString() << endl;
        }
    }

    return ret;
}

stringstream Election::electedByProportion() const
{
    stringstream ret;
    ret << "Eleitos, que se beneficiaram do sistema proporcional:" << endl;
    ret << "(com sua posição no ranking de mais votados)" << endl;

    for (int i = vacancies; i < mostVoted.size(); i++)
    {
        Candidate *c = mostVoted.at(i);
        if (c->getElected())
        {
            int p = i + 1;
            ret << p << " - " << c->toString() << endl;
        }
    }

    return ret;
}

stringstream Election::votesByCoalition() const
{
    stringstream ret;
    ret << "Votação (nominal) das coligações e número de candidatos eleitos:" << endl;

    vector<Coalition *> cList;

    for (map<string, Coalition *>::iterator it = coalitions->begin(); it != coalitions->end(); it++)
    {
        cList.push_back(it->second);
    }

    sort(cList.begin(), cList.end(), Coalition::compare);

    for (int i = 0; i < cList.size(); i++)
    {
        int p = i + 1;
        ret << p << " - Coligação: ";

        Coalition *c = cList.at(i);
        ret << c->getName() << ", " << c->getVotes() << " votos, ";

        int e = 0; // Elected candidates counter
        for (Party *party : c->getParties())
            for (Candidate *candidate : party->getCandidates())
                if (candidate->getElected())
                    e++;
        ret << (e >= 2) ? (e + " candidatos eleitos") : (e + " candidato eleito");
        ret << endl;
    }

    return ret;
}

stringstream Election::votesByParty() const
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
                e++;
        ret << (e >= 2) ? (e + " candidatos eleitos") : (e + " candidato eleito");
        ret << endl;
    }

    return ret;
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
