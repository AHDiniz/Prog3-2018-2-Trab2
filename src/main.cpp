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

Coalition &Funcao();
Candidate *Funcao2(Candidate &c);

int main(int argc, char const *argv[])
{
    // Currently only tests:

    Coalition coalition1, coalition2;
    coalition1.setName("PQP / PNSC");
    coalition2.setName("BOLO");

    Party pqp("PQP", coalition1);
    Party pnsc("PNSC", coalition1);
    Party bolo("BOLO", coalition2);

    Candidate c1("Alan Herculano Diniz", pqp, 100, "0.3", true);
    Candidate c2("Rafael Belmock Pedruzzi", pnsc, 100, "0.3", true);
    Candidate cenoura("Bolo de Cenoura", bolo, 350, "25%", false);

    coalition1.addCandidate(c1);
    coalition1.addCandidate(c2);
    coalition2.addCandidate(cenoura);

    std::cout << coalition1.toString() << std::endl;
    cout << coalition2.toString() << endl;

    // Teste de criação de classe em uma função:
    // Coalition coAlien = Funcao();
    // cout << coAlien.toString() << endl;

    Candidate *cAlien = Funcao2(c1);
    cout << cAlien->toString() << endl;

    return 0;
}

Coalition &Funcao()
{
    Coalition coalition3;
    coalition3.setName("ALIEN");

    Party alien("ALIEN", coalition3);

    Candidate c3("Josi Mar", alien, 100, "0.3", true);

    coalition3.addCandidate(c3);

    return coalition3;
}

Candidate *Funcao2(Candidate &c)
{
    Candidate *cand = new Candidate(c);
    return cand;
}

