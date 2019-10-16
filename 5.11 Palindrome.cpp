#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string temp;

int main() {

    string userString;
    int firstLetter = 0, lastLetterIndex, spacePos;
    bool isPalindrome = false;

    getline(cin, userString);
    temp = userString;

    spacePos = temp.find(' ');

    while (spacePos != string::npos)
    {
        temp = temp.erase(spacePos, 1);
        spacePos = temp.find(' ');
    }

    lastLetterIndex = temp.length() - 1;
    while (lastLetterIndex > 0)
    {
        if (temp[firstLetter] == temp[lastLetterIndex])
        {
            temp = temp.erase(firstLetter, 1);
            temp = temp.erase(lastLetterIndex - 1, 1);
            lastLetterIndex = temp.length() - 1;

            if ((temp.length() == 1) || (temp.length() == 2))
            {
                isPalindrome = true;
                break;
            } 
        } 
        else
        {
            isPalindrome = false;
            break;
        } 
    }
    if (isPalindrome)
        cout << userString << " is a palindrome" << endl;
    else
    {
        cout << userString << " is not a palindrome" << endl;
    }

    return 0;
}

