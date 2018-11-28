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
#include "election.h"
#include "reader.h"

Coalition *Funcao(map<string, Coalition *> *coalitions, string s);

int main(int argc, char const *argv[])
{
    string filepath = argv[1], encoding;

    if (argc == 2)  // Setting encoding as UTF-8 if none was given.
        encoding = "UTF-8";
    else
        encoding = argv[2];

    Election *election = Reader::readFile(filepath, encoding);  // Creating a election object with the input file.

    cout << election->numberOfVacancies() << endl; // Printing the number of vacant positions.
    cout << election->electedCandidates() << endl; // Printing the elected candidates.
    cout << election->mostVotedCandidates() << endl; // Printing the most voted candidates.
    cout << election->electedByMajority() << endl; // Printing the candidates that would be elected by majority but weren't.
    cout << election->electedByProportion() << endl; // Printing the candidates elected by proportion that would't be elected by majority.
    cout << election->votesByCoalition() << endl; // Printing the amount of votes for every coalition.
    cout << election->votesByParty() << endl; // Printing the amount of votes for every party.
    cout << "Total de votos nominais: " << election->amountOfVotes() << endl; // Printing the total of nominal votes.

    delete election;

    return 0;
}
