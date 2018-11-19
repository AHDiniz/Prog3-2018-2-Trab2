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
    coalition1.setName("");

    Party pqp("PQP", coalition1);
    Party pnsc("PNSC", coalition1);

    Candidate c1("Alan Herculano Diniz", pqp, 100, "0.3", true);
    Candidate c2("Rafael Belmock Pedruzzi", pnsc, 100, "0.3", true);

    coalition1.addCandidate(c1);
    coalition1.addCandidate(c2);

    std::cout << coalition1.toString() << std::endl;

    return 0;
}

