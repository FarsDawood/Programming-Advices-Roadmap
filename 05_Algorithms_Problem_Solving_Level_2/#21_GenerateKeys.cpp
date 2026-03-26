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
void GenerateKeys(short NumberOfKeys)
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        cout << "Key [" << i << "] : ";
        cout << GenerateKey() << "\n";
    }
    cout << "\n-------------------------------------------------------------------------------------------------\n\n";
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #05 : Write a program to read how many keys to generate and print them on the screen.\n ";
    cout << "\tex  : Enter how many Keys to be generated :  2  \n\t=>\t Key [1] : LCSJ-HHXW-DYJJ-JDQW\n\t\t Key [2] : DTIL-ZNMO-YMJF-HGHM\n\n ";
    int numberOfKeys = ReadPositiveNumber("Enter how many Keys to be generated : ");
    GenerateKeys(numberOfKeys);

    return 0;
}
