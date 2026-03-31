#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Lib.h"
using namespace std;
using namespace Lib;


int main()
{
    int x = Lib::ReadPositiveNumber("Enter Positive Number : ");
    int x2 = ReadNumber("",1,100);
    cout << "x = " << x << endl;
    cout << "x2 = " << x2 << endl;
    return 0;
}
