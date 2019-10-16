#include <iostream>
#include <cstdlib>
using namespace std;
/*
Activity 7: Math Quiz with Random Number Simulation
by Elijah Stultz, CISP 360, September 19th, 2019
*/
int main()
{
    int randNum1,
        randNum2,
        randNumProduct,
        userInput;
    bool correctProduct = false;
    while (userInput >= 0)
    {
        randNum1 = (rand() % 12) + 1;
        randNum2 = (rand() % 12) + 1;

        cout << "How much is " << randNum1 << " times " << randNum2 << "? ";
        cin >> userInput;

        if (userInput < 0)
            break;

        randNumProduct = randNum1 * randNum2;

        if (userInput == randNumProduct)
            cout << "Very good!\n";
        else
        {
            correctProduct = (userInput == randNumProduct) ? true : false;
            while (!correctProduct)
            {
               cout << "Incorrect Answer. Please try again. \n";
               cout << "How much is " << randNum1 << " times " << randNum2 << "? \n";

               cin >> userInput;

               correctProduct = (userInput == randNumProduct) ? true : false;
               if (correctProduct)
               {
                 cout << "Very good!\n";
                 break;
               }

            }
        }
    }
    return 0;
}