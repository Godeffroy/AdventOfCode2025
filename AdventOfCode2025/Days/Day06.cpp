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
// 6299564383938
void Day_06_Part_1()
{
	vector<string> inputLines = ReadInputFile(6, 1);
	long long result = 0;
	long long progress = 0;

	vector<vector<string>> problems;
	int cpt = 0;
	for (string line : inputLines)
	{
		problems.emplace_back();
		while (line.size() != 0)
		{
			if (line[0] == ' ')
			{
				line = line.substr(1);
				continue;
			}
			int sub = line.find(' ');
			if (sub == -1)
				sub = line.size();
			problems[cpt].push_back(line.substr(0, sub));
			line = line.substr(sub);
		}
		cpt++;
	}
	long long subResult = 0;
	for (size_t y = 0; y < problems.back().size(); y++)
	{
		if (problems.back()[y] == "+")
			subResult = 0;
		else if (problems.back()[y] == "*")
			subResult = 1;
		for (size_t i = 0; i < problems.size()-1; i++)
		{
			if (problems.back()[y] == "+")
			{
				subResult += stoll(problems[i][y].c_str());
			}
			else if (problems.back()[y] == "*")
			{
				subResult *= stoll(problems[i][y].c_str());
			}
		}
		UpdateProgress(progress++, problems.back().size(), to_string(subResult));
		result += subResult;
	}
	println("Result : " + to_string(result));
}