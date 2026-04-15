#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

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

stClient ConvertLinetoRecord(string str)
{
    vector<string> vClientData = SplitString(str, "#//#");
    stClient Client;
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);
    return Client;
}

void PrintClientRecord(stClient Client)
{
    cout << "\n\nThe following is the extracted client record:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #46 : Write a program to convert line data to record and print it.\n";
    cout << "\tex  : \n\t\tinput :\n";
    cout << "\t\tplease enter your string : 12345#//#54321#//#Ahmed Alaa#//#01000000000#//#1000.000000\n";
    cout << "\t\toutput : \n";
    cout << "\t\tAccoutn Number: 12345\n";
    cout << "\t\tPinCode: 54321\n";
    cout << "\t\tName: Ahmed Alaa\n";
    cout << "\t\tPhone: 01000000000\n";
    cout << "\t\tAccountBalance: 1000.000000\n";
    cout << "\n\n-------------------------------------------------\n\n";
    string str = ReadString("Please enter your Line: ");
    stClient Client = ConvertLinetoRecord(str);
    PrintClientRecord(Client);
    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
