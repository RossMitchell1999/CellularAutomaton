//Cellular Automaton
//Ross Mitchell, Nicole Orr, Christopher Carr

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;
int numRule;
string binRule;
int rules[8];
void menu();
void menu1();
void binCon();
int decCon(long long n);
void randomGenerateRule();
int * randomGenLine(int length);
int * getLine(int length, int array[]);
int firstItem(int i, int array[], int newLine[]);
int lastItem(int i, int array[], int newLine[]);
int rule(int i, int array[], int newLine[]);
int inputLength();
int inputNoGenerations();
void fileWrite(int array[], int length, string filename);


int main() {
	menu();
}

void menu(){
	int input = 0;
	while (input!=4){
		cout << "**** MAIN MENU ****\n";
		cout << "1. Run Cellular Automaton\n";
		cout << "2. Convert Binary number to Decimal\n";
		cout << "3. Convert Decimal number to Binary\n";
		cout << "4. Exit\n";
		cin >> input;
		if (input == 1){
			menu1();
		}else if (input==2)
		{
			long long n;
    		cout << "Enter a binary number: ";
    		cin >> n;
    		cout << n << " in binary = " << decCon(n) << "in decimal";
    		cout<<"\n";
		}else if (input==3)
		{
			binCon();
			for (int i = 0; i < 8; ++i)
			{
				cout<<rules[i];
			}
			cout<<"\n";
		}else{
			input = 4;
		}
	}
}

void menu1(){
	//Start of the menu
	int input;
	cout << "****** MENU ******\n";
	cout << "1. Run Cellular Automaton without saving to file\n";
	cout << "2. Run Cellular Automaton and save to file\n";
	cout << "3. Exit\n";

	cin >> input;
	//Option 1 means the file will not be saved
	if (input == 1)
	{
		int option;
		cout << "****************************\n";
		cout << "1. Randomly Generate Rule \n";
		cout << "2. Choose number for Rule\n";
		cin >> option;
		if(option==1){
			//This generates a random number
			randomGenerateRule();
		}else{
			//this receives their input and converts it to binary
			binCon();
		}
		//These find the width and number of generations the user wants
		const int length = inputLength();
		int noGenerations = inputNoGenerations();
		int* array= new int[length];
		array = randomGenLine(length);
		//this displays the first line of the array
		for (int i = 0; i < length; ++i)
		{
			cout<<array[i];
		}
		cout<<"\n";
		for (int i = 0; i < noGenerations; ++i)
		{	
			//this will generate a new line
			int *newLine = getLine(length, array);
			for ( int i = 0; i < length; ++i)
			{
				//this displays the array
				 std::cout<<newLine[i];
				 array[i]=newLine[i];
			}
			std::cout<<"\n";
		}	
	}else if (input == 2){
		//this is if the user doesnt want to save
		string n;
		cout << "What is the name of the file you would like to save to :";
		cin >> n;
		int option;
		cout << "****************************\n";
		cout << "1. Randomly Generate Rule \n";
		cout << "2. Choose number for Rule\n";
		cin >> option;
		if(option==1){
			//this randomly generates a rule
			randomGenerateRule();
		}else{
			//this converts their number to binary
			binCon();
		}
		//this gets the width and number of generations
		const int length = inputLength();
		int noGenerations = inputNoGenerations();
		int *array = randomGenLine(length);
		for (int i = 0; i < length; ++i)
		{
			//this displays the first line in the array
			cout<<array[i];
		}
		fileWrite(array, length, n);
		cout<<"\n";
		for (int i = 0; i < noGenerations; ++i)
		{	
			//this gets the new generation then displays it
			int *newLine = getLine(length, array);
			for ( int i = 0; i < length; ++i)
		{
			 std::cout<<newLine[i];
			 array[i]=newLine[i];
		}
		//this writes the output to a file
		fileWrite(newLine, length, n);
		std::cout<<"\n";

	}
	}else{

	}
}

int decCon(long long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

//this converts decimal to binary
void binCon(){
	int n = 0;
	cout << "What number of rule would you like? :";
	cin >> n;
	for(int i=0; n>0; i++)    
		{    
			//divides by 2 gets the remainder and keeps dividing
			rules[i]=n%2;    
			n= n/2;  
		}
}

void randomGenerateRule(){
	//this gets a random number and converts it to binary
	int num = rand() % 255 +1; 
	for(int i=0; num>0; i++)    
		{    
			rules[i]=num%2;    
			num= num/2;  
		}
}

//this creates a random first line for the user to generate
int * randomGenLine(int length){
	int* array = new int[length];
	int i;
	for (i = 0; i < length/2; ++i)
	{
		array[i]= 0;
	}
	array[i]=1;
	++i;
	for (i; i < (length); ++i)
	{
		array[i]=0;
	}
	return array;
}

//this establishes the width of the cellular automaton
int inputLength()
{
	string input = "";
	int value;
	while(true)
	{
		cout << "Enter the length of the first generation: (between 10 and 100)" << endl;
		getline(cin, input);
		stringstream ss(input);
		if(ss >> value)
		{
			if(value <= 100 && value >= 10)
			{
				return value;
			}
		}
	}
}

//this receives the number of generations the automaton will go on for
int inputNoGenerations()
{
	string input = "";
	int value;
	while(true)
	{
		cout << "Enter the number of generations: (between 10 and 100)" << endl;
		getline(cin, input);
		stringstream ss(input);
		if(ss >> value)
		{
			if(value <= 100 && value >= 10)
			{
				return value;
			}
		}
	}
}

//this will write the data to a file
void fileWrite(int array[], int length, string filename) { //this can be implemented into the main() in cellular_rules.cpp
		filename.append(".txt");
		fstream myfile;
		myfile.open(filename, fstream::app);
		for (int i = 0; i < (length); ++i)
		{
			myfile << array[i];
		}
		myfile << "\n";
		myfile.close();
}

//this will check the rules and create the next generation
int * getLine(int length, int array[])
{
	int value = 0;
	int* newLine=new int[length];
	for (int i = 0; i < length; ++i){
		if (i == 0)
		{
			value = firstItem(i, array, newLine);
		}
		else if (i == length)
		{
		value = lastItem(i, array, newLine);
		}else{
			value = rule(i, array, newLine);
		}
		newLine[i] = value;
	}
	return newLine;
}

//this is for the first item in the array
int firstItem(int i, int array[], int newLine[]){
	if (array[(sizeof(array)/sizeof(array[0]))-1] == 0 && array[0] == 0 && array[i+1] == 0)
	{
		if(rules[0]==0){
			return 0;
		}else{
			return 1;
		}

	}else if (array[(sizeof(array)/sizeof(array[0]))-1] == 0 && array[0] == 0 && array[i+1] == 1)
	{
		if(rules[1]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[(sizeof(array)/sizeof(array[0]))-1] == 0 && array[0] == 1 && array[i+1] == 0)
	{
		if(rules[2]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[(sizeof(array)/sizeof(array[0]))-1] == 0 && array[0] == 1 && array[i+1] == 1)
	{
		if(rules[3]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[(sizeof(array)/sizeof(array[0]))-1] == 1 && array[0] == 0 && array[i+1] == 0)
	{
		if(rules[4]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[(sizeof(array)/sizeof(array[0]))-1] == 1 && array[0] == 0 && array[i+1] == 1)
	{
		if(rules[5]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[(sizeof(array)/sizeof(array[0]))-1] == 1 && array[0] == 1 && array[i+1] == 0)
	{
		if(rules[6]==0){
			return 0;
		}else{
			return 1;
		}
	}else{
		if(rules[7]==0){
			return 0;
		}else{
			return 1;
		}
	}		
}

//this is for the last item in the array
int lastItem(int i, int array[], int newLine[]){
	if (array[i-1] == 0 && array[i] == 0 && array[0] == 0)
	{
		if(rules[0]==0){
			return 0;
		}else{
			return 1;
		}

	}else if (array[i-1] == 0 && array[i] == 0 && array[0] == 1)
	{
		if(rules[1]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[i-1] == 0 && array[i] == 1 && array[0] == 0)
	{
		if(rules[2]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[i-1] == 0 && array[i] == 1 && array[0] == 1)
	{
		if(rules[3]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[i-1] == 1 && array[i] == 0 && array[0] == 0)
	{
		if(rules[4]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[i-1] == 1 && array[i] == 0 && array[0] == 1)
	{
		if(rules[5]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[i-1] == 1 && array[i] == 1 && array[0] == 0)
	{
		if(rules[6]==0){
			return 0;
		}else{
			return 1;
		}
	}else{
		if(rules[7]==0){
			return 0;
		}else{
			return 1;
		}
	}	
}

//this applies the rules to the generations
int rule(int i, int array[], int newLine[]){
	if (array[i-1] == 0 && array[i] == 0 && array[i+1] == 0)
	{
		if(rules[0]==0){
			return 0;
		}else{
			return 1;
		}

	}else if (array[i-1] == 0 && array[i] == 0 && array[i+1] == 1)
	{
		if(rules[1]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[i-1] == 0 && array[i] == 1 && array[i+1] == 0)
	{
		if(rules[2]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[i-1] == 0 && array[i] == 1 && array[i+1] == 1)
	{
		if(rules[3]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[i-1] == 1 && array[i] == 0 && array[i+1] == 0)
	{
		if(rules[4]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[i-1] == 1 && array[i] == 0 && array[i+1] == 1)
	{
		if(rules[5]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[i-1] == 1 && array[i] == 1 && array[i+1] == 0)
	{
		if(rules[6]==0){
			return 0;
		}else{
			return 1;
		}
	}else{
		if(rules[7]==0){
			return 0;
		}else{
			return 1;
		}
	}
	
}