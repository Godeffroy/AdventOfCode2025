#pragma once

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <format>
#include <set>

//https://cplusplus.com/reference/string/string/
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::to_string;
using std::stoi;
using std::stol;
using std::stoll;
using std::sort;

#define print(x) cout<<x
#define println(x) cout << x << endl

struct couple_t {
	int x;
	int y;
	couple_t(int a, int b) : x(a), y(b) {}
	string toString() const
	{
		return std::format("Couple({},{})", x, y);
	}
};

struct range_t {
	long long start;
	long long end;
};

struct dictionnary_t {
	long long key;
	long long value;
};

enum class operation_e {
	ADD,
	MUL
};

struct problem_t {
	vector<string> numbers;
	char operation;
	int posStart;
	int posEnd;
};

struct point3D_t {
	int x;
	int y;
	int z;
	string toString() const
	{
		return std::format("Point3D({:4},{:4},{:4})", x, y, z);
	}
};

struct box_t
{
	point3D_t point{ 0,0,0 };
	int index = -1;
	//int closestBoxIndex = -1;
	//double closestDistance = -1;
	int network = -1;

	box_t(int idx, point3D_t p) : point(p), index(idx) {}
	/*bool operator<(const box_t& other) const
	{
		return closestDistance < other.closestDistance;
	}*/
	string toString() const
	{
		//return std::format("Point({:4},{:4},{:4}) Closest:{:2} Distance:{:4.2f} Network:{:2}", point.x, point.y, point.z, closestBoxIndex, closestDistance, network);
		return std::format("Point({:4},{:4},{:4}) Network:{:2}", point.x, point.y, point.z, network);
	}
};

struct boxCouple_t
{
	int indexBox1;
	int indexBox2;
	double distance;

	boxCouple_t(int idx1, int idx2, double dist) : indexBox1(idx1), indexBox2(idx2), distance(dist) {}
	bool operator<(const boxCouple_t& other) const
	{
		return distance < other.distance;
	}
	bool operator==(const boxCouple_t& other)
	{
		return ((indexBox1 == other.indexBox1 && indexBox2 == other.indexBox2) ||
			(indexBox1 == other.indexBox2 && indexBox2 == other.indexBox1));
	}
	string toString(vector<box_t> const& boxes) const
	{
		return std::format("Box1 [{:2}] ({:4},{:4},{:4}) - Distance:{:4.2f} - ({:4},{:4},{:4}) Box2 [{:2}]",
			indexBox1, boxes[indexBox1].point.x, boxes[indexBox1].point.y, boxes[indexBox1].point.z,
			distance, boxes[indexBox2].point.x, boxes[indexBox2].point.y, boxes[indexBox2].point.z, indexBox2);
	}
};

struct network_t{
	int index;
	int boxCount;
	network_t(int idx, int count) : index(idx), boxCount(count) {}
	bool operator<(const network_t& other) const
	{
		return boxCount < other.boxCount;
	}
	bool operator>(const network_t& other) const
	{
		return boxCount > other.boxCount;
	}
	string toString() const
	{
		return std::format("Network {:2} - Box count : {:4}", index, boxCount);
	}
};

vector<string> ReadInputFile(int day, int part);
void UpdateProgress(size_t progress, size_t total, string const& subResult = "");
string to_string(long long value, int space);

double EuclideanDistance(point3D_t a, point3D_t b);
