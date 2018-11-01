#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
using namespace std;

const int length = 4;
char binary[length];

int toDecimal(string binary)
{
	return stoi(binary, nullptr, 2);
}

std::string toBinary(int decimal)
{
	int r;
	string binary;
	while(decimal > 0)
	{
		r = decimal%2;
		binary = (r == 0 ? "0" : "1") + binary;
		decimal /= 2;
	}
	return binary;
}

void inputBinary()
{
	int count = 0;
	char x;
	while(count < length)
	{
		cout << "Enter a binary number with " << length - count << " digits: " << endl;
		cin >> x;
		if(x == '1' || x == '0')
		{
			binary[count] = x;
			count++;
		}
		
	}
}

void inputDecimal()
{
	int max = (1 << length) - 1;
	string input = "";
	int value;
	bool valid = 0;
	while(!valid)
	{
		cout << "Enter a number less than " << max << endl;
		getline(cin, input);
		stringstream ss(input);
		if(ss >> value)
		{
			if(value <= max && value > 0)
			{
				valid = 1;
				strcpy(binary, toBinary(value).c_str());
			}
		}
	}
}

int main( )
{
	//inputBinary();
	inputDecimal();
	cout << "Binary array: ";
	for (int i = 0; i < length; i++)
	{
		cout << binary[i];
	}
	cout << endl;

	//converting to decimal and back to binary
	int decimalV = toDecimal(binary);
	string binaryV = toBinary(decimalV);
	cout << "Decimal: " << decimalV << endl;
	cout << "Binary: " << binaryV << endl;

	return 0;
}
