/*
 * Filename: Atom.cpp
 * Author: Christoffel Doorman (10580557)
 * Language: C++ (version C++11)
 * Purpose: This file contains all member functions that are related to the atoms.
 */


#include "Atom.h"

/* This function seperates all different contents of an atom that
 *  are stored in a string and stores it in private members. */
void Atom::setData(std::string line) {
    _recordName = Atom::eraseSpaces(line.substr(0, 6));
    _serialNumber = stoi(line.substr(6, 5));
    _atomName = Atom::eraseSpaces(line.substr(12, 4));
    _altLoc = line[16];
    _resName = Atom::eraseSpaces(line.substr(17, 3));
    _chainID = line[21];
    _resSeqNo = stoi(line.substr(22, 4));
    _insertRes = line[26];
    _x = stof(line.substr(30, 8));
    _y = stof(line.substr(38, 8));
    _z = stof(line.substr(46, 8));
    _occup = stof(line.substr(54, 6));
    _temp = stof(line.substr(60, 6));
    _segId = Atom::eraseSpaces(line.substr(72, 4));
    _element = Atom::eraseSpaces(line.substr(76, 2));
    _Q = Atom::eraseSpaces(line.substr(78, 2));
}

/* This function prints the name of the atom. */
std::string Atom::getAtomName() { return _atomName; }

/* These functions return some properties of the atom. */
char Atom::getAltLoc() { return _altLoc; }
std::string Atom::getResName() { return _resName; }
char Atom::getChainID() { return _chainID; }
char Atom::getInsertRes() { return _insertRes; }

/* These functions return the x, y and z coordinates of the atom. */
float Atom::getX() { return _x; }
float Atom::getY() { return _y; }
float Atom::getZ() { return _z; }
std::string Atom::getElement() { return _element; }

/* This function returns the name of the atom in a MFI format. */
std::string Atom::printAtomName() {
    std::string output(4, ' ');
    for (int i=1; i<_atomName.length()+1; i++) { output[i] = _atomName[i-1]; }
    return output;
}


/* This function fills a string of spaces with a given string
 *  in order to return a MFI format. */
std::string Atom::printString(std::string name, int length) {
    std::string output(length, ' ');
    for (int i=0; i<name.length(); i++) { output[i] = name[i]; }
    return output;
}

/* This function returns a given string from left to right
 *  in order to return a MFI format. */
std::string Atom::printStringReverse(std::string name, int length) {
    std::string output(length, ' ');
    for (int i=name.length()-1, j=length-1; i>=0; i--, j--) { output[j] = name[i]; }
    return output;
}

/* This function returns a given integer as a string in a MFI format. */
std::string Atom::printInteger(int value, int length) {
    std::string output(length, ' ');
    std::string str = std::to_string(value);
    for (int i=str.length()-1, j=length-1; i>=0; i--, j--) { output[j] = str[i]; }
    return output;
}

/* This function returns a given float as a string in a MFI format, with
 *  a given precision. */
std::string Atom::printReal(float coordinate, int length, int precision) {
    std::string output(length, ' ');
    std::stringstream stream;
    stream << std::fixed << std::setprecision(precision) << coordinate;
    std::string str = stream.str();
    for (int i=str.length()-1, j=length-1; i>=0; i--, j--) { output[j] = str[i]; }
    return output;
}

/* This function prints out all contents off the atom in the MFI format. */
std::string Atom::printAtom() {
    std::stringstream stream;
    stream << Atom::printString(_recordName, 6) << Atom::printInteger(_serialNumber, 5) << " " << printAtomName() <<
        getAltLoc() << getResName() << " " << getChainID() << Atom::printInteger(_resSeqNo, 4) <<
        getInsertRes() << "   " << Atom::printReal(_x, 8, 3) << Atom::printReal(_y, 8, 3) << Atom::printReal(_z, 8, 3) <<
        Atom::printReal(_occup, 6, 2) << Atom::printReal(_temp, 6, 2) << "      " << Atom::printString(_segId, 4) <<
        Atom::printStringReverse(_element, 2) << Atom::printString(_Q, 2);

    return stream.str();
}

/* This function erases spaces in a string. */
std::string Atom::eraseSpaces(std::string str) {
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    return str;
}