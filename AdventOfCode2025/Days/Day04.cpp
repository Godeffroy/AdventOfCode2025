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
// 
void Day_04_Part_1()
{
	vector<string> inputLines = ReadInputFile(4, 0);
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

	for (signed long long y = grid.size()-1; y >= 0; y--)
	{
		for (size_t x = 0; x < grid[y].size(); x++)
		{
			if (grid[y][x] == '.')
				continue;
			if (y == 0 || y == grid.size() - 1 || x == 0 || x == grid[y].size() - 1)
				result++;
			else
			{
				int roll = 0;
				//char current = grid[y][x];
				char up = grid[y + 1][x];
				if (up == '.')
					roll++;
				char down = grid[y - 1][x];
				if (down == '.')
					roll++;
				char left = grid[y][x - 1];
				if (left == '.')
					roll++;
				char right = grid[y][x + 1];
				if (right == '.')
					roll++;
				char diagUpLeft = grid[y + 1][x - 1];
				if (diagUpLeft == '.')
					roll++;
				char diagUpRight = grid[y + 1][x + 1];
				if (diagUpRight == '.')
					roll++;
				char diagDownLeft = grid[y - 1][x - 1];
				if (diagDownLeft == '.')
					roll++;
				char diagDownRight = grid[y - 1][x + 1];
				if (diagDownRight == '.')
					roll++;

				if(roll<4)
					result++;
			}
			progress++;
			UpdateProgress(progress, inputLines.size(), to_string(progress));
		}
	}


	

	println("Result : " + to_string(result));
}
