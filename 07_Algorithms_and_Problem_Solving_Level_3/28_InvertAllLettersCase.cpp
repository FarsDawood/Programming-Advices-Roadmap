#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string ReadString(string message)
{
    string l;
    cout << message;
    getline(cin, l);
    return l;
}

char InvertLetterCase(char l)
{
    return (isupper(l) ? tolower(l) : toupper(l));
}

string InvertAllStringLettersCase(string str)
{

    for (size_t i = 0; i < str.length(); i++)
    {
        str[i] = InvertLetterCase(str[i]);
    }
    return str;
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #28 : Write a program to read a string then invert all its letter's case an print it.\n\n";
    cout << "\tex1  : please enter a String : fArS DawooD\n";
    cout << "\toutput : String after inverting all letters case: FaRs dAWOOd\n\n";
    cout << "\n\n-------------------------------------------------\n\n";
    string str = ReadString("Please Enter a String: ");
    cout << "String after inverting all letters case: " << InvertAllStringLettersCase(str);
    cout << "\n\n-------------------------------------------------\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
