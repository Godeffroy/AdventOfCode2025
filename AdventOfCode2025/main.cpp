#include "main.h"


//the function read all lines form the input file and fill each line in a vector of strings
void ReadInputFile(int day, int part)
{
    println("Reading input file : Day "+ to_string(day)+" - Part "+ to_string(part));
    string fileName = "input\\input_" + to_string(day) + '_' + to_string(part) + ".txt";
    std::ifstream file(fileName);
    string str;
    while (std::getline(file, str))
    {
		inputLines.push_back(str);
    }
}

void ReadInput(string& input)
{
	cin >> input;
}

int main()
{
    println("*----------------*");
    println("| Advent of Code |");
    println("*----------------*");

    Day_01_Part_2();

    println("Result : " + to_string(result));
	return 0;
}

// not 7475
void Day_01_Part_2()
{
    ReadInputFile(1, 2);
    int vault = 50;
    result = 0;
    int progress = 0;
    size_t total = inputLines.size();
    for (string line : inputLines)
    {
        char sens = line.at(0);
		int value = std::stoi(line.substr(1));

        if(sens == 'R')
        {
            vault += value;
        }
        else if(sens == 'L')
        {
            vault -= value;
		}
        else
			vault += 0;

        while (vault >= 100)
        {
            vault -= 100;
            result++;
        }

        while (vault < 0)
        {
            vault += 100;
            result++;
        }

        if (vault == 0)
            result++;

        progress++;
    }
}

void Day_01_Part_1()
{
    ReadInputFile(1, 1);
    int vault = 50;
    result = 0;
    int progress = 0;
    size_t total = inputLines.size();
    for (string line : inputLines)
    {
        char sens = line.at(0);
        int value = std::stoi(line.substr(1));

        if (sens == 'R')
        {
            vault += value;
        }
        else if (sens == 'L')
        {
            vault -= value;
        }
        else
            vault += 0;

        while (vault >= 100)
            vault -= 100;

        while (vault < 0)
            vault += 100;

        if (vault == 0)
            result++;

        progress++;
    }
}
