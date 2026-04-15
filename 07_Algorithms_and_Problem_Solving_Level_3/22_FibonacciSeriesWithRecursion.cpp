#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

int PrintFibonacciUsingRecurssion(int first, int second, int number)
{
    if (number == 0)
    {
        return 0;
    }
    cout << second << "  ";
    return PrintFibonacciUsingRecurssion(second, first + second, --number);
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #22 : Write a program to print Fibonacci Series of 10.\n";
    cout << "\tex  : Fibonacci Series of 10 : 1  1  2  3  5  8  13  21  34  55\n";
    cout << "-------------------------------------------------\n\n";
    cout << "Fibonacci Series of " << 10 << " : ";
    PrintFibonacciUsingRecurssion(0, 1, 10);
    cout << "\n\n-------------------------------------------------";
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
