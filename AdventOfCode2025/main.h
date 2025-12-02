#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::to_string;

#define print(x) cout<<x;
#define println(x) cout << x << endl;


vector<string> inputLines;
int result;

void ReadInputFile(int day, int part);

void Day_01_Part_1();
void Day_01_Part_2();