#include "Day01.h"

// not 7475 - 6162
void Day_01_Part_2()
{
    vector<string> inputLines = ReadInputFile(1, 2);
    long long result = 0;
    int vault = 50;
    int progress = 0;
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
        UpdateProgress(progress, inputLines.size());
    }

    println("Result : " + to_string(result));
}

// result
void Day_01_Part_1()
{
    vector<string> inputLines = ReadInputFile(1, 1);
    long long result = 0;
    
    int vault = 50;
    int progress = 0;
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
        UpdateProgress(progress, inputLines.size());
    }

    println("Result : " + to_string(result));
}
