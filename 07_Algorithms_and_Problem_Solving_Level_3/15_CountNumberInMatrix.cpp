#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int ReadPositiveNumber(string message)
{

    int number;
    cout << message;
    cin >> number;

    while (cin.fail())
    {
        cin.clear();             
        cin.ignore(10000, '\n'); 
        cout << "Invalid Input! Please enter a valid number: ";
        cin >> number;
    }
    return number;
}

string ReadString(string message)
{
    string word;
    cout << message;
    cin >> word;
    return word;
}

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int matrix[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int matrix[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        cout << "\t";
        for (int j = 0; j < cols; j++)
        {
            printf("%02d\t", matrix[i][j]);
        }
        cout << endl;
    }
}

int CountNumberInMatrix(int matrix1[3][3], int number, int rows, int cols)
{
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix1[i][j] == number)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #15 : Write a program to count given number in matrix.\n";
    cout << "\tex  : \n\t\t2   3   2\n\t\t5   2   1\n\t\t11   2   33\n\n";
    cout << "\n\t\tInput : Enter number to count : 2\n\n";
    cout << "\n\t\tOutput : The Number 2 is found 4 times in the matrix.\n\n";
    cout << "\n\n-------------------------------------------------\n\n";
    int martrix[3][3];
    FillMatrixWithRandomNumbers(martrix, 3, 3);
    cout << "Matrix 1: \n\n";
    PrintMatrix(martrix, 3, 3);
    int number = ReadPositiveNumber("\nEnter number to count : ");
    int count = CountNumberInMatrix(martrix, number, 3, 3);
    cout << "\nThe Number " << number << " is found " << count << " times in the matrix.\n";
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
