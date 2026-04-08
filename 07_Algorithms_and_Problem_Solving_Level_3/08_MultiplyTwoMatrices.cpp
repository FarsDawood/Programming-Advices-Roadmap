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
            matrix[i][j] = RandomNumber(1, 10);
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

void MultiplyMatrix(int matrix1[3][3], int matrix2[3][3], int resultMatrix[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            resultMatrix[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #08 : Write a program to fill two 3x3 matrix with random numbers and them, multiply them into a 3rd matrix and print it.\n ";
    cout << "\t\tThe Following is the First Matrix :\n";
    cout << "\tex  : \n\t\t10       8       4\n\t\t2       1       4\n\t\t2       5       6\n\n";
    cout << "\t\tThe Following is the Second Matrix :\n";
    cout << "\n\t\t10       7       5\n\t\t5       8       6\n\t\t7       3       9\n\n";
    cout << "\t\tThe Following is the Result of Multiplying the First Matrix with the Second Matrix :\n";
    cout << "\n\t\t100      56      20\n\t\t10       8      24\n\t\t14      15      54\n\n";
    cout << "\n\n-------------------------------------------------\n\n";
    int martrix[3][3], martrix2[3][3];
    FillMatrixWithRandomNumbers(martrix, 3, 3);
    FillMatrixWithRandomNumbers(martrix2, 3, 3);
    cout << "The Following is the First Matrix : \n\n";
    PrintMatrix(martrix, 3, 3);
    cout << "\nThe Following is the Second Matrix : \n\n";
    PrintMatrix(martrix2, 3, 3);
    int resultMatrix[3][3];
    MultiplyMatrix(martrix, martrix2, resultMatrix, 3, 3);
    cout << "\nThe Following is the Result of Multiplying the First Matrix with the Second Matrix : \n\n";
    PrintMatrix(resultMatrix, 3, 3);
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
