#ifndef CONTACTNODE_H
#define CONTACTNODE_H

#include <string>

class ContactNode
{
    public:
        ContactNode(std::string name, std::string phoneNum);//done
        ~ContactNode();//done
        void InsertAfter(ContactNode* nextPtr);
        std::string GetName(); //done
        std::string GetPhoneNumber();//done
        ContactNode* GetNext();//done
        void PrintContactNode();//done

    private:
        std::string contactName, contactPhoneNum;
        ContactNode* nextNodePtr;

};

#endif // CONTACTNODE_H
