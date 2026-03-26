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

int MaxNumberInArray(int arr[], int arrLength)
{
    int maxNum = arr[0];
    for (int i = 1; i < arrLength; i++)
    {
        if (arr[i] > maxNum)
        {
            maxNum = arr[i];
        }
    }
    return maxNum;
}
int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #24 : Write a program to fill array with max size 100 with random numbers from 1 to 100, then print Max\n";
    cout << "\tex  : Enter how many randmon number to be created in array : 5\n\t=>\tArray elements : 41 30 88 94 4 \n\t\tMax number in array is : 94\n\n";
    cout << "------------------------\n\n";
    int arrLength = ReadPositiveNumber("Enter how many randmon number to be created in array : ");
    int arr[100];
    FillArrayWithRandomNumbers(arr, arrLength);
    PrintArray(arr, arrLength);
    cout << "Max number in array is : " << MaxNumberInArray(arr, arrLength) << endl;
    cout << "\n------------------------";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
