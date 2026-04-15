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

enum enWhatToCount
{
    SmallLetters = 1,
    CapitalLetters = 2,
    AllLetters = 3
};

short CountLetters(string str, enWhatToCount whatToCount = enWhatToCount::AllLetters)
{
    if (whatToCount == enWhatToCount::AllLetters)
        return str.length();
    short count = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (whatToCount == enWhatToCount::SmallLetters)
        {
            if (islower(str[i]))
                count++;
        }
        else if (whatToCount == enWhatToCount::CapitalLetters)
        {
            if (isupper(str[i]))
                count++;
        }
    }
    return count;
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #29 : Write a program to read a string then count small/capital letters in that string\n\n";
    cout << "\tex1  : please enter a String : fArS\n";
    cout << "\toutput : String Length             : 4\n\t\t Number of Small Letters   : 2\n \t\t Number of Capital Letters : 2";
    cout << "\n\n-------------------------------------------------\n\n";
    string str = ReadString("Please Enter a String: ");
    cout << "\nString Length             : " << CountLetters(str, enWhatToCount::AllLetters);
    cout << "\nNumber of Small Letters   : " << CountLetters(str, enWhatToCount::SmallLetters);
    cout << "\nNumber of Capital Letters : " << CountLetters(str, enWhatToCount::CapitalLetters);
    cout << "\n\n-------------------------------------------------\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
