/*
 * Filename: Atom.h
 * Author: Christoffel Doorman (10580557)
 * Language: C++ (version C++11)
 * Purpose: This file contains the class and member function declarations
 *  of the atoms.
 */

#ifndef ASSIGNMENT1_ATOM_H
#define ASSIGNMENT1_ATOM_H

#include <iostream>
#include <string.h>
#include <iomanip>
#include <sstream>

class Atom {
public:

    /* This function separates all different contents of an atom that
     *  are stored in a string and stores it in private members. */
    void setData(std::string line);

    /* This function returns the name of the atom in an MFI format. */
    std::string printAtomName();

    /* This function prints out all contents off the atom in the MFI format. */
    std::string printAtom();

    /* These functions manipulate data types to be returned in
     *  a string format. */
    std::string printReal(float, int, int);
    std::string printInteger(int, int);
    std::string printString(std::string, int);
    std::string printStringReverse(std::string, int);

    /* This function erases spaces in a string. */
    std::string eraseSpaces(std::string str);

    /* These functions return some properties of the atom. */
    std::string getAtomName();
    char getAltLoc();
    std::string getResName();
    char getChainID();
    char getInsertRes();
    std::string getElement();

    /* These functions return the x, y and z coordinates of the atom. */
    float getX();
    float getY();
    float getZ();

private:
    std::string _recordName, _atomName, _resName, _segId, _element, _Q;
    int _serialNumber, _resSeqNo;
    char _altLoc, _chainID, _insertRes;
    float _x, _y, _z, _occup, _temp;
};

#endif //ASSIGNMENT1_ATOM_H
