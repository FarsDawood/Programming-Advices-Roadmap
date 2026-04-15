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

string UpperAllString(string word)
{
    for (short i = 0; i < word.length(); i++)
    {
        word[i] = toupper(word[i]);
    }
    return word;
}
string LowerAllString(string word)
{
    for (short i = 0; i < word.length(); i++)
    {
        word[i] = tolower(word[i]);
    }
    return word;
}
int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #26 : Write a program to read a string then upper all letters , then lower all letters , and print them.\n";
    cout << "\tex  : please enter your string : Fars alaa mostafa Dawood\n\n";
    cout << "\toutput : string after UpperCase : FARS ALAA MOSTAFA DAWOOD\n";
    cout << "\t         string after LowerCase : fars alaa mostafa dawood\n";
    cout << "\n\n-------------------------------------------------\n\n";
    string word = ReadString("Please Enter your String : ");
    cout << "\nString after Uppercase All letters : " << UpperAllString(word);
    cout << "\nString after Lowercase All letters : " << LowerAllString(word);
    cout << "\n\n-------------------------------------------------\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
