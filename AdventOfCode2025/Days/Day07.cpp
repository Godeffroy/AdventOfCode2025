#include "Day07.h"

// result :
// 3098 too low
// 2292676794 too low
// 9897897326778
void Day_07_Part_2()
{
	vector<string> inputLines = ReadInputFile(7, 1);
	long long result = 0;
	vector<vector<long long >> time(inputLines.size(), vector<long long >(inputLines[0].size(), 0));
	println(inputLines[0]);
	int start = inputLines[0].find_first_of('S');
	inputLines[1][start] = '|';
	time[1][start]++;
	for (size_t lineNum = 1; lineNum < inputLines.size(); lineNum++)
	{
		println(inputLines[lineNum]);
		
		for (size_t charNum = 0; charNum < inputLines[lineNum].size(); charNum++)
		{
			if(time[lineNum][charNum]!=0)
				print(time[lineNum][charNum]);
			else
				print(" ");
			if (inputLines[lineNum - 1][charNum] == '|')
			{
				if (inputLines[lineNum][charNum] == '^')
				{
					inputLines[lineNum + 1][charNum - 1] = '|';
					inputLines[lineNum + 1][charNum + 1] = '|';
					time[lineNum + 1][charNum - 1] += time[lineNum - 1][charNum];
					time[lineNum + 1][charNum + 1] += time[lineNum - 1][charNum];
				}
				else
				{
					inputLines[lineNum + 1][charNum] = '|';
					time[lineNum + 1][charNum] += time[lineNum - 1][charNum];
				}
			}
		}
		println(' ');
	}
	for (auto& t : time.back())
		result += t;
	println("---");
	println("Result : " + to_string(result));
}


// result :
// 1550
void Day_07_Part_1()
{
	vector<string> inputLines = ReadInputFile(7, 1);
	long long result = 0;

	println(inputLines[0]);
	int start = inputLines[0].find_first_of('S');
	inputLines[1][start] = '|';
	for (size_t lineNum = 1; lineNum < inputLines.size(); lineNum++)
	{
		println(inputLines[lineNum]);
		for (size_t charNum = 0; charNum < inputLines[lineNum].size(); charNum++)
		{
			if(inputLines[lineNum - 1][charNum] == '|')
			{
				if(inputLines[lineNum][charNum] == '^')
				{
					inputLines[lineNum + 1][charNum - 1] = '|';
					inputLines[lineNum + 1][charNum + 1] = '|';
					result++;
				}
				else
					inputLines[lineNum + 1][charNum] = '|';
			}
		}

	}

	println("---");
	println("Result : " + to_string(result));
}