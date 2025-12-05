#include "Day03.h"

// result : 
// 
void Day_03_Part_2()
{
	vector<string> inputLines = ReadInputFile(3, 0);
	long long result = 0;


	println("Result : " + to_string(result));
}

// result : 
// 17147 too low
void Day_03_Part_1()
{
	vector<string> inputLines = ReadInputFile(3, 1);
	long long result = 0;
	int bat1 = 0;
	int bat2 = 0;
	int progress = 0;
	for (string line:inputLines)
	{
		bat1 = bat2 = 0;
		for (char c : line)
		{
			int bat = c - '0';
			if (bat > bat1 && c != line[line.length() - 1])
			{
				bat1 = bat;
				bat2 = 0;
			}
			else if (bat > bat2)
				bat2 = bat;
		}
		int jolt = bat1 * 10 + bat2;
		result += jolt;
		progress++;
		UpdateProgress(progress, inputLines.size(), to_string(jolt));
	}

	println("Result : " + to_string(result));
}
