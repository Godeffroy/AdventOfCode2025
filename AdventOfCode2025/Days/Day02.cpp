#include "Day02.h"

// result : 
// 4175389365 too low
// 21932258645 ok
void Day_02_Part_2()
{
	vector<string> inputLines = ReadInputFile(2, 1);
	long long result = 0;
	string line = inputLines[0];
	vector<long long> id1;
	vector<long long> id2;
	inputLines.clear();

	while (line.find(',') != -1)
	{
		inputLines.push_back(line.substr(0, line.find(',')));
		id1.push_back(stoll(line.substr(0, line.find('-'))));
		id2.push_back(stoll(line.substr(line.find('-') + 1)));
		line = line.substr(line.find(',') + 1);
	}
	inputLines.push_back(line);
	id1.push_back(stoll(line.substr(0, line.find('-'))));
	id2.push_back(stoll(line.substr(line.find('-') + 1)));

	vector<long long> invalidID;
	int cpt = 0;
	for (string strTmp : inputLines)
	{
		for (long long i = id1[cpt]; i <= id2[cpt]; i++)
		{
			string currentId = to_string(i);
			for (size_t y = 1; y <= currentId.length() / 2; y++)
			{
				string search = currentId.substr(0, y);
				if (search.length() == 0 || currentId.length() % search.length() != 0)
					continue;
				auto divide = currentId.length() / search.length();
				bool same = true;
				for (size_t z = 1; z < divide; z++)
				{
					string test = currentId.substr(z * search.length(), search.length());
					same = same && test == search;
					if (!same)
						break;
				}
				if (same && (invalidID.empty() || invalidID.back() != i))
					invalidID.push_back(i);
			}
		}
		cpt++;
		UpdateProgress(cpt, inputLines.size());
	}
	for (long long int id : invalidID)
	{
		result += id;
	}
}

// result : 
// 19128774598 ok
void Day_02_Part_1()
{
	vector<string> inputLines = ReadInputFile(2, 1);
	long long result = 0;
	string line = inputLines[0];
	vector<long long> id1;
	vector<long long> id2;
	inputLines.clear();

	while (line.find(',') != -1)
	{
		inputLines.push_back(line.substr(0, line.find(',')));
		id1.push_back(stoll(line.substr(0, line.find('-'))));
		id2.push_back(stoll(line.substr(line.find('-') + 1)));
		line = line.substr(line.find(',') + 1);
	}
	inputLines.push_back(line);
	id1.push_back(stoll(line.substr(0, line.find('-'))));
	id2.push_back(stoll(line.substr(line.find('-') + 1)));

	vector<long long> invalidID;
	int cpt = 0;
	for (string str : inputLines)
	{
		for (long long i = id1[cpt]; i <= id2[cpt]; i++)
		{
			string s = to_string(i);
			if (to_string(i).length() % 2 != 0)
				continue;
			if (s.substr(0, to_string(i).length() / 2) == s.substr(to_string(i).length() / 2))
				invalidID.push_back(i);
		}
		cpt++;
		UpdateProgress(cpt, inputLines.size());
	}
	for (long long int id : invalidID)
	{
		result += id;
	}

	println("Result : " + to_string(result));
}
