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



short CountLetters(string str, char c)
{
    short count = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
            count++;
    }
    return count;
}
int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #30 : Writea ro ram to read a string and read a character then count the character in that string\n\n";
    cout << "\tex1  : please enter a String : fArS Dawood\n";
    cout << "\tinput : enter a character to count : a\n";
    cout << "\toutput : Number of 'a' in the string is : 1";
    cout << "\n\n-------------------------------------------------\n\n";
    string str = ReadString("Please Enter a String: ");
    char c = ReadString("Enter a character to count: ")[0];
    cout << "\nNumber of '" << c << "' in the string is : " << CountLetters(str, c);
    cout << "\n\n-------------------------------------------------\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
