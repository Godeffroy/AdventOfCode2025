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
	bool operator==(const couple_t& other) const
	{
		return (x == other.x && y == other.y);
	}
	struct compare_xy {
		bool operator ()(const couple_t& left, const couple_t& right) const {
			return (left.y == right.y ? left.x < right.x : left.y < right.y);
		}
	};
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
	bool operator==(const point3D_t& other) const
	{
		return (x == other.x && y == other.y && z == other.z);
	}
	string toString() const
	{
		return std::format("Point3D({:4},{:4},{:4})", x, y, z);
	}
};

struct box_t
{
	point3D_t point{ 0,0,0 };
	int index = -1;
	int network = -1;

	box_t(int idx, point3D_t p) : point(p), index(idx) {}
	bool operator==(const box_t& other) const
	{
		return (point == other.point);
	}
	string toString() const
	{
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

struct boxCoupleRef_t
{
	box_t* box1;
	box_t* box2;
	double distance;

	// Constructeur principal : prend deux box_t par référence et la distance
	boxCoupleRef_t(box_t& b1, box_t& b2, double dist) : box1(&b1), box2(&b2), distance(dist) {}

	// Constructeur par défaut
	boxCoupleRef_t() : box1(nullptr), box2(nullptr), distance(0.0) {}

	bool operator<(const boxCoupleRef_t& other) const
	{
		return distance < other.distance;
	}
	bool operator>(const boxCoupleRef_t& other) const
	{
		return distance > other.distance;
	}

	bool operator==(const boxCoupleRef_t& other) const
	{
		// égalité indépendante de l'ordre des boîtes
		return ((box1 == other.box1 && box2 == other.box2) ||
				(box1 == other.box2 && box2 == other.box1));
	}

	// toString compatible avec le format utilisé ailleurs dans le fichier
	string toString() const
	{
		int idx1 = box1 ? box1->index : -1;
		int idx2 = box2 ? box2->index : -1;
		int x1 = box1 ? box1->point.x : 0;
		int y1 = box1 ? box1->point.y : 0;
		int z1 = box1 ? box1->point.z : 0;
		int x2 = box2 ? box2->point.x : 0;
		int y2 = box2 ? box2->point.y : 0;
		int z2 = box2 ? box2->point.z : 0;

		return std::format("Box1 [{:2}] ({:4},{:4},{:4}) - Distance:{:4.2f} - ({:4},{:4},{:4}) Box2 [{:2}]",
			idx1, x1, y1, z1,
			distance, x2, y2, z2, idx2);
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


struct coupleRef_t
{
	couple_t* couple1;
	couple_t* couple2;
	long long surface;

	// Constructeur principal : prend deux couple_t par référence
	coupleRef_t(couple_t& c1, couple_t& c2) : couple1(&c1), couple2(&c2)
	{
		//calcul the surface between the two couples
		surface = (static_cast<long long>(std::abs(c1.x - c2.x)) + 1) * (static_cast<long long>(std::abs(c1.y - c2.y)) + 1);

	}

	// Constructeur par défaut
	coupleRef_t() : couple1(nullptr), couple2(nullptr), surface(0) {}

	bool operator<(const coupleRef_t& other) const
	{
		return surface < other.surface;
	}
	bool operator>(const coupleRef_t& other) const
	{
		return surface > other.surface;
	}

	// toString compatible avec le format utilisé ailleurs dans le fichier
	string toString() const
	{
		int x1 = couple1 ? couple1->x : 0;
		int y1 = couple1 ? couple1->y : 0;
		int x2 = couple2 ? couple2->x : 0;
		int y2 = couple2 ? couple2->y : 0;

		return std::format("Couple1 ({:4},{:4}) - Surface:{:4} - ({:4},{:4}) Couple2",
			x1, y1,
			surface, x2, y2);
	}
};