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

int main(int argc, char const *argv[])
{
    // Currently only tests:

    Coalition coalition1;

    coalition1.addCandidate("Alan Herculano Diniz", "PQP", 100, "0.3", true);
    coalition1.addCandidate("Rafael Belmock Pedruzzi", "PQP", 99, "0.3", true);
    coalition1.addCandidate("José Ninguém da Silva Pinto", "PQP", 98, "0", false);
    coalition1.addCandidate("Fulano Borges Terceiro", "PNSC", 100, "0.3", true);
    coalition1.addCandidate("Sicrano Pessoa Matos", "PNSC", 99, "0.3", true);
    coalition1.addCandidate("Beltrano Não Sei das Quantas", "PNSC", 98, "0", false);

    std::cout << coalition1.getParties().size() << std::endl;

    return 0;
}

