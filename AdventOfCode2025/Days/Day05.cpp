#include "Day05.h"

// result : 
// 
void Day_05_Part_2()
{
	vector<string> inputLines = ReadInputFile(5, 0);
	long long result = 0;
	long long progress = 0;

	struct range {
		long long start;
		long long end;
	};
	vector<range> ranges;
	vector<long long> ids;
	for (string line : inputLines)
	{
		if (size_t rangeIndex = line.find('-'); rangeIndex != -1)
		{
			ranges.push_back(range{ stoll(line.substr(0, rangeIndex)), stoll(line.substr(rangeIndex + 1)) });
		}
		if (line.length() != 0)
		{
			ids.push_back(stoll(line));
		}

	}
	
	UpdateProgress(progress, inputLines.size(), to_string(result));

	println("Result : " + to_string(result));
}


// result : 
// 
void Day_05_Part_1()
{
	vector<string> inputLines = ReadInputFile(5, 1);
	long long result = 0;
	long long progress = 0;

	struct range_t {
		long long start;
		long long end;
	};
	vector<range_t> ranges;
	vector<long long> ids;
	for (string line : inputLines)
	{
		if (size_t rangeIndex = line.find('-'); rangeIndex != -1)
		{
			ranges.push_back(range_t{ stoll(line.substr(0, rangeIndex)), stoll(line.substr(rangeIndex + 1)) });
		}
		else if (line.length() != 0)
		{
			ids.push_back(stoll(line));
		}
	}

	vector<long long> fresh;
	for (auto id : ids)
	{
		for (auto range : ranges)
		{
			if (id >= range.start && id <= range.end)
			{
				fresh.push_back(id);
				result++;
				break;
			}
		}
		UpdateProgress(progress++, ids.size(), to_string(result));
	}

	println("Result : " + to_string(result));
}