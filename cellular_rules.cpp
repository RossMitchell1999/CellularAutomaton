//Ross Mitchell
//Cellular Automiton
#include <iostream>
#include <fstream>
using namespace std;

int array[31]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int newLine[31] = {};
int rules[8] = {0,0,0,1,1,0,1,0};

void getLine();
int firstItem(int i);
int lastItem(int i);
int rule(int i);

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 15; ++i)
	{	

		getLine();
		for ( int i = 0; i < sizeof(array)/sizeof(array[0]); ++i)
		{
			 std::cout<<array[i];
			 if (writeToFile == true) {
				//string input;
				//cout << "Enter line to be written to file: ";
				//cin >> input;
				ofstream myfile;
				myfile.open("CellularAutomatonOutput.txt");
				myfile << array[i];

			}
			 array[i]=newLine[i];
		}
		std::cout<<"\n";

	}
	return 0;
}

void getLine()
{
	int value = 0;
	for (int i = 0; i < sizeof(array)/sizeof(array[0]); ++i){
		if (i == 0)
		{
			value = firstItem(i);
		}
		else if (i == sizeof(array))
		{
		value = lastItem(i);
		}else{
			value = rule(i);
		}
		newLine[i] = value;
	}
}

int firstItem(int i){
	if (array[(sizeof(array)/sizeof(array[0]))-1] == 0 && array[0] == 0 && array[i+1] == 0)
	{
		if(rules[7]==0){
			return 0;
		}else{
			return 1;
		}

	}else if (array[(sizeof(array)/sizeof(array[0]))-1] == 0 && array[0] == 0 && array[i+1] == 1)
	{
		if(rules[6]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[(sizeof(array)/sizeof(array[0]))-1] == 0 && array[0] == 1 && array[i+1] == 0)
	{
		if(rules[5]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[(sizeof(array)/sizeof(array[0]))-1] == 0 && array[0] == 1 && array[i+1] == 1)
	{
		if(rules[4]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[(sizeof(array)/sizeof(array[0]))-1] == 1 && array[0] == 0 && array[i+1] == 0)
	{
		if(rules[3]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[(sizeof(array)/sizeof(array[0]))-1] == 1 && array[0] == 0 && array[i+1] == 1)
	{
		if(rules[2]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[(sizeof(array)/sizeof(array[0]))-1] == 1 && array[0] == 1 && array[i+1] == 0)
	{
		if(rules[1]==0){
			return 0;
		}else{
			return 1;
		}
	}else{
		if(rules[0]==0){
			return 0;
		}else{
			return 1;
		}
	}		
}

int lastItem(int i){
	if (array[i-1] == 0 && array[i] == 0 && array[0] == 0)
	{
		if(rules[7]==0){
			return 0;
		}else{
			return 1;
		}

	}else if (array[i-1] == 0 && array[i] == 0 && array[0] == 1)
	{
		if(rules[6]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[i-1] == 0 && array[i] == 1 && array[0] == 0)
	{
		if(rules[5]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[i-1] == 0 && array[i] == 1 && array[0] == 1)
	{
		if(rules[4]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[i-1] == 1 && array[i] == 0 && array[0] == 0)
	{
		if(rules[3]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[i-1] == 1 && array[i] == 0 && array[0] == 1)
	{
		if(rules[2]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[i-1] == 1 && array[i] == 1 && array[0] == 0)
	{
		if(rules[1]==0){
			return 0;
		}else{
			return 1;
		}
	}else{
		if(rules[0]==0){
			return 0;
		}else{
			return 1;
		}
	}	
}

int rule(int i){
	if (array[i-1] == 0 && array[i] == 0 && array[i+1] == 0)
	{
		if(rules[7]==0){
			return 0;
		}else{
			return 1;
		}

	}else if (array[i-1] == 0 && array[i] == 0 && array[i+1] == 1)
	{
		if(rules[6]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[i-1] == 0 && array[i] == 1 && array[i+1] == 0)
	{
		if(rules[5]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[i-1] == 0 && array[i] == 1 && array[i+1] == 1)
	{
		if(rules[4]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[i-1] == 1 && array[i] == 0 && array[i+1] == 0)
	{
		if(rules[3]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[i-1] == 1 && array[i] == 0 && array[i+1] == 1)
	{
		if(rules[2]==0){
			return 0;
		}else{
			return 1;
		}
	}else if (array[i-1] == 1 && array[i] == 1 && array[i+1] == 0)
	{
		if(rules[1]==0){
			return 0;
		}else{
			return 1;
		}
	}else{
		if(rules[0]==0){
			return 0;
		}else{
			return 1;
		}
	}
	
}
