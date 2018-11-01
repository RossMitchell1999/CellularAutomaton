//for a file write, I'll build an option in the menu to write to file.
//this will set a fileWrite bool to true and then run the program normally
//but will require an additional if statement in the getLine() method that will save to file.
//I've written a test method below and can implement this into the method 

#include <iostream>
#include <fstream>
using namespace std;
void fileWrite();

int main() {
	fileWrite();
}

void fileWrite() { //this can be implemented into the main() in cellular_rules.cpp
	if (writeToFile == true) {
		//string input;
		//cout << "Enter line to be written to file: ";
		//cin >> input;
		ofstream myfile;
		myfile.open("CellularAutomatonOutput.txt");
		myfile << array[i];

	}
}
