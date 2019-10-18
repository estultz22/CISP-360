#include <iostream>
using std::cout;
using std::cin;
using std::endl;


void getInput(int [], int);
void mode(int [], int, int&);

int main()
{
    int arraySize, modeNum = 0;
    
    cout << "Enter how many numbers you want tested: ";
    cin >> arraySize;
    cout << endl;

    int numArray[arraySize] = {0};

    getInput(numArray, arraySize);
    mode(numArray, arraySize, modeNum);

    cout << "The most common number is: " << modeNum;

    return 0;
}

void getInput(int arrayToInput[], int arrSize)
{
    for (int index = 0; index < arrSize; index++)
    {
        cout << "Input number " << index + 1 << ": ";
        cin >> arrayToInput[index];
    }
}

void mode(int arrayToParse[], int arrSize, int& numMode)
{
    int numOccurs, numMostOccurs = 0, numToReturn = 0;
    for (int index = 0; index < arrSize; index++)
    {
        numOccurs = 0;
        for (int jindex = 0; jindex < arrSize; jindex++)
        {
            if (arrayToParse[index] == arrayToParse[jindex])
                numOccurs++;
            if (numOccurs > numMostOccurs)
            {
                numMostOccurs = numOccurs;
                numToReturn = arrayToParse[index];
            }


        }
    }
    numMode = numToReturn;
}
