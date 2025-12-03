#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//https://cplusplus.com/reference/string/string/
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::to_string;
using std::stoi;
using std::stol;

#define print(x) cout<<x;
#define println(x) cout << x << endl;


vector<string> inputLines;
long long result = 0;

void ReadInputFile(int day, int part);

void Day_01_Part_1();
void Day_01_Part_2();

void Day_02_Part_1();
void Day_02_Part_2();