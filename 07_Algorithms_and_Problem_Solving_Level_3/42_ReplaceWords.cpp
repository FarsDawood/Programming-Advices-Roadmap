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

string ReplaceWordInStringUsingBuiltInFunction(string str, string wordToReplace, string wordToReplaceWith)
{
    short pos = 0;
    pos = str.find(wordToReplace);
    while (pos != std::string::npos)
    {
        str.replace(pos, wordToReplace.length(), wordToReplaceWith);
        pos = str.find(wordToReplace);
    }
    return str;
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #42 : Write a program to replace words in string.\n";
    cout << "\tex  : \n\t\tinput :\n";
    cout << "\t\tplease enter your string   : ahmed Alaa ahmed Fawzy\n";
    cout << "\t\tEnter word to replace      : ahmed\n";
    cout << "\t\tEnter word to replace with : Fars\n";
    cout << "\t\toutput : \n\t\tyour string after Replace  : Fars Alaa Fars Fawzy";
    cout << "\n\n-------------------------------------------------\n\n";
    string str = ReadString("Please enter your string: ");
    string wordToReplace = ReadString("Enter word to replace: ");
    string wordToReplaceWith = ReadString("Enter word to replace with: ");
    cout << "\nYour string after Replace: " << ReplaceWordInStringUsingBuiltInFunction(str, wordToReplace, wordToReplaceWith);
    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
