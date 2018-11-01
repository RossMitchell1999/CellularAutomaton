//Ross Mitchell
//Cellular Automiton
#include <iostream>

int array[10]= {0,1,0,0,0,1,1,1,0,1};
int newLine[10] = {};

void getLine();
int firstItem(int i);
int lastItem(int i);
int rules(int i);

int main(int argc, char const *argv[])
{
	getLine();
	for ( int i = 0; i < sizeof(array)/sizeof(array[0]); ++i)
	{
		 std::cout<<newLine[i];
	}
	return 0;
}

void getLine()
{
	int value = 0;
	for (int i = 0; i < sizeof(array)/sizeof(array[0]); ++i){
		if (i == 0)
		{
			value = firstItem (i);
		}
		else if (i == sizeof(array))
		{
		value = lastItem (i);
		}else{
			value = rules (i);
		}
		newLine[i] = value;
	}
}

int firstItem(int i){
	if (array[i] == 0)
	{
		if (((array[(sizeof(array)/sizeof(array[0]))-1] == 0) && (array[i+1] == 0)) || ((array[(sizeof(array)/sizeof(array[0]))-1] == 1) && (array[i+1] == 1)))
		{
			std::cout<<"correct";
			return 0;
		}else{
			std::cout<<sizeof(array)-1;
			std::cout<<array[(sizeof(array)/sizeof(array[0]))-1];
			std::cout<<array[i+1];
			std::cout<<"wrong";
			return 1;
		}
	}else{
		if ((array[(sizeof(array)/sizeof(array[0]))-1] == 1 && array[i+1] == 1) || (array[(sizeof(array)/sizeof(array[0]))-1] == 1 && array[i+1] == 0))
		{
			return 0;
		}else{
			return 1;
		}
	}	
}

int lastItem(int i){
	if (array[i] == 0)
	{
		if ((array[i-1] == 0 && array[0] == 0) || (array[i-1] == 1 && array[0] == 1))
		{
			return 0;
		}else{
			return 1;
		}
	}else{
		if ((array[i-1] == 1 && array[0] == 1) || (array[i-1] == 1 && array[0] == 0))
		{
			return 0;
		}else{
			return 1;
		}
	}	
}

int rules(int i){
	if (array[i] == 0)
	{
		if ((array[i-1] == 0 && array[i+1] == 0) || (array[i-1] == 1 && array[i+1] == 1))
		{
			return 0;
		}else{
			return 1;
		}
	}else{
		if ((array[i-1] == 1 && array[i+1] == 1) || (array[i-1] == 1 && array[i+1] == 0))
		{
			return 0;
		}else{
			return 1;
		}
	}
}