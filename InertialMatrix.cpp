/*
 * Filename: InertialMatrix.cpp
 * Author: Christoffel Doorman (10580557)
 * Language: C++ (version C++11)
 * Purpose: This file contains all member functions that are related to the
 *  calculation of the inertial matrix of atom structure.
 */

#include "InertialMatrix.h"

#define CMASS (1.99 * pow(10, -26))
#define NMASS (2.325 * pow(10, -26))
#define OMASS (2.657 * pow(10, -26))
#define SMASS (5.325 * pow(10, -26))

/* This function calculates and sets all values of the matix. */
void InertialMatrix::setValues(Atom* atomList, int listLength) {
    for (int i = 0; i < listLength; i++) {
        if (atomList[i].getElement() == "C") { InertialMatrix::addMoment(atomList[i], CMASS); }
        else if (atomList[i].getElement() == "N") { InertialMatrix::addMoment(atomList[i], NMASS); }
        else if (atomList[i].getElement() == "O") { InertialMatrix::addMoment(atomList[i], OMASS); }
        else if (atomList[i].getElement() == "S") { InertialMatrix::addMoment(atomList[i], SMASS); }
    }
}

/* This function calculates all elements of the inertial matrix. */
void InertialMatrix::addMoment(Atom atom, double mass) {
    _a11 += mass * (pow(atom.getY(), 2) + pow(atom.getZ(), 2));
    _a12 -= mass * atom.getX() * atom.getY();
    _a13 -= mass * atom.getX() * atom.getZ();;
    _a21 -= mass * atom.getY() * atom.getX();;
    _a22 += mass * (pow(atom.getZ(), 2) + pow(atom.getX(), 2));;
    _a23 -= mass * atom.getY() * atom.getZ();;
    _a31 -= mass * atom.getZ() * atom.getX();;
    _a32 -= mass * atom.getZ() * atom.getY();;
    _a33 += mass * (pow(atom.getX(), 2) + pow(atom.getY(), 2));;
}

/* This function prints the inertial matrix in a matrix format. */
void InertialMatrix::printMatrix() {
    std::cout << "[[" << _a11 << ", " << _a12 << ", " << _a13 << "],\n[[" <<
        _a21 << ", " << _a22 << ", " << _a23 << "],\n[[" <<
        _a31 << ", " << _a32 << ", " << _a33 << "]]" << std::endl;
}