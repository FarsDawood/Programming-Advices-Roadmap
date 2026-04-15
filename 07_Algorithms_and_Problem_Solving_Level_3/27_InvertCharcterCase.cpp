#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

char ReadChar(string message)
{
    char l;
    cout << message;
    cin >> l;
    return l;
}


char InvertLetterCase(char l)
{
    return (isupper(l) ? tolower(l) : toupper(l));
}
int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #27 : Write a program to read a character then invert it's case, and print it.\n\n";
    cout << "\tex1  : please enter a character : f\n";
    cout << "\toutput : character after inverting case: F\n\n";
    cout << "\tex2  : please enter a character : A\n";
    cout << "\toutput : character after inverting case: a\n";
    cout << "\n\n-------------------------------------------------\n\n";
    char letter = ReadChar("Please Enter a character: ");
    cout << "\nCharacter after inverting case : " << InvertLetterCase(letter);
    cout << "\n\n-------------------------------------------------\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
