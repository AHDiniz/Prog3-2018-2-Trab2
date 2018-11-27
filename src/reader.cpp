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
    cout << "Path: " << filePath << endl << "Encoding: " << encoding << endl;

    map<string, Coalition *> *coalitions = new map<string, Coalition *>; // Map with all coalitions.
    bool elected;                                                        // Mark elected candidates.
    string aux, name, coalitionName, partyName, percent;                 // Auxiliar reading variables.
    int votes;                                                           // Vote counter.
    unsigned vacancies = 0;                                              // Number of vacancies.
    Coalition *coalition;                                                // Auxiliar variables.
    Party *party;
    Candidate *cand;
    ifstream in;

    cout << "Starting locale..." << endl;

    // setlocale(LC_ALL, "");
    aux = "pt_BR." + encoding;
    cout << "Aux = " << aux << endl;
    locale brasilLocale(aux);
    aux.clear();

    cout << "Abrindo arquivo..." << endl;

    in.open(filePath);
    //in.imbue(brasilLocale);
    getline(in, aux); // Skipping the header.

    // while (getline(in, aux))
    getline(in, aux);
    // {
    istringstream line(aux);
    line.imbue(brasilLocale);

    getline(line, aux, ';'); // Getting the identification number.
    if (aux.find("#"))       // Break the loop if the section of valid candidates end.
    {
        // break;
    }
    if (aux.find("*")) // Incrementing the number of vacancies if an elected candidate is found.
    {
        vacancies++;
        elected = true; // Marking the candidate as elected.
    }
    else // Else, marking candidate as non elected.
        elected = false;

    getline(line, aux, ';');  // Skipping the candidate's number.
    getline(line, name, ';'); // Getting the candidate's name.
    aux.clear();

    // getline(line, partyName, ';');
    // Reader::trim(partyName);

    getline(line, aux, ';'); // Getting party and coalition's name.

    std::size_t pos = aux.find("-");
    if (pos != string::npos)
    {
        stringstream pcstream(aux);
        pcstream >> partyName;
        pcstream >> coalitionName;  // Skipping '-'.
        getline(pcstream, coalitionName, ';');  // Getting coalition's name.
        // coalitionName = aux.substr(++pos); 
        Reader::trim(coalitionName);
    }
    else // If there's no coalition, both names will be seted as the party's name.
    {
        partyName = aux;
        coalitionName = partyName;
    }

    // line >> votes; // Getting the candidate's votes.
    // line.ignore(1, ';');
    getline(line, aux);
    istringstream vote(aux);
    vote.imbue(brasilLocale);
    vote >> votes;
    getline(line, percent); // Getting the candidate's percent of votes.

    cout << "Name: " << name << " Party: " << partyName << " Coalition: " << coalitionName << " Votes: " << votes << " Percent: " << percent << endl;

    // Getting / Setting the candidate's coalition:
    if (coalitions->find(coalitionName) == coalitions->end()) // Checking if the coalition already exists.
    {
        (*coalitions)[coalitionName] = new Coalition(); // If not, a new one is created.
        (*coalitions)[coalitionName]->setName(coalitionName);
    }
    coalition = coalitions->find(coalitionName)->second;

    // Getting / Setting the candidate's party:
    for (Party *p : coalition->getParties())
    {
        if (p->getName() == partyName) // Checking if the party already exists.
        {
            party = p;
            break;
        }
        else // If not, a new one is created.
        {
            party = new Party(partyName, *coalition);
            break;
        }
    }

    cand = new Candidate(name, *party, votes, percent, elected); // Creating this line candidate.

    coalition->addCandidate(*cand); // Adding the candidate to the coalition.
    // }
    return new Election(coalitions, vacancies);
}

inline void Reader::ltrim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
                return !std::isspace(ch);
            }));
}

inline void Reader::rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
                return !std::isspace(ch);
            })
                .base(),
            s.end());
}

inline void Reader::trim(std::string &s)
{
    ltrim(s);
    rtrim(s);
}
