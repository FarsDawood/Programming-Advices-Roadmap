#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
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

enum enPrimeNumber
{
    Prime = 1,
    NotPrime = 2
};

enPrimeNumber CheckPrime(int number)
{
    if (number == 1)
        return enPrimeNumber::NotPrime;

    int newNumber = sqrt(number); // sqrt better than number/2 because it is the biggest possible factor for a number
    for (int i = 2; i <= newNumber; i++)
    {
        if (number % i == 0)
        {
            return enPrimeNumber::NotPrime;
        }
    }
    return enPrimeNumber::Prime;
}
void CopyOnlyPrimaryNumbers(int arrSource[100], int arrDestination[100], int arrLength, int &arr2Length)
{
    arr2Length = 0;
    for (int i = 0; i < arrLength; i++)
        if (CheckPrime(arrSource[i]) == enPrimeNumber::Prime)
        {
            arrDestination[arr2Length] = arrSource[i];
            arr2Length++;
        }
}
int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #29 : Write a program to fill array with max size 100 with random numbers from 1 to 100, copy only prime numbers to another array and print it.\n ";
    cout << "\tex  : Enter how many randmon number to be created in array : 10\n\t=>\t[ Array 1 elements before copy ] Array elements : 6 1 80 15 21 29 14 88 5 65 \n\t\t[ Prime Numbers in Array 2 ] Array elements : 29 5\n\n";
    cout << "------------------------\n\n";
    int arrLength = ReadPositiveNumber("Enter how many randmon number to be created in array : ");
    int arr[100];
    FillArrayWithRandomNumbers(arr, arrLength);
    cout << "[ Array 1 elements before copy ] ";
    PrintArray(arr, arrLength);
    int arr2[100], arr2Length;
    CopyOnlyPrimaryNumbers(arr, arr2, arrLength, arr2Length);
    cout << "[ Prime Numbers in Array 2 ] ";
    PrintArray(arr2, arr2Length);
    cout << "\n------------------------";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
