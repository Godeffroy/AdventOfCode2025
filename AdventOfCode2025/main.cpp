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

    Day_02_Part_1();

    println("Result : " + to_string(result));
	return 0;
}

// result : 19128774598
void Day_02_Part_1()
{
    ReadInputFile(2, 1);
    string line = inputLines[0];
    vector<long long> id1, id2;
    inputLines.clear();
    try
    {
        while (line.find(',') != -1)
        {
            inputLines.push_back(line.substr(0, line.find(',')));
            id1.push_back(stoll(line.substr(0, line.find('-'))));
            id2.push_back(stoll(line.substr(line.find('-') + 1)));
            line = line.substr(line.find(',') + 1);
        }
        inputLines.push_back(line);
        id1.push_back(stoll(line.substr(0, line.find('-'))));
        id2.push_back(stoll(line.substr(line.find('-') + 1)));
    }
    catch (const std::exception& e)
    {
        println(e.what());
    }

    vector<long long> invalidID;
    int cpt = 0;
    for (string str : inputLines)
    {
        for (long long i = id1[cpt]; i <= id2[cpt]; i++)
        {
            string s = to_string(i);
            if (to_string(i).length() % 2 != 0)
                continue;
            if (s.substr(0, to_string(i).length() / 2) == s.substr(to_string(i).length() / 2))
                invalidID.push_back(i);
        }
        cpt++;
    }
    for (long long int id : invalidID)
    {
        result += id;
    }
}
// result : 19128774598
void Day_02_Part_1()
{
    ReadInputFile(2, 1);
    string line = inputLines[0];
    vector<long long> id1, id2;
    inputLines.clear();
    try
    {
        while (line.find(',')!=-1)
        {
            inputLines.push_back(line.substr(0, line.find(',')));
            id1.push_back(stoll(line.substr(0, line.find('-'))));
            id2.push_back(stoll(line.substr(line.find('-') + 1)));
            line = line.substr(line.find(',') + 1);
        }
        inputLines.push_back(line);
        id1.push_back(stoll(line.substr(0, line.find('-'))));
        id2.push_back(stoll(line.substr(line.find('-') + 1)));
    }
    catch (const std::exception& e)
    {
		println(e.what());
    }

    vector<long long> invalidID;
    int cpt = 0;
    for (string str : inputLines)
    {
        for (long long i = id1[cpt]; i <= id2[cpt]; i++)
        {
            string s = to_string(i);
            if (to_string(i).length() % 2 != 0)
                continue;
            if (s.substr(0, to_string(i).length() / 2) == s.substr(to_string(i).length() / 2))
                invalidID.push_back(i);
        }
        cpt++;
    }
    for (long long int id : invalidID)
    {
        result += id;
    }
}

// not 7475 - 6162
void Day_01_Part_2()
{
    ReadInputFile(1, 2);
    int vault = 50;
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

        if (vault == 0)
            result++;

        while (vault > 100)
        {
            vault -= 100;
            result++;
        }

        while (vault < 0)
        {
            vault += 100;
            result++;
        }

        progress++;
    }
}

void Day_01_Part_1()
{
    ReadInputFile(1, 1);
    int vault = 50;
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
