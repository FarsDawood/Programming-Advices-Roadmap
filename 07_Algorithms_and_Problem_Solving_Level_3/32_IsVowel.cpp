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

bool IsVowel(char l)
{
    char lowerL = tolower(l);
    return (lowerL == 'a' || lowerL == 'e' || lowerL == 'i' || lowerL == 'o' || lowerL == 'u');
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #32 : Write a program to read a character and check if it is a vowel or not (Vowels are: a, e ,i ,u ,o).\n\n";
    cout << "\tex1  : please enter a character : f\n";
    cout << "\toutput : character is not a vowel\n\n";
    cout << "\tex2  : please enter a character : A\n";
    cout << "\toutput : character is a vowel\n";
    cout << "\n\n-------------------------------------------------\n\n";
    char letter = ReadChar("Please Enter a character: ");
    if (IsVowel(letter))
    {
        cout << "\nYes, Character " << letter << " is a vowel";
    }
    else
    {
        cout << "\nNo, Character " << letter << " is not a vowel";
    }
    cout << "\n\n-------------------------------------------------\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
