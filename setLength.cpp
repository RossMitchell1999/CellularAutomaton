#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int inputLength()
{
	string input = "";
	int value;
	while(true)
	{
		cout << "Enter the length of the first generation: " << endl;
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

int inputNoGenerations()
{
	string input = "";
	int value;
	while(true)
	{
		cout << "Enter the number of generations: " << endl;
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

int main()
{
	const int length = inputLength();
	int noGenerations = inputNoGenerations();
	//we might need to use a vector instead of an array
	//so we can declare it globally & then resize it
	return 0;
}