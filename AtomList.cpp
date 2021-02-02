/*
 * Filename: AtomList.cpp
 * Author: Christoffel Doorman (10580557)
 * Language: C++ (version C++11)
 * Purpose: This file contains all the member functions of the AtomList class
 *  that are related to the list of atoms.
 */


#include "AtomList.h"

/* This function makes a list from a vector of atoms and returns nothing */
void AtomList::makeAtomList(std::vector<std::string> lines, int listLength) {

    // allocate a list of atoms on the heap
    Atom* atomList = new Atom[lines.size()];

    // add atoms from the vector to a class in array
    for (int i=0; i<lines.size(); i++)
        atomList[i].setData(lines[i]);

    // set private member's value
    _atomList = atomList;
    _listLength = listLength;
}

/* This function returns the atom list which is a private member. */
Atom* AtomList::returnAtomList() { return _atomList; }

/* This function prints all atoms of a given atom type. It can
 *  also print out all atomtypes or none, dependend on users input. */
void AtomList::printAtomTypes(std::string atomType) {

    // if user enters none, do nothing
    if (atomType == "none") { return; }

    // if user enters all, print all atoms
    else if (atomType == "all") {
        for (int i=0; i<_listLength; i++) { std::cout << _atomList[i].printAtom() << std::endl; }
        std::cout << "Total number of atoms: " << _listLength << std::endl;
    }

    // if user enters an atom type, print only these atom types
    else {
        int atomCount = 0; // count number of atoms
        for (int i=0; i<_listLength; i++) {
            if (_atomList[i].getAtomName() == atomType) { // only print atom types of asked type
                std::cout << _atomList[i].printAtom() << std::endl;
                atomCount += 1;
            }
        }
        std::cout << "Number of " << atomType << " atoms: " << atomCount << std::endl;
    }
}

/* This function prints all atoms of a given element. It can
 *  also print out all elements or none, dependent on users input. */
void AtomList::printElement(std::string element) {

    // if user enters none, do nothing
    if (element == "none") { return; }

    // if user enters all, print all atoms
    else if (element == "all") {
        for (int i=0; i<_listLength; i++) { std::cout << _atomList[i].printAtom() << std::endl; }
        std::cout << "Total number of atoms: " << _listLength << std::endl;
    }

    // if user enters an atom type, print only these atom types
    else {
        int atomCount = 0; // count number of atoms
        for (int i=0; i<_listLength; i++) { // iterate through entire list
            if (_atomList[i].getElement() == element) {
                std::cout << _atomList[i].printAtom() << std::endl;
                atomCount += 1;
            }
        }
        std::cout << "Number of " << element << " atoms: " << atomCount << std::endl;
    }
}