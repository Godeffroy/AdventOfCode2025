#include "Day03.h"

// result :
// 
void Day_03_Part_2()
{
	vector<string> inputLines = ReadInputFile(3, 1);
	long long result = 0;
	long long bat1 = 0;
	long long bat2 = 0;
	long long bat3 = 0;
	long long bat4 = 0;
	long long bat5 = 0;
	long long bat6 = 0;
	long long bat7 = 0;
	long long bat8 = 0;
	long long bat9 = 0;
	long long bat10 = 0;
	long long bat11 = 0;
	long long bat12 = 0;
	long long progress = 0;
	for (string line : inputLines)
	{
		bat1 = bat2 = bat3 = bat4 = bat5 = bat6 = bat7 = bat8 = bat9 = bat10 = bat11 = bat12 = 0;
		int cpt = 0;
		for (char c : line)
		{
			if (int bat = c - '0'; bat > bat1 && cpt < (line.length() - 11))
			{
				bat1 = bat;
				bat2 = bat3 = bat4 = bat5 = bat6 = bat7 = bat8 = bat9 = bat10 = bat11 = bat12 = 0;
			}
			else if (bat > bat2 && cpt < (line.length() - 10))
			{
				bat2 = bat;
				bat3 = bat4 = bat5 = bat6 = bat7 = bat8 = bat9 = bat10 = bat11 = bat12 = 0;
			}
			else if (bat > bat3 && cpt < (line.length() - 9))
			{
				bat3 = bat;
				bat4 = bat5 = bat6 = bat7 = bat8 = bat9 = bat10 = bat11 = bat12 = 0;
			}
			else if (bat > bat4 && cpt < (line.length() - 8))
			{
				bat4 = bat;
				bat5 = bat6 = bat7 = bat8 = bat9 = bat10 = bat11 = bat12 = 0;
			}
			else if (bat > bat5 && cpt < (line.length() - 7))
			{
				bat5 = bat;
				bat6 = bat7 = bat8 = bat9 = bat10 = bat11 = bat12 = 0;
			}
			else if (bat > bat6 && cpt < (line.length() - 6))
			{
				bat6 = bat;
				bat7 = bat8 = bat9 = bat10 = bat11 = bat12 = 0;
			}
			else if (bat > bat7 && cpt < (line.length() - 5))
			{
				bat7 = bat;
				bat8 = bat9 = bat10 = bat11 = bat12 = 0;
			}
			else if (bat > bat8 && cpt < (line.length() - 4))
			{
				bat8 = bat;
				bat9 = bat10 = bat11 = bat12 = 0;
			}
			else if (bat > bat9 && cpt < (line.length() - 3))
			{
				bat9 = bat;
				bat10 = bat11 = bat12 = 0;
			}
			else if (bat > bat10 && cpt < (line.length() - 2))
			{
				bat10 = bat;
				bat11 = bat12 = 0;
			}
			else if (bat > bat11 && cpt < (line.length() - 1))
			{
				bat11 = bat;
				bat12 = 0;
			}
			else if (bat > bat12)
				bat12 = bat;
			cpt++;
		}
		long long jolt = bat1 * pow(10, 11) + bat2 * pow(10, 10) + bat3 * pow(10, 9) + bat4 * pow(10, 8) + bat5 * pow(10, 7) + bat6 * pow(10, 6) + bat7 * pow(10, 5) + bat8 * pow(10, 4) + bat9 * pow(10, 3) + bat10 * pow(10, 2) + bat11 * pow(10, 1) + bat12;
		result += jolt;
		progress++;
		UpdateProgress(progress, inputLines.size(), to_string(jolt));
	}

	println("Result : " + to_string(result));
}

// result : 
// 17147 too low
// 17207 ok
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
		int cpt = 0;
		for (char c : line)
		{
			if (int bat = c - '0'; bat > bat1 && cpt != (line.length() - 1))
			{
				bat1 = bat;
				bat2 = 0;
			}
			else if (bat > bat2)
				bat2 = bat;
			cpt++;
		}
		int jolt = bat1 * 10 + bat2;
		result += jolt;
		progress++;
		UpdateProgress(progress, inputLines.size(), to_string(jolt));
	}

	println("Result : " + to_string(result));
}
