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

string ReverseWordsInString(string str)
{
    vector<string> vWords = SplitString(str);
    string sReversedString = "";
    vector<string>::iterator it = vWords.end();
    while (it != vWords.begin())
    {
        it--;
        sReversedString += *it + " ";
    }
    sReversedString = sReversedString.substr(0, sReversedString.length() - 1);
    return sReversedString;
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #41 : Write a program to read string and reverse its words.\n";
    cout << "\tex  : please enter your string: Fars Alaa Fawzy\n";
    cout << "\toutput : your string after reverse: Fawzy Alaa Fars\n";
    cout << "\n\n-------------------------------------------------\n\n";
    string str = ReadString("Please enter your string: ");
    cout << "\nYour string after reverse: " << ReverseWordsInString(str);
    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
