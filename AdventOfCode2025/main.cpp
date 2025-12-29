#include "main.h"

int main()
{
    println("*----------------*");
    println("| Advent of Code |");
    println("*----------------*");

    try
    {
        Day_09_Part_1();
    }
    catch (const std::system_error& e)
    {
        println(e.what());
    }

	return 0;
}
