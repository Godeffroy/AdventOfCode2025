#include "Day04.h"

// result : 
// 
void Day_04_Part_2()
{
	vector<string> inputLines = ReadInputFile(4, 0);
	long long result = 0;
	long long progress = 0;
	for (string line : inputLines)
	{
		progress++;
		UpdateProgress(progress, inputLines.size(), to_string(progress));
	}

	println("Result : " + to_string(result));
}

// result :
// 1320
void Day_04_Part_1()
{
	vector<string> inputLines = ReadInputFile(4, 1);
	vector<vector<char>> grid;
	long long result = 0;
	long long progress = 0;
	for (string line : inputLines)
	{
		grid.emplace_back();
		for (char c : line)
		{
			grid[grid.size() - 1].push_back(c);
		}
	}

	for (size_t y = 0; y < grid.size(); y++)
	{
		for (size_t x = 0; x < grid[y].size(); x++)
		{
			if (grid[y][x] == '.')
				continue;

			int roll = 0;
				//down
				if (y < grid.size() - 1 && grid[y + 1][x] == '@')
					roll++;
				//up
				if (y > 0 && grid[y - 1][x] == '@')
					roll++;
				//left
				if (x > 0 && grid[y][x - 1] == '@')
					roll++;
				//right
				if (x < grid[y].size() - 1 && grid[y][x + 1] == '@')
					roll++;
				//diagDownLeft
				if (x > 0 && y < grid.size() - 1 && grid[y + 1][x - 1] == '@')
					roll++;
				//diagDownRight
				if (x < grid[y].size() - 1 && y < grid.size() - 1 && grid[y + 1][x + 1] == '@')
					roll++;
				//diagUpLeft
				if (y > 0 && x > 0 && grid[y - 1][x - 1] == '@')
					roll++;
				//diagUpRight
				if (x < grid[y].size() - 1 && y > 0 && grid[y - 1][x + 1] == '@')
					roll++;

				if (roll < 4)
					result++;
		}
			progress++;
			UpdateProgress(progress, inputLines.size(), to_string(progress));
	}	

	println("Result : " + to_string(result));
}
