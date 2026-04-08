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

bool IsScalarMarix(int matrix1[3][3], int rows, int cols)
{
    int scalarValue = matrix1[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == j)
            {
                if (matrix1[i][j] != scalarValue)
                {
                    return false;
                }
            }
            else
            {
                if (matrix1[i][j] != 0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #14 : Write a program to check if the matrix is Scalar or not.\n";
    cout << "\tex  : \n\t\t3   0   0\n\t\t0   3   0\n\t\t0   0   3\n\n";
    cout << "\n\t\tOutput : The Matrix is Scalar Matrix.\n\n";
    cout << "\n\n-------------------------------------------------\n\n";
    int martrix[3][3];
    FillMatrixWithRandomNumbers(martrix, 3, 3);
    cout << "Matrix 1: \n\n";
    PrintMatrix(martrix, 3, 3);
    if (IsScalarMarix(martrix, 3, 3))
    {
        cout << "\nThe Matrix is Scalar Matrix.\n";
    }
    else
    {
        cout << "\nThe Matrix is Not Scalar Matrix.\n";
    }
    int martrix2[3][3] = {{3, 0, 0}, {0, 3, 0}, {0, 0, 3}};
    cout << "Matrix 2: \n\n";
    PrintMatrix(martrix2, 3, 3);
    if (IsScalarMarix(martrix2, 3, 3))
    {
        cout << "\nThe Matrix is Scalar Matrix.\n";
    }
    else
    {
        cout << "\nThe Matrix is Not Scalar Matrix.\n";
    }
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
