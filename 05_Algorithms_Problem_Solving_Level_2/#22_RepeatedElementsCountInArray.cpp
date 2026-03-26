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

void ReadArray(int arr[], int &arrLength)
{
    cout << "\n\n-----------------------\n\n";
    arrLength = ReadPositiveNumber("Enter how many elements in array : ");
    cout << "\nEnter array elements: \n";
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
    cout << "\n-----------------------\n\n";
}
void PrintArray(int arr[], int arrLength)
{
    cout << "Array elements: ";
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int TimesRepeated(int Number, int arr[100], int arrLength)
{
    int count = 0;
    for (int i = 0; i <= arrLength - 1; i++)
    {
        if (Number == arr[i])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #05 : Write a program to read N elements and store them in array then print all array elements and ask  \n\t      for a number to check, then print how many number a certain element repeated in that array.\n";
    cout << "\tex  :   Enter how many elements in array : 3\n\t\tEnter array elements: \n\t\t\tElement[1] : 1 \n\t\t\tElement[2] : 1 \n\t\t\tElement[3] : 2\n\t\tEnter the number you want to check : 1\n\t\tArray elements: 1 1 2 \n\t\tNumber[1] is repeated[2] time(s)\n\n ";
    int arrLength;
    int arr[1000];
    ReadArray(arr, arrLength);

    cout << "\n\n-----------------------\n\n";
    int NumberToCheck = ReadPositiveNumber("Enter the number you want to check : ");

    PrintArray(arr, arrLength);
    cout << "Number [ " << NumberToCheck << " ] is repeated [ " << TimesRepeated(NumberToCheck, arr, arrLength) << " ] time(s)";
    cout << "\n\n-----------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
