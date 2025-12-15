#include "Day06.h"

// result :
// 
void Day_06_Part_2()
{
	vector<string> inputLines = ReadInputFile(6, 0);
	long long result = 0;
	long long progress = 0;
	for (string line : inputLines)
	{
		UpdateProgress(progress++, inputLines.size(), line);
	}

	println("Result : " + to_string(result));
}


// result :
// 
void Day_06_Part_1()
{
	vector<string> inputLines = ReadInputFile(6, 0);
	long long result = 0;
	long long progress = 0;
	for (string line : inputLines)
	{
		UpdateProgress(progress++, inputLines.size(), line);
	}

	println("Result : " + to_string(result));
}