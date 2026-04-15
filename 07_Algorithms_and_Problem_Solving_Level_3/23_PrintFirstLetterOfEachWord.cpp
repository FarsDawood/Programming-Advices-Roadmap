#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string ReadString(string message)
{
    string word;
    cout << message;
    getline(cin, word);
    return word;
}

void PrintFirstLetterOfEachWord(string word)
{
    bool isFirstLetter = true;
    cout << "\nFirst letters of this string:  ";
    for (short i = 0; i < word.length(); i++)
    {
        if (word[i] != ' ' && isFirstLetter)
        {
            cout << word[i] << "  ";
        }
        isFirstLetter = (word[i] == ' ' ? true : false);
    }
}
int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #23 : Write a program to read a string then print the first letter of each word in that string\n";
    cout << "\tex  : please enter your string : Fars Alaa Mostafa\n\n";
    cout << "\toutput : First Letters of this string: F A M\n";
    cout << "\n\n-------------------------------------------------\n\n";
    string word = ReadString("Please Enter your String : ");
    PrintFirstLetterOfEachWord(word);
    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
