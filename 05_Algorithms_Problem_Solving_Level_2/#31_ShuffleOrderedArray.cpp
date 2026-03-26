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

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void ShuffleArray(int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        int index1 = RandomNumber(0, arrLength - 1);
        int index2 = RandomNumber(0, arrLength - 1);
        Swap(arr[index1], arr[index2]);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #31 : Write a program to fill array with ordered numbers from 1 to N, then print it, after that shuffle this array and print it after shuffle.\n";
    cout << "\tex  : Enter how many number to be created in array : 5\n\t=>\tArray elements before suffle : 1 2 3 4 5\n\t\tArray elements after suffle  : 3 1 4 2 5 \n\n";
    cout << "------------------------\n\n";
    int arrLength = ReadPositiveNumber("Enter how many number to be created in array : ");
    int arr[100];
    FillArrayWith1toN(arr, arrLength);
    cout << "[ Array elements before suffle ] ";
    PrintArray(arr, arrLength);
    ShuffleArray(arr, arrLength);
    cout << "[ Array elements after  suffle ] ";
    PrintArray(arr, arrLength);
    cout << "\n------------------------";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
