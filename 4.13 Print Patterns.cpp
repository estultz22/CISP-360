#include <iostream>
using namespace std;

int main() {
    int numRows;
    char sharp = '#',
        asterisk = '*';
    bool invalidEntry = false;

    cout << "Enter number of rows (1 - 50 inclusive): ";
    cin >> numRows;

    invalidEntry = (numRows < 1 || numRows >= 50) ? true : false;

    while (invalidEntry)
    {
        cout << "Invalid input!!" << endl;
        if (numRows < 1)
           cout << "Number of rows cannot be less than 1." << endl;
        else
            cout << "Number of rows cannot be greater than 50." << endl;

        cout << "Enter number of rows (1 - 50 inclusive): ";
        cin >> numRows;

        invalidEntry = (numRows < 1 || numRows >= 50) ? true : false;

        if (invalidEntry == false)
        {
            break;
        }
    }

    for (int i = 0; i < numRows; ++i)
    {
      for (int j = numRows; j > i + 1; --j)
      {
         cout << asterisk;
      }
      cout << sharp;
      cout << endl;
    }

    return 0;
}
