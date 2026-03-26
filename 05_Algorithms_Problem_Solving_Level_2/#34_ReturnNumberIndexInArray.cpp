#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

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

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void PrintArray(int arr[], int arrLength)
{
    cout << "Array elements : ";
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void FillArrayWithRandomNumbers(int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

int FindNumberPositionInArray(int number, int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == number)
            return i;
    }
    return -1;
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #34 : Write a program to fill array with max size 100 with random numbers from 1 to 100, read number and return its index in array if found otherwise return -1.\n ";
    cout << "\tex  : Enter how many random number to be created in array : 5\n\t=>\tArray elements : 72 29 66 17 73\n\t\tEnter number to find its index in array : 17\n\t\tThe number found at position: 3\n\t\tThe number found its order  : 4\n\n";
    cout << "\tex  : Enter how many random number to be created in array : 5\n\t=>\tArray elements : 72 29 66 17 73\n\t\tEnter number to find its index in array : 55\n\t\tThe number is not found :-(\n\n";
    cout << "------------------------\n\n";
    int arrLength = ReadPositiveNumber("Enter how many randmon number to be created in array : ");
    int arr[100];
    FillArrayWithRandomNumbers(arr, arrLength);
    PrintArray(arr, arrLength);
    int number = ReadPositiveNumber("Enter number to find its index in array : ");
    int NumberPosition = FindNumberPositionInArray(number, arr, arrLength);

    if (NumberPosition == -1)
        cout << "The number is not found :-(\n";
    else
    {
        cout << "The number found at position: " << NumberPosition << endl;
        cout << "The number found its order  : " << NumberPosition + 1 << endl;
    }
    cout << "\n------------------------";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
