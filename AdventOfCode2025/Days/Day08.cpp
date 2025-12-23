#include "Day08.h"

// result :
// 123234
void Day_08_Part_2()
{
	vector<string> inputLines = ReadInputFile(8, 0);
	long long result = 0;
	long long progress = 0;

	for (string line : inputLines)
	{
		UpdateProgress(progress++, inputLines.size(), to_string(result));
	}
	println("Result : " + to_string(result));
}


// result :
// 
void Day_08_Part_1()
{
	vector<string> inputLines = ReadInputFile(8, 1);
	long long result = 0;
	long long progress = 0;

	vector<box_t> boxes;

	int cpt = 0;
	for (string line : inputLines)
	{
		point3D_t boxPoint;
		boxPoint.x = stoi(line.substr(0, line.find_first_of(',')));
		boxPoint.y = stoi(line.substr(line.find_first_of(',') + 1, line.find_last_of(',')));
		boxPoint.z = stoi(line.substr(line.find_last_of(',') + 1, line.size()));
		boxes.emplace_back(cpt++, boxPoint);
	}
	std::set <boxCouple_t> sortedClosestBoxes;
	for (int i = 0; i < boxes.size(); i++)
	{
		for (int y = 0; y < boxes.size(); y++)
		{
			if (i == y)
				continue;
			double distance = EuclideanDistance(boxes[i].point, boxes[y].point);
			sortedClosestBoxes.insert({ i, y, distance });


			//if (distance <= boxes[i].closestDistance || boxes[i].closestDistance == -1)
			//{
			//	boxes[i].closestDistance = distance;
			//	boxes[i].closestBoxIndex = y;
			//}
		}
	}
	int networkGlobal = -1;
	int cptMax = 0;
	for (auto& box : sortedClosestBoxes)
	{
		println(box.toString(boxes));

		if (boxes[box.indexBox1].network == -1 && boxes[box.indexBox2].network == -1)
		{
			boxes[box.indexBox1].network = boxes[box.indexBox2].network = ++networkGlobal;
		}
		else if (boxes[box.indexBox1].network != -1)
		{
			if(boxes[box.indexBox2].network == -1)
				boxes[box.indexBox2].network = boxes[box.indexBox1].network;
			else
			{
				int index = boxes[box.indexBox2].network;
				for (auto const& boxTemp : boxes)
				{
					if (boxes[boxTemp.index].network == index)
					{
						boxes[boxTemp.index].network = boxes[box.indexBox1].network;
					}
				}
			}
		}
		else if (boxes[box.indexBox2].network != -1)
		{
			if (boxes[box.indexBox1].network == -1)
				boxes[box.indexBox1].network = boxes[box.indexBox2].network;
			else
			{
				int index = boxes[box.indexBox1].network;
				for (auto const& boxTemp : boxes)
				{
					if (boxes[boxTemp.index].network == index)
					{
						boxes[boxTemp.index].network = boxes[box.indexBox2].network;
					}
				}
			}
		}
		cptMax++;

		UpdateProgress(cptMax, sortedClosestBoxes.size(), to_string(networkGlobal));
		if (cptMax >= 1000)
			break;
	}
	println("---");
	vector<network_t> networks;
	for (auto& box : boxes)
	{
		println(std::format("Box {:2} ", box.index) + box.toString());
		bool netFound = false;
		for (size_t i = 0; i < networks.size(); i++)
		{
			if (networks[i].index == box.network)
			{
				netFound = true;
				networks[i].boxCount++;
			}
		}
		if (!netFound)
			networks.push_back({ box.network,1 });
	}

	println("---");
	sort(networks.begin(), networks.end(), std::greater<network_t>());
	long long subresult = 1;
	for (int i = 1; i < networks.size(); i++)
	{
		if(i<=3)
			subresult *= networks[i].boxCount;
		println(networks[i].toString());
		UpdateProgress(i, networks.size(), to_string(subresult));
	}
	result = subresult;

	println("Result : " + to_string(result));
}