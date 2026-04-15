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

vector<string> SplitString(string S1, string delim = " ")
{
    short counter = 0;
    vector<string> vWords;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vWords.push_back(sWord);
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
    {
        vWords.push_back(S1);
    }
    return vWords;
}

string JoinString(vector<string> &vWords, string delim = " ")
{
    string sResult;
    for (string &word : vWords)
    {
        sResult += word + delim;
    }
    if (sResult.length() > 0)
    {
        sResult.erase(sResult.length() - delim.length());
    }
    return sResult;
}

string LowerAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}

string ReplaceWordInStringUsingSplit(string str, string wordToReplace, string wordToReplaceWith, bool matchCase = true)
{
    vector<string> vWords = SplitString(str);
    vector<string>::iterator it = vWords.begin();
    while (it != vWords.end())
    {
        if (matchCase)
        {
            if (*it == wordToReplace)
            {
                *it = wordToReplaceWith;
            }
        }
        else
        {
            if (LowerAllString(*it) == LowerAllString(wordToReplace))
            {
                *it = wordToReplaceWith;
            }
        }
        it++;
    }
    return JoinString(vWords);
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #43 : Write a program to replace words in string using custom function.\n";
    cout << "\tex  : \n\t\tinput :\n";
    cout << "\t\tplease enter your string   : ahmed Alaa Ahmed Fawzy\n";
    cout << "\t\tEnter word to replace      : ahmed\n";
    cout << "\t\tEnter word to replace with : Fars\n";
    cout << "\t\toutput : \n\t\tyour string after Replace with matchcase    : Fars Alaa Ahmed Fawzy";
    cout << "\n\t\tyour string after Replace without matchcase : Fars Alaa Fars Fawzy";
    cout << "\n\n-------------------------------------------------\n\n";
    string str = ReadString("Please enter your string: ");
    string wordToReplace = ReadString("Enter word to replace: ");
    string wordToReplaceWith = ReadString("Enter word to replace with: ");
    cout << "\nYour string after Replace with Matchcase: " << ReplaceWordInStringUsingSplit(str, wordToReplace, wordToReplaceWith);
    cout << "\nYour string after Replace without Matchcase: " << ReplaceWordInStringUsingSplit(str, wordToReplace, wordToReplaceWith, false);
    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
