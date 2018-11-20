/**
 * Prog3-2018-2-Trab2: Reading a CSV file with data about Brazilian elections in C++
 *
 * Alan Herculano Diniz
 * Rafael Belmock Pedruzzi
 *
 * reader.cpp: reader class implementation file
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <locale>
#include <cctype>
#include <algorithm>
#include <functional>

#include "../include/reader.h"

Election *Reader::readFile(const string filePath, const string encoding)
{
    map<string, Coalition *> coalitions; // Map with all coalitions
    bool elected;                                                                                                        // Mark elected candidates
    string aux, name, coalition, party, percent;                                                                         // Auxiliar reading variables
    int votes = 0;                                                                                                       // Vote counter
    int vacancies = 0;                                                                                                   // Number of elected candidates
    Coalition *temp;                                                                                                      // Auxiliar variable
    ifstream in;

    locale brLocale("pt_BR." + encoding);

    in.open(filePath);
    //in.imbue(brLocale);
    getline(in, aux); // Skipping the header

    while (getline(in, aux))
    {
        stringstream line(aux);
        line.imbue(brLocale);

        getline(line, aux, ';'); // Getting the identification number
        if (aux.find("#"))       // Break the loop if the section of valid candidates end
        {
            break;
        }
        if (aux.find("*")) // Incrementing the number of vacancies if an elected candidate is found
        {
            vacancies++;
            elected = true; // Marking the candidate as elected
        }
        else // Else, marking candidate as non elected
            elected = false;

        getline(line, aux, ';');  // Skipping the candidate's number
        getline(line, name, ';'); // Getting the candidate's name
        aux.clear();

        line >> party;  // Getting party
        trim(party);

        getline(line, aux, ';');    // Getting coalition, if there is one

        std::size_t pos = aux.find("-");
        if (pos != string::npos)
        {
            coalition = aux.substr(pos);
            trim(coalition);
        }
        else
        {
            coalition = party;
        }

        line >> votes; // Getting the candidate's votes
        line.ignore(1,';');
        getline(line, percent); // Getting the candidate's percent of votes

        temp = coalitions[coalition];   // Getting the coalition of the candidate. If it dont exists it will be automaticaly created with defaut constructor by operator[]
        if(temp->getName() != coalition)   // If true then a new coalition was created
        {
            coalitions[coalition]->setName(coalition);  // Setting coalition's name
        }

        coalitions[coalition]->addCandidate(name, party, votes, percent, elected); // Adding the line's candidate to the coalition
    }
    return new Election(&coalitions,vacancies);
}

static inline void ltrim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
                return !std::isspace(ch);
            }));
}

static inline void rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
                return !std::isspace(ch);
            })
                .base(),
            s.end());
}

static inline void trim(std::string &s)
{
    ltrim(s);
    rtrim(s);
}