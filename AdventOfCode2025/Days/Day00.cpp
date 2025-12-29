#include "Day00.h"

// result :
// 
void Day_00_Part_2()
{
	vector<string> inputLines = ReadInputFile(0, 0);
	long long result = 0;
	long long progress = 0;

	UpdateProgress(progress++, inputLines.size(), to_string(result));

	println("Result : " + to_string(result));
}


// result :
// 
void Day_00_Part_1()
{
	vector<string> inputLines = ReadInputFile(0, 0);
	long long result = 0;
	long long progress = 0;

	UpdateProgress(progress++, inputLines.size(), to_string(result));

	println("Result : " + to_string(result));
}