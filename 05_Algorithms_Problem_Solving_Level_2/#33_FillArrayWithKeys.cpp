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

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void PrintStringArray(string arr[100], int arrLength)
{
    cout << "\nArray elements :\n";
    for (int i = 0; i < arrLength; i++)
    {
        cout << "\tArray[" << i << "] : ";
        cout << arr[i] << "\n";
    }
    cout << "\n";
}

enum enCharType
{
    SamallLetter = 1,
    CapitalLetter = 2,
    SpecialCharacter = 3,
    Digit = 4
};

char GetRandomCharacter(enCharType CharType)
{
    char character;
    switch (CharType)
    {
    case SamallLetter:
        character = RandomNumber('a', 'z');
        break;
    case CapitalLetter:
        character = RandomNumber('A', 'Z');
        break;
    case SpecialCharacter:
        character = RandomNumber(33, 47);
        break;
    case Digit:
        character = RandomNumber('0', '9');
        break;
    default:
        character = '?';
        break;
    }
    return character;
}

string GenerateWord(enCharType CharType, int WordLength)
{
    string word = "";
    for (int i = 0; i < WordLength; i++)
    {
        word += GetRandomCharacter(CharType);
    }
    return word;
}

string GenerateKey()
{
    string key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key += GenerateWord(enCharType::CapitalLetter, 4);
    return key;
}

void FillArrayWithKeys(string arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = GenerateKey();
    }
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #33 : Write a program to read how many keys to generate and fill them in array then print them on the screen.\n ";
    cout << "\tex  : Enter how many number to be created in array : 2\n\t=>\tArray elements : \n\t\t\tArray[0] : CCEF-FWFP-VKFE-SONL\n\t\t\tArray[1] : UTPQ-XTRO-IJVH-ISEG\n\n";
    cout << "------------------------\n\n";
    int arrLength = ReadPositiveNumber("Enter how many number to be created in array : ");
    string arr[100];
    FillArrayWithKeys(arr, arrLength);
    PrintStringArray(arr, arrLength);
    cout << "------------------------";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
