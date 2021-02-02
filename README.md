# Atoms

I separated the code into a main function main.cpp four .cpp files containing classes:
•	Atom.cpp: this is the most extensive class. It contains all content of an atom, and member functions that can read in atoms from a string, print out the atom in a MFI format, etc.
•	AtomList.cpp: this is the class of the atom list. This has a private member where the list is stored.  The member functions can print out (a) specific atom(s) or element(s).
•	Com.cpp: this class contains, calculates and prints the center of mass.
•	InertialMatrix.cpp: this class contains, calculates and prints the moments of inertia matrix.

In order to test the program, the user is asked for input two times. The first time, the user can choose to print out all atoms of a certain atom name (e.g. CA, CB, NZ, N, etc) and how many there are of them. The user can also choose to print out all atoms, or none at all. 
The second time, the user can choose to print out all atoms of a certain element (e.g. C, N, O or S) and how many there are of them. Again, the user can also choose to print out all atoms or none at all.
After printing the atoms, the program computes the center of mass and the inertial matrix of the entire list, and prints them. It also writes all atoms to an outfile in the same format as the infile.

