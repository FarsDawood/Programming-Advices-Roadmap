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
int SumOfMatrix(int matrix[3][3], int rows, int cols)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}

bool AreEqualMatrices(int matrix1[3][3], int matrix2[3][3], int rows, int cols)
{
    return SumOfMatrix(matrix1, rows, cols) == SumOfMatrix(matrix2, rows, cols);
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #11 : Write aprogram to compare two matrices and check if they are equal or not.\n";
    cout << "\tex  : \n\t\tMatrix 1\n\t\t11  54  75\n\t\t78  98  25\n\t\t14  41  56\n\n";
    cout << "\n\t\tMatrix 2\n\t\t11  54  75\n\t\t78  98  25\n\t\t14  41  56\n\n";
    cout << "\n\t\tOutput : The Two Matrices are Equal.\n\n";
    cout << "\n\n-------------------------------------------------\n\n";
    int martrix[3][3], martrix2[3][3];
    FillMatrixWithRandomNumbers(martrix, 3, 3);
    FillMatrixWithRandomNumbers(martrix2, 3, 3);
    cout << "Matrix 1: \n\n";
    PrintMatrix(martrix, 3, 3);
    cout << "Matrix 2: \n\n";
    PrintMatrix(martrix2, 3, 3);
    if (AreEqualMatrices(martrix, martrix2, 3, 3))
    {
        cout << "\nThe Two Matrices are Equal.\n";
    }
    else
    {
        cout << "\nThe Two Matrices are Not Equal.\n";
    }
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
