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

Coalition *Funcao();
Candidate *Funcao2(Candidate &c);

int main(int argc, char const *argv[])
{
    // Currently only tests:

    string b = "BOLO";
    string pp = "PQP / PNSC";

    map<string, Coalition *> *coalitions = new map<string, Coalition *>();

    Coalition coalition1, coalition2;
    Coalition *temp = &coalition1, *temp2 = &coalition2;
    coalition1.setName(pp);
    coalition2.setName(b);

    // Testando um trecho de reader
    // temp = (*coalitions)[pp];
    // if(temp->getName() != pp)
    // {
    //     temp->setName(pp);
    // }

    // temp2 = (*coalitions)[b];
    // if(temp2->getName() != b)
    // {
    //     temp2->setName(b);
    // }

    Party pqp("PQP", coalition1);
    Party pnsc("PNSC", coalition1);
    Party bolo("BOLO", coalition2);

    Candidate c1("Alan Herculano Diniz", pqp, 100, "0.3", true);
    Candidate c2("Rafael Belmock Pedruzzi", pnsc, 100, "0.3", true);
    Candidate cenoura("Bolo de Cenoura", bolo, 350, "25%", false);

    temp->addCandidate(c1);
    temp->addCandidate(c2);
    temp2->addCandidate(cenoura);


    // for (map<string, Coalition *>::iterator coIt = coalitions->begin(); coIt != coalitions->end(); coIt++)
    // {
    //     cout << coIt->second->toString() << endl;
    // }

    cout << temp->toString() << endl;
    cout << temp2->toString() << endl;

    delete coalitions;

    return 0;
}

Coalition *Funcao()
{
    Coalition *coalition3 = new Coalition();
    coalition3->setName("ALIEN");

    Party *alien = new Party("ALIEN", *coalition3);

    Candidate *c3 = new Candidate("Josi Mar", *alien, 100, "0.3", true);

    coalition3->addCandidate(*c3);

    return coalition3;
}

Candidate *Funcao2(Candidate &c)
{
    Candidate *cand = new Candidate(c);
    return cand;
}

