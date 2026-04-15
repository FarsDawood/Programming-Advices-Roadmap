#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

string ReadString(string message)
{
    string word;
    cout << message;
    getline(cin, word);
    return word;
}

string RemovePunctuationsFromString(string str)
{
    string str2 = "";
    for (short i = 0; i < str.length(); i++)
    {
        if (!ispunct(str[i]))
        {
            str2 += str[i];
        }
    }
    return str2;
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #44 : Write a program to remove all punctuations from a string:\n";
    cout << "\tex  : \n\t\tinput :\n";
    cout << "\t\tplease enter your string             : ahmed# Alaa! Ahmed@ Fawzy\n";
    cout << "\t\toutput : \n\t\tyour string after remove puntuations : ahmed Alaa Ahmed Fawzy";
    cout << "\n\n-------------------------------------------------\n\n";
    string str = ReadString("Please enter your string: ");
    cout << "\nYour string after Replace remove punctuations: " << RemovePunctuationsFromString(str);
    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
