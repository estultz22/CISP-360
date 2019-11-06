#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;


//function definitions
void printMenu();
void printList(string *, int);
void sort(string *, int);
void insertAtZero(string *, string, int);
void insertAtEnd(string *, string, int);
bool insertAt(string *, string, int, int);
bool removeFrom(string *, int, int);
bool removeFromEnd(string *, int);
string *expand(string *, int &);
string getString();
int getInt();
int getMenuInput();


int main()
{
    int asize = 2, //initialize to 2
        count = 0, //initialize to 0
        userIndex, 
        inputInt, 
        quitInt = 8;
    
    string newItem,
           *array = new string[asize];// {"Foo", "Bar", "Test", "Testz", "Testa"}; //debugging strings

    bool isRemoved,
         isIValid;

    do
    {
        printMenu();
        cout << "Enter your choice: ";
        inputInt = getMenuInput();

        isRemoved = false;
        isIValid = false;

        if (inputInt < 1 || inputInt > 8)
            cout << "Invalid choice!! Enter a valid choice.\n";
        else if (inputInt == 8)
            cout << "Thank you for using the program!! Good bye!";

        if (count == asize)
        {
            array = expand(array, asize);
        }

        if(inputInt == 7)
        {
            printList(array, asize);
        }
        else if (inputInt == 4)//remove last element from array
        {
            isRemoved = removeFromEnd(array, count);

            if (isRemoved)
                count--;
            else
                cout << "Cannot remove from an empty list...\n";
              
        }
        else if (inputInt == 5)//remove item in array from given index
        {
            userIndex = getInt();
            isRemoved = removeFrom(array, userIndex, count);

            if(isRemoved)
                count--;
            else
                cout << "Cannot remove item from index " << userIndex << " of list...\n";
        }
        else if (inputInt == 2) //insert at element zero
        {
            if (count == asize)
                array = expand(array, asize);

            newItem = getString();
            insertAtZero(array, newItem, count);

            count++;
        }
        else if (inputInt == 1) //insert at last element
        {
            if (count == asize)
                array = expand(array, asize);
            
            newItem = getString();
            insertAtEnd(array, newItem, count);
            
            count++;
        }
        else if (inputInt == 3)//insert at given index
        {
            newItem = getString();
            userIndex = getInt();
            isIValid = insertAt(array, newItem, userIndex, count);

            //only increments if the insert was valid
            if(isIValid)
                count++;
        }
        else if (inputInt == 6)//sort
        {
            sort(array, count);
        }
    }while (inputInt != quitInt); 
    
    //always delete dynamically allocated variables
    delete[] array;

    return 0;
}


//shows all the menu options
void printMenu()
{
   cout << "Please choose from the following menu choices:\n";
   cout << "1) Insert a new element to the end of the list.\n" <<
            "2) Insert a new element at the beginning of the list.\n" <<
            "3) Insert an element into the list at a given index.\n" <<
            "4) Remove an element from the end of the list.\n" <<
            "5) Remove an element from the list at a given index.\n" <<
            "6) Sort the list.\n" << 
            "7) Print the contents of the list.\n" <<
            "8) Exit.\n";
}

//gets a single int
int getMenuInput()
{
    int input;

    cin >> input;

    return input;
}

//prints array using pointer notation
void printList(string *list, int listSize)
{
    cout << "The list contains: \n";

    for (int index = 0; index < listSize; index++)
    {
        cout << *(list + index) << " ";
    }

    cout << endl;
}

//gets last index of an item and removes it
bool removeFromEnd(string *p, int count)
{
    bool isRemoved = false;
    int lastIndex = (count != 0) ? count - 1 : 1;

    if (*(p + lastIndex) != "")
    {
        *(p + lastIndex) = "";
        isRemoved = true;
    }
   
    return isRemoved;
}

//shifts every index one to the right and inserts new string into 0th element
void insertAtZero(string *p, string item, int count)
{
    string *newItem = new string(item);
    int i;  

    // shift elements forward 
    for (i = count; i >= 1; i--) 
        *(p + i) = *(p + i - 1); 

    *p = *newItem;

    delete newItem;
}

//gets a single string from input and returns it
string getString()
{
    string item;

    cout << "Enter string: ";
    cin.ignore();
    getline(cin, item);

    return item;
}

//creates a new array, copies all old array contents onto it and returns pointer for the new array 
string *expand(string *p, int &size)
{
    int i;
    string *newArray = new string[size * 2];
    
    for (i = 0; i < size; i++)
        *(newArray + i) = *(p + i);
    
    delete[] p;

    size *= 2;

    return newArray;
}

bool insertAt(string *p, string item, int index, int count)
{
    bool isIndexValid = false;

    string *newItem = new string(item);
    
    if (index == 0)
        insertAtZero(p, item, count);

    if (index > 0 && index < count)
    {
        isIndexValid = true;
        
        int i;

        for (i = count; i >= index; i--) 
            *(p + i) = *(p + i - 1); 

        *(p + index) = *newItem;
    }

    delete newItem;

    return isIndexValid;
}

void insertAtEnd(string *p, string item, int count)
{
    string *newItem = new string(item);

    *(p + count) = *newItem;

    delete newItem;
}

bool removeFrom(string *p, int index, int count)
{
    bool isIndexValid = false;
    
    if (index > 0 && index < count)
    {
        isIndexValid = true;

        int i;

        for (i = index; i < count; i++) 
            *(p + i) = *(p + i + 1); 
    }

    return isIndexValid;     
}

int getInt()
{
    int item;

    cout << "Enter index: ";
    cin >> item;

    return item;
}

//bubble sort because why not
void sort(string *p, int count)
{
    int i, 
        j;
    string temp;

    for (i = 0; i < count; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (*(p + j) > *(p + j + 1))
            {
                temp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = temp;
            } 
        }
    }            
}