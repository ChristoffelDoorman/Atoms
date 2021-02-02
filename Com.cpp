/*
 * Filename: Com.c
 * Author: Christoffel Doorman (10580557)
 * Language: C++ (version C++11)
 * Purpose: This file contains all member functions that are related to the
 *  calculation of the center of mass of atom structure.
 */


#include "Com.h"

#define CMASS (1.99 * pow(10, -26)) // mass of a carbon atom in kg
#define NMASS (2.325 * pow(10, -26)) // mass of a nitrogen atom in kg
#define OMASS (2.657 * pow(10, -26)) // mass of a oxygen atom in kg
#define SMASS (5.325 * pow(10, -26)) // mass of a sulfur atom in kg

/* This function calculates and sets the values of the center of mass. */
void Com::setValues(Atom* atomList, int listLength) {
    for (int i = 0; i < listLength; i++) { // iterate through entire list
        if (atomList[i].getElement() == "C") { Com::addMass(atomList[i], CMASS); }
        else if (atomList[i].getElement() == "N") { Com::addMass(atomList[i], NMASS); }
        else if (atomList[i].getElement() == "O") { Com::addMass(atomList[i], OMASS); }
        else if (atomList[i].getElement() == "S") { Com::addMass(atomList[i], SMASS); }
    }

    // devide sum by total mass
    _x /= _M;
    _y /= _M;
    _z /= _M;
}

/* This function adds the mass-times-position to the private members. */
void Com::addMass(Atom atom, double mass) {
    _x += mass * atom.getX();
    _y += mass * atom.getY();
    _z += mass * atom.getZ();
    _M += mass;
}

/* These functions print out the coordinates of the center of mass. */
double Com::printX() { return _x; } // x coordinate
double Com::printY() { return _y; } // y coordinate
double Com::printZ() { return _z; } // z coordinate

/* This function prints out all coordinates of the center of mass. */
void Com::printCom() {
    std::cout << "x-coordinate: " << printX() << " Angstrom\ny-coordinate: " << printY() <<
    " Angstrom\nz-coordinate: " << printZ() << " Angstrom" << std::endl;
}