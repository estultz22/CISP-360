#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;
/*Cell wall by Elijah Stultz
CISP 360, September 11, 2019
*/

int main()
{
    //variable initialization
    int menuOption;
    double coordX,
           coordY;
    const int RADIUS = 10;
    bool valid, onCircle, inCircle;

    //initialize random number generator
    srand(2018);

    //main menu asks for option 1 or 2
    cout << "1) Enter coordinate of particle" << endl;
    cout << "2) Generate random particle" << endl;
    cin >> menuOption;
    
    //if 1 was chosen, do this.. if 2 do that
    switch (menuOption)
    {
        case 1:
        //user input
            cout << "x: ";
            cin >> coordX;
            cout << "y: ";
            cin >> coordY;

            valid = true;
            break;
        case 2:
        //generates two random numbers between 0 and 20
            coordX = (rand() % 21);
            coordY = (rand() % 21);

            cout << '(' << coordX << ',' << coordY << ')' << endl;

            valid = true;
            break;
        default:
            valid = false;
            break;
    }

    //tests the two coordinates in radius equation and returns a bool value
    onCircle = (abs(sqrt((coordX * coordX) + (coordY * coordY)) - RADIUS) < 0.01) ? true : false;
    inCircle = (sqrt(pow(coordX, 2) + pow(coordY, 2)) < RADIUS) ? true : false;


    if (valid)
    {
        if (onCircle)
            cout << "On";
        else if (inCircle)
            cout << "In";
        
        else
            cout << "Out";
    }
    else
    {
        cout << "Error";
        return 1;
    }
        

    return 0;
}