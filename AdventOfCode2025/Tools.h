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

#define print(x) cout<<x
#define println(x) cout << x << endl

vector<string> ReadInputFile(int day, int part);
void UpdateProgress(size_t progress, size_t total, string const& subResult = "");