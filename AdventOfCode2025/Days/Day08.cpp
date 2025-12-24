#include "Day08.h"

// result :
// 1221958433 too low
// 670023973 too low
// 
void Day_08_Part_2()
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
	vector <boxCoupleRef_t> sortedClosestCoupleBoxes;
	for (int i = 0; i < boxes.size() - 1; i++)
	{
		for (int y = i + 1; y < boxes.size(); y++)
		{
			if (i == y)
				continue;
			double distance = EuclideanDistance(boxes[i].point, boxes[y].point);
			//insert sorted by distance, without including the pair twice
			sortedClosestCoupleBoxes.emplace_back();
			sortedClosestCoupleBoxes.back().box1 = &boxes[i];
			sortedClosestCoupleBoxes.back().box2 = &boxes[y];
			sortedClosestCoupleBoxes.back().distance = distance;
		}
	}
	sort(sortedClosestCoupleBoxes.begin(), sortedClosestCoupleBoxes.end(), std::less<boxCoupleRef_t>());
	int networkGlobal = -1;
	int cptMax = 0;
	boxCoupleRef_t lastBoxCouple;
	for (auto& [box1, box2, distance] : sortedClosestCoupleBoxes)
	{
		if (box1->network == -1 && box2->network == -1)
		{
			box1->network = box2->network = ++networkGlobal;
		}
		else if (box1->network == box2->network)
			continue;
		else if (box1->network != -1 && box2->network == -1)
		{
			box2->network = box1->network;
			lastBoxCouple.box1 = box1;
			lastBoxCouple.box2 = box2;
			lastBoxCouple.distance = distance;
		}
		else if (box2->network != -1 && box1->network == -1)
		{
			box1->network = box2->network;
			lastBoxCouple.box1 = box1;
			lastBoxCouple.box2 = box2;
			lastBoxCouple.distance = distance;
		}
		else
		{
			lastBoxCouple.box1 = box1;
			lastBoxCouple.box2 = box2;
			lastBoxCouple.distance = distance;
			int index = box2->network;
			for (auto& boxTemp : boxes)
			{
				if (boxTemp.network == index)
				{
					boxTemp.network = box1->network;
				}
			}
		}

		cptMax++;

		UpdateProgress(cptMax, sortedClosestCoupleBoxes.size(), to_string(networkGlobal));
		//if (cptMax >= 1000)
		//	break;
	}
	int net = boxes[0].network;
	bool allInSameNetwork = true;
	for (auto& box : boxes)
	{
		if (box.network != net)
			allInSameNetwork = false;
	}

	println("---");

	auto back = sortedClosestCoupleBoxes.back();
	println(back.toString());

	println("---");
	println(lastBoxCouple.box1->toString());
	println(lastBoxCouple.box2->toString());
	result = lastBoxCouple.box1->point.x * lastBoxCouple.box2->point.x;
	println("Result : " + to_string(result));
}


// result :
// 123234
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