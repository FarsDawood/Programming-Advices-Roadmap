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


string UpperFirstLetterOfEachWord(string word)
{
    bool isFirstLetter = true;
    for (short i = 0; i < word.length(); i++)
    {
        if (word[i] != ' ' && isFirstLetter)
        {
            word[i] = toupper(word[i]);
        }
        isFirstLetter = (word[i] == ' ' ? true : false);
    }
    return word;
}
int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #24 : Write a program to read a string then uppercase the first letter of each word in that string\n";
    cout << "\tex  : please enter your string : Fars alaa mostafa Dawood\n\n";
    cout << "\toutput : String after conversion: Fars Alaa Mostafa Dawood\n";
    cout << "\n\n-------------------------------------------------\n\n";
    string word = ReadString("Please Enter your String : ");
    string result = UpperFirstLetterOfEachWord(word);
    cout << "\nString after conversion : " << result;
    cout << "\n\n-------------------------------------------------\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
