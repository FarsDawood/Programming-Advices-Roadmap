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

short CountLetters(string str, char c, bool MatchCase = true)
{
    short count = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (MatchCase)
        {
            if (str[i] == c)
                count++;
        }
        else
        {
            if (tolower(str[i]) == tolower(c))
                count++;
        }
    }
    return count;
}
int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #31 : Write a proqram to read a strinq and read a character then count the character in that string (Match Case or Not)\n\n";
    cout << "\tex1  : please enter a String : fArS Dawood\n";
    cout << "\tinput : enter a character to count : a\n";
    cout << "\toutput : Number of 'a' in the string is        : 1";
    cout << "\n\t\t Number of 'a' or 'A' in the string is : 2";
    cout << "\n\n-------------------------------------------------\n\n";
    string str = ReadString("Please Enter a String: ");
    char c = ReadString("Enter a character to count: ")[0];
    cout << "\nNumber of '" << c << "' in the string is : " << CountLetters(str, c);
    cout << "\nNumber of '" << c << "' or '" << InvertLetterCase(c) << "' in the string is : " << CountLetters(str, c, false);
    cout << "\n\n-------------------------------------------------\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
