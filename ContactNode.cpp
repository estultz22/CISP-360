#include "ContactNode.h"
#include <iostream>
using std::string;

ContactNode::ContactNode(string name, string phoneNum)
{
    this->contactName = name;
    this->contactPhoneNum = phoneNum;
    this->nextNodePtr = nullptr;
}

//destuctor
ContactNode::~ContactNode()
{
    delete this->nextNodePtr;
}

string ContactNode::GetName()
{
    return this->contactName;
}

string ContactNode::GetPhoneNumber()
{
    return this->contactPhoneNum;
}

ContactNode* ContactNode::GetNext()
{
    return this->nextNodePtr;
}

void ContactNode::PrintContactNode()
{
    std::cout << "Name: " << this->contactName << std::endl;
    std::cout << "Phone number: " << this->contactPhoneNum << std::endl;
}

void ContactNode::InsertAfter(ContactNode* nextPtr)
{
    ContactNode* temp = nullptr;

    temp = this->nextNodePtr;
    this->nextNodePtr = nextPtr;
    nextPtr->nextNodePtr = temp;
}
