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
    // Testing the candidate class:

    std::string name;
    int votes;
    bool elected;
    Candidate candidate;

    std::cout << "Write the name of the candidate:" << std::endl;
    std::cin >> name;
    candidate.setName(name);

    std::cout << "Candidate's name: " << candidate.getName() << std::endl;

    return 0;
}

