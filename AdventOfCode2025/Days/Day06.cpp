#include "Day06.h"

// result :
// 11950004808442
void Day_06_Part_2()
{
	vector<string> inputLines = ReadInputFile(6, 1);
	long long result = 0;
	long long progress = 0;

	vector<problem_t> problems;
	int i = inputLines.back().find_first_not_of(' ', 0);
	while (i != -1)
	{
		problem_t prob;
		prob.operation = inputLines.back()[i];
		prob.posStart = i;
		prob.posEnd = inputLines.back().find_first_not_of(' ', i+1)-2;
		if (prob.posEnd < 0)
			prob.posEnd = inputLines.back().size()-1;
		for (int y = prob.posEnd; y >= prob.posStart; y--)
		{
			prob.numbers.push_back(string(inputLines.size() - 1, ' '));
			for (int z = 0; z < inputLines.size()-1; z++)
			{
				prob.numbers.back()[z] = inputLines[z][y];
			}
		}
		problems.push_back(prob);
		i = inputLines.back().find_first_not_of(' ', i+1);

		//UpdateProgress(progress++, inputLines.back().size(), to_string(i));
	}

	for (auto prob : problems)
	{
		long long subResult;
		if (prob.operation == '+')
			subResult = 0;
		else if (prob.operation == '*')
			subResult = 1;

		for (auto num : prob.numbers)
		{
			if (prob.operation == '+')
				subResult += stoi(num);
			else if (prob.operation == '*')
				subResult *= stoi(num);
		}
		result += subResult;
		UpdateProgress(progress++, problems.size(), to_string(subResult));
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