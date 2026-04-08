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
    cout << "The Following is a " << rows << "x" << cols << " Matrix filled with Random Numbers : \n\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

int ColSum(int matrix[3][3], int columnNumber, int rows)
{
    int sum = 0;
    for (int j = 0; j < rows; j++)
    {
        sum += matrix[j][columnNumber];
    }
    return sum;
}

void PrintEachColSum(int matrix[3][3], int rows, int cols)
{
    cout << "The Following are the sume of each column in matrix : \n\n";
    for (int i = 0; i < cols; i++)
    {
        cout << "\tColumn " << i + 1 << " Sum = " << ColSum(matrix, i, rows) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #04 : Write a program to fill a 3x3 matrix with random numbers, then print each column sum :\n ";
    cout << "\tex  : \n\t\t66      19      66\n\t\t66      38      24\n\t\t45      44      29\n\n";
    cout << "\t\tCol 1 Sum = 177\n\t\tCol 2 Sum = 101\n\t\tCol 3 Sum = 119";
    cout << "\n\n-------------------------------------------------\n\n";
    int martrix[3][3];
    FillMatrixWithRandomNumbers(martrix, 3, 3);
    PrintMatrix(martrix, 3, 3);
    PrintEachColSum(martrix, 3, 3);
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
