#include "Tools.h"

//the function read all lines form the input file and fill each line in a vector of strings
vector<string> ReadInputFile(int day, int part)
{
    vector<string> inputLines;
    println("Reading input file : Day " + to_string(day) + " - Part " + to_string(part));
    string fileName = std::format("input/input_{}_{}.txt", day, part);
    std::ifstream file(fileName);
    string str;
    while (std::getline(file, str))
    {
        inputLines.push_back(str);
    }
    return inputLines;
}

void UpdateProgress(size_t progress, size_t total, string const & subResult)
{
    println("Progress : " + to_string(progress, to_string(total).size()) + " / " + to_string(total) + "    " + subResult);
}

string to_string(long long value, int space)
{
    return string(space-to_string(value).size(), ' ').append(to_string(value));
}

double EuclideanDistance(point3D_t a, point3D_t b)
{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2));
}