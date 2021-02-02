/*
 * Filename: InertialMatrix.h
 * Author: Christoffel Doorman (10580557)
 * Language: C++ (version C++11)
 * Purpose: This file contains the class and member functions of
 *  the inertial matrix.
 */

#ifndef ASSIGNMENT1_INERTIALMATRIX_H
#define ASSIGNMENT1_INERTIALMATRIX_H

#include <iostream>
#include <math.h>
#include "Atom.h"

/* This class contains all elements of an inertial matrix. */
class InertialMatrix {
public:

    /* Constructor sets elements at zero. */
    InertialMatrix() : _a11(0.0), _a12(0.0), _a13(0.0), _a21(0.0), _a22(0.0),
        _a23(0.0), _a31(0.0), _a32(0.0), _a33(0.0) {}

    /* This function calculates and sets all values of the matix. */
    void setValues(Atom* atomList, int listLength);

    /* This function calculates all elements of the inertial matrix. */
    void addMoment(Atom atom, double mass);

    /* This function prints the inertial matrix in a matrix format. */
    void printMatrix();

private:
    double _a11, _a12, _a13, _a21, _a22, _a23, _a31, _a32, _a33;
};


#endif //ASSIGNMENT1_INERTIALMATRIX_H
