#include "main.h"

int main()
{
    println("*----------------*");
    println("| Advent of Code |");
    println("*----------------*");

    try
    {
        Day_07_Part_2();
    }
    catch (const std::system_error& e)
    {
        println(e.what());
    }

	return 0;
}
