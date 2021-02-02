/*
 * Filename: Com.h
 * Author: Christoffel Doorman (10580557)
 * Language: C++ (version C++11)
 * Purpose: This file contains the class and member functions of
 *  the structure's center of mass.
 */

#ifndef ASSIGNMENT1_COM_H
#define ASSIGNMENT1_COM_H

#include <iostream>
#include <math.h>
#include "Atom.h"

class Com {
public:
    /* Constructor that sets initial values to zero. */
    Com() : _x(0.0), _y(0.0), _z(0.0), _M(0.0) {}

    /* This function calculates and sets the values of the center of mass. */
    void setValues(Atom* atomList, int listLength);

    /* This function adds the mass-times-position to the private members. */
    void addMass(Atom atom, double mass);

    /* These functions print out the coordinates of the center of mass. */
    double printX();
    double printY();
    double printZ();

    /* This function prints out all coordinates of the center of mass. */
    void printCom();

private:
    double _x, _y, _z, _M;
};


#endif //ASSIGNMENT1_COM_H
