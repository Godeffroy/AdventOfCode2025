#include "Day05.h"

// result : 
// 442266765077712 too high
// 1829693007032757 too high
// 352716206375547 OK
void Day_05_Part_2()
{
	vector<string> inputLines = ReadInputFile(5, 1);
	long long result = 0;
	long long progress = 0;

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

	bool added = false;
	do {
		added = false;
		for (size_t r = 0; r < ranges.size()-1; r++)
		{
			for (size_t f = r+1; f < ranges.size(); f++)
			{
				if (ranges[f].end < ranges[r].start || ranges[f].start > ranges[r].end)
					continue;
				if (ranges[f].start < ranges[r].start)
				{
					ranges[r].start = ranges[f].start;
				}
				if (ranges[f].end > ranges[r].end)
				{
					ranges[r].end = ranges[f].end;
				}
				added = true;
				ranges.erase(ranges.begin() + f);
				break;
			}
			if (added)
				break;
			progress++;
		}
		UpdateProgress(progress, ranges.size(), to_string(0));

	} while (added);

	for(auto range : ranges)
	{
		result += (range.end - range.start + 1);
	}

	println("Result : " + to_string(result));
}


// result : 
// 
void Day_05_Part_1()
{
	vector<string> inputLines = ReadInputFile(5, 1);
	long long result = 0;
	long long progress = 0;

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