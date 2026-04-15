#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

void PrintFibonacciUsingLoop(int number)
{
    int first = 1, second = 1, next;
    cout << "Fibonacci Series of " << number << " : 1 1 ";
    for (int i = 3; i <= number; i++)
    {
        next = first + second;
        cout << next << " ";
        first = second;
        second = next;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #21 : Write a program to print Fibonacci Series of 10.\n";
    cout << "\tex  : Fibonacci Series of 10 : 1  1  2  3  5  8  13  21  34  55\n";
    cout << "-------------------------------------------------\n\n";
    PrintFibonacciUsingLoop(10);
    cout << "\n\n-------------------------------------------------";
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
