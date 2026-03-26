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

void AddArrayElement(int number, int arr[], int &arrLength)
{
    if (arrLength >= 100)
        return;
    arr[arrLength] = number;
    arrLength++;
}

void InputUserNumbersInArray(int arr[], int &arrLength)
{
    bool addMore = true;
    do
    {
        if (arrLength == 100)
        {
            cout << "Array is full, can't add more numbers.\n";
            break;
        }

        AddArrayElement(ReadPositiveNumber("Enter Positive Number : "), arr, arrLength);
        short addMoreAsk = 0;
        do
        {
            cout << "Do you want to add more number (0,1) ? Yes[1] No[0] : ";
            cin >> addMoreAsk;
            if (addMoreAsk == 0)
                addMore = false;
            else if (addMoreAsk != 1)
                cout << "Invalid Choice, try again.\n";
        } while (addMoreAsk != 0 && addMoreAsk != 1);

    } while (addMore);
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #36 : Write a program to dynamically read numbers and save them in an array Max size of array is 100, allocate simi - dynamic array length.\n ";
    cout << "\tex  :   Enter Positive Number : 10\n\t\tDo you want to add more number (0,1) ? Yes[1] No[0] : 1\n\t\tEnter Positive Number : 50\n\t\tDo you want to add more number(0, 1) ? Yes[1] No[0] : 0\n\t\tArray elements : 10 50\n\n ";
    int arr[100];
    int arrLength = 0;
    cout << "------------------------\n\n";
    InputUserNumbersInArray(arr, arrLength);
    PrintArray(arr, arrLength);
    cout << "\n------------------------";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
