#include "Day09.h"

// result :
// 
void Day_09_Part_2()
{
	vector<string> inputLines = ReadInputFile(9, 0);
	long long result = 0;
	long long progress = 0;

	UpdateProgress(progress++, inputLines.size(), to_string(result));

	println("Result : " + to_string(result));
}


// result :
// 4749672288
void Day_09_Part_1()
{
	vector<string> inputLines = ReadInputFile(9, 1);
	long long result = 0;
	long long progress = 0;

	vector<couple_t> tiles;
	for (string line : inputLines)
	{
		size_t index = line.find_first_of(',');
		int x = stoi(line.substr(0, index));
		int y = stoi(line.substr(index + 1, line.size()));
		tiles.push_back(couple_t{ x,y });
	}
	sort(tiles.begin(), tiles.end(), couple_t::compare_xy());

	vector <coupleRef_t> sortedLargestSurfaceCoupleTiles;
	for (int i = 0; i < tiles.size() - 1; i++)
	{
		for (int y = i + 1; y < tiles.size(); y++)
		{
			sortedLargestSurfaceCoupleTiles.emplace_back(tiles[i],tiles[y]);
			UpdateProgress(progress++, inputLines.size() * inputLines.size(), to_string(sortedLargestSurfaceCoupleTiles.back().surface));
		}
	}
	sort(sortedLargestSurfaceCoupleTiles.begin(), sortedLargestSurfaceCoupleTiles.end(), std::less<coupleRef_t>());

	result = sortedLargestSurfaceCoupleTiles.back().surface;

	println("Result : " + to_string(result));
}