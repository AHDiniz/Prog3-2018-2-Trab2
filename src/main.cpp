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
#include "../include/coalition.h"
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

    // Election *election = Reader::readFile(filepath, encoding);

    // delete election;

    // Currently only tests:

    string b = "BOLO";
    string pp = "PQP / PNSC";

    map<string, Coalition *> *coalitions = new map<string, Coalition *>();
    Coalition *temp, *temp2;

    // Coalition coalition1, coalition2;
    // coalition1.setName(pp);
    // coalition2.setName(b);

    // Testando um trecho de reader

    temp = Funcao(coalitions, pp);
    temp2 = Funcao(coalitions, b);

    Party pqp("PQP", *temp);
    Party pnsc("PNSC", *temp);
    Party bolo("BOLO", *temp2);

    Candidate c1("Alan Herculano Diniz", pqp, 100, "0.3", true);
    Candidate c2("Rafael Belmock Pedruzzi", pnsc, 100, "0.3", true);
    Candidate cenoura("Bolo de Cenoura", bolo, 350, "25%", false);

    temp->addCandidate(c1);
    temp->addCandidate(c2);
    temp2->addCandidate(cenoura);

    for (map<string, Coalition *>::iterator coIt = coalitions->begin(); coIt != coalitions->end(); coIt++)
    {
        cout << coIt->second->toString() << endl;
    }

    // cout << temp->toString() << endl;
    // cout << temp2->toString() << endl;

    // for (map<string, Coalition *>::iterator coIt = coalitions->begin(); coIt != coalitions->end(); coIt++)
    // {
    //     delete coIt->second;
    // }
    // delete coalitions;

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
