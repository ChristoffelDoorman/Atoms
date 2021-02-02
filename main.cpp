/*
 * Filename: main.cpp
 * Author: Christoffel Doorman (10580557)
 * Language: C++ (version C++11)
 * Purpose: This file contains the main function that reads in molecular
 *  data from a .pdb file and stores each atom as a structure in a list. This
 *  list is then written to an outfile of .pdb format. It then asks for user
 *  input to print out all atoms with a certain atom name, and then asks for
 *  user input to print out all atoms of a certain element. The main function
 *  also calls a function that calculates the center of mass and the inertia
 *  matrix of the atom list.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include "Atom.h"
#include "Com.h"
#include "AtomList.h"
#include "InertialMatrix.h"


int main() {

    // open .pdb file in read mode
    std::ifstream infile;
    infile.open("../1AON.pdb");

    // check if file has opened correctly, if not return 1
    if (!infile) {
        std::cerr << "Error while opening the file." << std::endl;
        return 1;
    }

    // store data in vector
    std::string line; // store each line temporary as a string
    std::vector<std::string> lines; // vector for holding all lines in the file
    int listLength = 0; // number of atoms in infile

    // read file line by line and store lines in vector until end of file
    while (std::getline(infile, line)) {
        if ((line.rfind("ATOM", 0) == 0) || (line.rfind("HETATM", 0) == 0)) { // only parse ATOM and HETATM
            lines.push_back(line); // save line in vector
            ++listLength;
        }
    }

    // create a list for atoms
    AtomList atomList;
    atomList.makeAtomList(lines, listLength);

    // close the opened file.
    infile.close();

    // print all atom types of user's choice
    std::string atomType;
    std::cout << "Please enter an atom type to print out (other options: none, all): ";
    std::cin >> atomType;
    atomList.printAtomTypes(atomType);

    // print all elements of user's choice
    std::string element;
    std::cout << "Please enter an element to print out (options: C, N, O, none, all): ";
    std::cin >> element;
    atomList.printElement(element);

    // create pdb file to write atoms to
    std::ofstream myfile;
    myfile.open ("../MFI_outfile.pdb");

    // iterate through list of atoms and write to pdf file line by line
    for (int i=0; i<listLength; i++) {
        myfile << atomList.returnAtomList()[i].printAtom() << std::endl;
    }

    // close pdf file
    myfile.close();

    // create a center of mass class
    Com com;
    com.setValues(atomList.returnAtomList(), listLength);

    // print out the center of mass
    std::cout << "\nThe center of mass of the MFI structure:" << std::endl;
    com.printCom();

    // create a moment of inertial matrix class
    InertialMatrix inertMtrx;
    inertMtrx.setValues(atomList.returnAtomList(), listLength);

    // print out the moments of inertia matrix
    std::cout << "\nThe moments of inertia matrix in units kg A^2 is:" << std::endl;
    inertMtrx.printMatrix();

    return 0;
}