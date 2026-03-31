#pragma once
#include <iostream>
#include <limits>
#include <climits>
using namespace std;
namespace Lib
{
    int ReadPositiveNumber(string message)
    {
        int number;
        do
        {
            cout << message;
            cin >> number;
        } while (number <= 0);
        return number;
    }

    int ReadNumber(string message = "", int from = INT_MIN, int to = INT_MAX)
    {
        int number;
        while (true)
        {
            cout << message;
            cin >> number;

            if (cin.fail() || cin.peek() != '\n' || number < from || number > to)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid Number, Try Again.\n\n";
            }
            else
            {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return number;
            }
        }
    }
    float ReadNumber(string message = "", float from = -FLT_MAX, float to = FLT_MAX)
    {
        float number;
        while (true)
        {
            cout << message;
            cin >> number;

            if (cin.fail() || cin.peek() != '\n' || number < from || number > to)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid Number, Try Again.\n\n";
            }
            else
            {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return number;
            }
        }
    }
}