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

void CopyOddNumbers(int arrSource[], int arrDestination[], int arrLength, int &arrLength2)
{
    for (int i = 0; i < arrLength; i++)
        if (arrSource[i] % 2 == 1)
            AddArrayElement(arrSource[i], arrDestination, arrLength2);
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #38 : Write a program to fill array with max size 100 with random numbers from 1 to 100, copy only odd numbers to another array using AddArrayElement, and print it.\n ";
    cout << "\tex  : Enter how many randmon number to be created in array : 5\n\t=>\tArray 1 elements : 41 30 88 94 4 \n\t\tArray 2 elements after copy Odd numbers : 41 \n\n";

    cout << "------------------------\n\n";
    int arr[100], arrLength = ReadPositiveNumber("Enter how many randmon number to be created in array : ");
    FillArrayWithRandomNumbers(arr, arrLength);
    PrintArray(arr, arrLength);
    cout << "[ Array 1 elements before copy ] ";
    PrintArray(arr, arrLength);
    int arr2[100], arrLength2 = 0;
    CopyOddNumbers(arr, arr2, arrLength, arrLength2);
    cout << "[ Array 2 elements after  copy Odd numbers] ";
    PrintArray(arr2, arrLength2);
    cout << "\n------------------------";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
