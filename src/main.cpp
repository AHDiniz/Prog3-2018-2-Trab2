/**
 * Prog3-2018-2-Trab2: Reading a CSV file with data about Brazilian elections in C++
 *
 * Alan Herculano Diniz
 * Rafael Belmock Pedruzzi
 *
 * main.cpp: program's entry point
 */

#include <iostream>
#include <string>
// #include "../include/coalition.h"
#include "../include/election.h"
#include "../include/reader.h"

Coalition *Funcao(map<string, Coalition *> *coalitions, string s);

int main(int argc, char const *argv[])
{
    string filepath = argv[1], encoding;

    if (argc == 2)
        encoding = "UTF-8";
    else
        encoding = argv[2];

    Election *election = Reader::readFile(filepath, encoding);

    // delete election;

    // Currently only tests:

    // string b = "BOLO";
    // string pp = "PQP / PNSC";

    // map<string, Coalition *> *coalitions = new map<string, Coalition *>();
    // Coalition *temp, *temp2;

    // Coalition coalition1, coalition2;
    // coalition1.setName(pp);
    // coalition2.setName(b);

    // Testando um trecho de reader

    // temp = Funcao(coalitions, pp);
    // temp2 = Funcao(coalitions, b);

    // Party *pqp = new Party("PQP", *temp);
    // Party *pnsc = new Party("PNSC", *temp);
    // Party *bolo = new Party("BOLO", *temp2);

    // Candidate *c1 = new Candidate("Alan Herculano Diniz", *pqp, 100, "0.3", true);
    // Candidate *c2 = new Candidate("Rafael Belmock Pedruzzi", *pnsc, 100, "0.3", true);
    // Candidate *cenoura = new Candidate("Bolo de Cenoura", *bolo, 350, "25%", false);

    // temp->addCandidate(*c1);
    // temp->addCandidate(*c2);
    // temp2->addCandidate(*cenoura);

    // for (map<string, Coalition *>::iterator coIt = coalitions->begin(); coIt != coalitions->end(); coIt++)
    // {
    //     cout << coIt->second->getName() << endl << coIt->second->toString() << endl;
    // }

    // Election *election = new Election(coalitions,2);

    cout << election->numberOfVacancies() << endl; // Printing the number of vacant positions
    cout << election->electedCandidates() << endl; // Printing the elected candidates
    cout << election->mostVotedCandidates() << endl; // Printing the most voted candidates
    cout << election->electedByMajority() << endl; // Printing the candidates that would be elected by majority but weren't
    cout << election->electedByProportion() << endl; // Printing the candidates elected by proportion that would't be elected by majority
    cout << election->votesByCoalition() << endl; // Printing the amount of votes for every coalition
    cout << election->votesByParty() << endl; // Printing the amount of votes for every party
    cout << "Total de votos nominais: " << election->amountOfVotes() << endl; // Printing the total of nominal votes

    // for (map<string, Coalition *>::iterator coIt = coalitions->begin(); coIt != coalitions->end(); coIt++)
    // {
    //     cout << coIt->second->toString() << endl;
    // }

    // cout << temp->toString() << endl;
    // cout << temp2->toString() << endl;

    // for (map<string, Coalition *>::iterator coIt = coalitions->begin(); coIt != coalitions->end(); coIt++)
    // {
    //     delete coIt->second;
    // }
    // delete coalitions;

    delete election;

    return 0;
}

Coalition *Funcao(map<string, Coalition *> *coalitions, string s)
{
    if (coalitions->find(s) == coalitions->end())
    {
        (*coalitions)[s] = new Coalition();
        (*coalitions)[s]->setName(s);
    }
    return coalitions->find(s)->second;
}
