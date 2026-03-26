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

void FillArrayWithRandomNumbers(int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
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

void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arrDestination[i] = arrSource[i];
}
int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #28 : Write a program to fill array with max size 100 with random numbers from 1 to 100, copy it to another array and print it.\n ";
    cout << "\tex  : Enter how many randmon number to be created in array : 5\n\t=>\tArray 1 elements : 41 30 88 94 4 \n\t\tArray 2 elements after copy : 41 30 88 94 4\n\n";
    cout << "------------------------\n\n";
    int arrLength = ReadPositiveNumber("Enter how many randmon number to be created in array : ");
    int arr[100];
    FillArrayWithRandomNumbers(arr, arrLength);
    cout << "[ Array 1 elements before copy ] ";
    PrintArray(arr, arrLength);
    int arr2[100];
    CopyArray(arr, arr2, arrLength);
    cout << "[ Array 2 elements after copy ] ";
    PrintArray(arr2, arrLength);
    cout << "\n------------------------";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
