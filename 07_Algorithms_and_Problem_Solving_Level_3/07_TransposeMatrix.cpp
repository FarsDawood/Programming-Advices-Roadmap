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

void FillMatrixWithOrderedNumbers(int matrix[3][3], int rows, int cols)
{
    short counter = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = counter++;
        }
    }
}

void PrintMatrix(int matrix[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

void TransposeMatrix(int matrix[3][3], int transposedMatrix[3][3], int rows, int cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #07 : Write a program to fill a 3x3 matrix with ordered numbers and print it, then transpose matrix and print it\n";
    cout << "\tex  : \n\t\t1       2       3\n\t\t4       5       6\n\t\t7       8       9\n\n";
    cout << "\tThe Following is the Transposed Matrix : \n\t\t1       4       7\n\t\t2       5       8\n\t\t3       6       9\n\n";
    cout << "\n\n-------------------------------------------------\n\n";
    int martrix[3][3];
    FillMatrixWithOrderedNumbers(martrix, 3, 3);
    cout << "The Following is a 3x3 Matrix filled with ordered Numbers : \n\n";
    PrintMatrix(martrix, 3, 3);
    int transposedMatrix[3][3];
    TransposeMatrix(martrix, transposedMatrix, 3, 3);
    cout << "\nThe Following is the Transposed Matrix : \n\n";
    PrintMatrix(transposedMatrix, 3, 3);
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
