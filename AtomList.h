/*
 * Filename: AtomList.h
 * Author: Christoffel Doorman (10580557)
 * Language: C++ (version C++11)
 * Purpose: This file contains the AtomList class and member function.
 */

#ifndef ASSIGNMENT1_ATOMLIST_H
#define ASSIGNMENT1_ATOMLIST_H

#include <iostream>
#include <vector>
#include "Atom.h"

class AtomList {
public:

    /* This function makes a list from a vector of atoms and returns nothing */
    void makeAtomList(std::vector<std::string>, int);

    /* This function prints all atoms of a given atom type. It can
     *  also print out all atomtypes or none, dependend on users input. */
    void printAtomTypes(std::string);

    /* This function prints all atoms of a given element. It can
     *  also print out all elements or none, dependend on users input. */
    void printElement(std::string);

    /* This function returns the atom list which is a private member. */
    Atom* returnAtomList();

private:
    Atom* _atomList;
    int _listLength;
};


#endif //ASSIGNMENT1_ATOMLIST_H
