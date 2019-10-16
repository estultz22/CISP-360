#include <iostream>
#include <math.h>
using namespace std;
//main by Elijah Stultz
//09/03
int main()
{
    int userNum = 0;
    int userNum2;

    cout << "Enter integer:" << endl;
    cin  >> userNum;

    cout << "You entered: " << userNum << endl;
    cout << userNum << " squared is " << pow(userNum, 2) << endl;
    cout << "And " << userNum << " cubed is " << pow(userNum, 3) << "!!" << endl;

    cout << "Enter another integer: " << endl;
    cin >> userNum2;

    cout << userNum << "+" << userNum2 << " is " << userNum + userNum2 << endl;
    cout << userNum << "*" << userNum2 << " is " << userNum * userNum2 << endl;
   return 0;
}
