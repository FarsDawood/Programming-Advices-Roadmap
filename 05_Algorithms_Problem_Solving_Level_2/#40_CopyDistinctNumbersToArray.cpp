#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <math.h>
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

void PrintArray(int arr[], int arrLength)
{
    cout << "Array elements : ";
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillArrayWithRandomNumbers(int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

void AddArrayElement(int number, int arr[], int &arrLength)
{
    if (arrLength >= 100)
        return;
    arr[arrLength] = number;
    arrLength++;
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

bool IsNumberInArray(int Number, int arr[], int arrLength)
{
    return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}

void CopyDistinctNumbersToArray(int arrSource[], int arrDestination[], int arrLength, int &arrLength2)
{
    for (int i = 0; i < arrLength; i++)
        if (!IsNumberInArray(arrSource[i], arrDestination, arrLength2))
            AddArrayElement(arrSource[i], arrDestination, arrLength2);
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #40 : Write a program to fill array with numbers, then print distinct numbers to another array.\n ";
    cout << "\tex  : Enter how many randmon number to be created in array : 6\n\t=>\tArray 1 elements : 41 30 4 30 4 4\n\t\tArray 2 distinct elements : 41 30 4\n\n";

    cout << "------------------------\n\n";
    int arr[100], arrLength = ReadPositiveNumber("Enter how many randmon number to be created in array : ");
    FillArrayWithRandomNumbers(arr, arrLength);
    PrintArray(arr, arrLength);
    cout << "[ Array 1 elements before copy ] ";
    PrintArray(arr, arrLength);
    int arr2[100], arrLength2 = 0;
    CopyDistinctNumbersToArray(arr, arr2, arrLength, arrLength2);
    cout << "[ Array 2 distinct elements ]    ";
    PrintArray(arr2, arrLength2);
    cout << "\n------------------------";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
