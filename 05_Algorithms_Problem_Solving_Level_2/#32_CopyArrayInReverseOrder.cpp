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

void FillArrayWith1toN(int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = i + 1;
}

void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arrDestination[i] = arrSource[arrLength - 1 - i];
    }
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #32 : Write a program to fill array with max size 100 with random numbers from 1 to 100, copy it to another array in reverse order and print it.\n";
    cout << "\tex  : Enter how many number to be created in array : 5\n\t=>\tArray 1 elements : 1 2 3 4 5\n\t\tArray 2 elements : 5 4 3 2 1\n\n";
    cout << "------------------------\n\n";
    int arrLength = ReadPositiveNumber("Enter how many number to be created in array : ");
    int arr[100];
    FillArrayWith1toN(arr, arrLength);
    cout << "[ Array 1 elements ] ";
    PrintArray(arr, arrLength);
    int arrReversed[100];
    CopyArrayInReverseOrder(arr, arrReversed, arrLength);
    cout << "[ Array 2 elements ] ";
    PrintArray(arrReversed, arrLength);
    cout << "\n------------------------";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
