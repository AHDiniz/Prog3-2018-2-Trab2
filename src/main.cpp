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
#include "../include/candidate.h"

int main(int argc, char const *argv[])
{
    Candidate c1;
    Candidate c2;
    Candidate c3;

    Party party("PQP", "PQP");

    c1.setName("Alan Herculano Diniz");
    c1.setVotes(100);
    c1.setElected(true);
    c1.setPercent("0.3");
    c1.setParty(party);

    c2.setName("Rafael Belmock Pedruzzi");
    c2.setVotes(100);
    c2.setElected(true);
    c2.setPercent("0.3");
    c2.setParty(party);

    c3.setName("José Ninguém da Silva Pinto");
    c3.setVotes(100);
    c3.setElected(true);
    c3.setPercent("0");
    c3.setParty(party);

    std::cout << c1.toString() << std::endl;
    std::cout << c2.toString() << std::endl;
    std::cout << c3.toString() << std::endl;

    return 0;
}

