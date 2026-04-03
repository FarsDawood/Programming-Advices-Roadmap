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
        cin.clear();             // مسح الخطأ
        cin.ignore(10000, '\n'); // تفريغ الذاكرة
        cout << "Invalid Input! Please enter a valid number: ";
        cin >> number;
    }
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

void PrintMiddleRow(int matrix[3][3], int rows, int cols)
{
    short middleRowIndex = rows / 2;
    cout << "The Middle Row is    : ";
    for (int j = 0; j < cols; j++)
    {
        printf("%02d\t", matrix[middleRowIndex][j]);
    }
}

void PrintMiddleCol(int matrix[3][3], int rows, int cols)
{
    short middleColIndex = cols / 2;
    cout << "The Middle Column is : ";
    for (int i = 0; i < rows; i++)
    {
        printf("%02d\t", matrix[i][middleColIndex]);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #09 : Write a program to fill a 3x3 matrix with random numbers, print it , then print the middle row and middle col.\n";
    cout << "\tex  : \n\t\t11  54  75\n\t\t78  98  25\n\t\t14  41  56\n\n";
    cout << "\n\t\tThe Middle Row is    : 78  98  25\n";
    cout << "\n\t\tThe Middle Column is : 54  98  56\n\n";
    cout << "\n\n-------------------------------------------------\n\n";
    int martrix[3][3];
    FillMatrixWithRandomNumbers(martrix, 3, 3);
    cout << "The Following is a 3x3 Matrix filled with Random Numbers : \n\n";
    PrintMatrix(martrix, 3, 3);
    PrintMiddleRow(martrix, 3, 3);
    cout << "\n\n";
    PrintMiddleCol(martrix, 3, 3);
    cout << "\n";
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
