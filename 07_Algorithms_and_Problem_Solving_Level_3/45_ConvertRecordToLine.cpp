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

stClient ReadNewClient()
{
    stClient Client;
    cout << "Enter Account Number? ";
    getline(cin, Client.AccountNumber);
    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    return Client;
}

string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}

string ReadString(string message)
{
    string word;
    cout << message;
    getline(cin, word);
    return word;
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #45 : Write a program to read bank client data record and convert it to one line\n";
    cout << "\tex  : \n\t\tinput :\n";
    cout << "\t\tEnter Accoutn Number? 12345\n";
    cout << "\t\tEnter PinCode? 54321\n";
    cout << "\t\tEnter Name? Ahmed Alaa\n";
    cout << "\t\tEnter Phone? 01000000000\n";
    cout << "\t\tEnter AccountBalance? 1000\n";
    cout << "\t\toutput : \n\t\tyour string after convert record to line : 12345#//#54321#//#Ahmed Alaa#//#01000000000#//#1000.000000";
    cout << "\n\n-------------------------------------------------\n\n";
    stClient Client = ReadNewClient();
    cout << "\nYour string after convert record to line : " << ConvertRecordToLine(Client);
    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
