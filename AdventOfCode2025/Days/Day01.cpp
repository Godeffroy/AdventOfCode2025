#include "Day01.h"

// not 7475 - 6162 - 5761 - 6364 - 5689
void Day_01_Part_2()
{
    vector<string> inputLines = ReadInputFile(1, 2);
    long long result = 0;
    long long lastResult = 0;
    int vault = 50;
    int lastVault = 50;
    int progress = 0;
    for (string line : inputLines)
    {
        char sens = line.at(0);
        int value = std::stoi(line.substr(1));
        string subVault;

        if (sens == 'R')
        {
            subVault += "         " + to_string(vault, 4) + " ->R " + to_string(value, 4);
            vault += value;
            subVault += "  Vault= " + to_string(vault, 4);
        }
        else if (sens == 'L')
        {
            subVault += "L"+ to_string(value, 4) + " <- " + to_string(vault, 4);
            vault -= value;
            subVault += "           Vault= " + to_string(vault, 4);
        }

        if (vault == 0)
            result++;
        else if(vault >= 100)
        {
                result += vault/100;
                vault %= 100;
        }
        else if (vault < 0)
        {
            result += (- vault) / 100;
            vault %= 100;
            if (vault < 0)
            {
                vault += 100;

                if (lastVault != 0)
                {
                    result++;
                }
            }
        }

        if (lastResult != result)
        {

            subVault += "\t => + " + to_string(result - lastResult) + " Vault= " + to_string(vault, 4);
            lastResult = result;
        }
        lastVault = vault;
        progress++;
        UpdateProgress(progress, inputLines.size(), subVault);
    }

    println("Result : " + to_string(result));
}

// result
// 1118 OK
void Day_01_Part_1()
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

        while (vault >= 100)
            vault -= 100;

        while (vault < 0)
            vault += 100;

        if (vault == 0)
            result++;

        progress++;
        UpdateProgress(progress, inputLines.size(), to_string(result));
    }

    println("Result : " + to_string(result));
}
