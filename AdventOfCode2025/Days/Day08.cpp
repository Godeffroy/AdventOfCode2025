#include "Day08.h"

// result :
// 
void Day_08_Part_2()
{
	vector<string> inputLines = ReadInputFile(8, 0);
	long long result = 0;
	long long progress = 0;

	for (string line : inputLines)
	{
		UpdateProgress(progress++, inputLines.size(), to_string(result));
	}
	println("Result : " + to_string(result));
}


// result :
// 
void Day_08_Part_1()
{
	vector<string> inputLines = ReadInputFile(8, 0);
	long long result = 0;
	long long progress = 0;

	for (string line : inputLines)
	{
		UpdateProgress(progress++, inputLines.size(), to_string(result));
	}
	println("Result : " + to_string(result));
}