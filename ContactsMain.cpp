#include <iostream>
#include "ContactNode.h"

using namespace std;

void getNameAndNumber(string &, string& );

int main()
{
    int i = 0;
    ContactNode* headObj = nullptr; // Create intNode objects
    ContactNode* currObj = nullptr;
    ContactNode* lastObj = nullptr;

    string currName, currPhoneNum;

    cout << "Person " << i + 1 << "\n";
    getNameAndNumber(currName, currPhoneNum);

    headObj = new ContactNode(currName, currPhoneNum);
    lastObj = headObj;

    while (i < 2)
    {
        cout << "Person " << i + 2 << "\n";

        getNameAndNumber(currName, currPhoneNum);

        currObj = new ContactNode(currName, currPhoneNum);

        lastObj->InsertAfter(currObj); // Append curr
        lastObj = currObj;
        i++;
    }

    currObj = headObj;

    cout << "CONTACT LIST\n";
    while (currObj != nullptr)
    {
        currObj->PrintContactNode();
        currObj = currObj->GetNext();
        cout << endl;
    }

    delete headObj;
    return 0;
}

void getNameAndNumber(string &name, string &phoneNum)
{
    cout << "Enter name: \n";
    getline(cin, name);

    cout << "Enter phone number:\n";
    getline(cin, phoneNum);

    cout << "You entered: " << name << ", " << phoneNum;

    cout << endl << endl;
}
