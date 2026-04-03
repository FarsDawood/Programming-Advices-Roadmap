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

int RowSum(int matrix[3][3], int rowNumber, int cols)
{
    int sum = 0;
    for (int j = 0; j < cols; j++)
    {
        sum += matrix[rowNumber][j];
    }
    return sum;
}

void SumMatrixRowsInArray(int matrix[3][3], int rowsRum[3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        rowsRum[i] = RowSum(matrix, i, cols);
    }
}

void PrintRowsSumArray(int arrRowsSum[3])
{
    cout << "The Following are the sume of each row in matrix : \n\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "\tRow " << i + 1 << " Sum = " << arrRowsSum[i] << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #03 : Write a program to fill a 3x3 matrix with random numbers, then sum each row in separate array and print the results :\n ";
    cout << "\tex  : \n\t\t59      90      42\n\t\t49      28       4\n\t\t84      88      82\n\n";
    cout << "\t\tRow 1 Sum = 191\n\t\tRow 2 Sum = 81\n\t\tRow 3 Sum = 254";
    cout << "\n\n-------------------------------------------------\n\n";
    int martrix[3][3];
    FillMatrixWithRandomNumbers(martrix, 3, 3);
    PrintMatrix(martrix, 3, 3);
    int rowsSum[3];
    SumMatrixRowsInArray(martrix, rowsSum, 3, 3);
    PrintRowsSumArray(rowsSum);
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
