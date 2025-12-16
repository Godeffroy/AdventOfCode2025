#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <format>


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


#define print(x) cout<<x
#define println(x) cout << x << endl

vector<string> ReadInputFile(int day, int part);
void UpdateProgress(size_t progress, size_t total, string const& subResult = "");
string to_string(long long value, int space);

struct couple {
	size_t x;
	size_t y;
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