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

void SumOf2Arrays(int arr1[], int arr2[], int arrSum[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arrSum[i] = arr1[i] + arr2[i];
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #30 : Write a program to fill array two arrays with max size 100 with random numbers from 1 to 100, sum their elements in a third array and print the results.\n ";
    cout << "\tex  : Enter how many randmon number to be created in array : 5\n\t=>\tArray 1 elements  : 73 73 70 70 18\n\t\tArray 2 elements  : 27 96 55 51 15\n\t\tSum of two arrays : 100 169 125 121 33 \n\n";
    cout << "------------------------\n\n";
    int arrLength = ReadPositiveNumber("Enter how many randmon number to be created in array : ");
    int arr[100];
    FillArrayWithRandomNumbers(arr, arrLength);
    cout << "[ Array 1 elements ] ";
    PrintArray(arr, arrLength);
    int arr2[100];
    FillArrayWithRandomNumbers(arr2, arrLength);
    cout << "[ Array 2 elements ] ";
    PrintArray(arr2, arrLength);
    int arrSum[100];
    SumOf2Arrays(arr, arr2, arrSum, arrLength);
    cout << "[ Sum of Array 1 and Array 2 elements ] ";
    PrintArray(arrSum, arrLength);
    cout << "\n------------------------";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
