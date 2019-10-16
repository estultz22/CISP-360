#include <iostream>
using namespace std;

/*Color mixer by Elijah Stultz September 12, 2019
This program inputs two rby colors from the user,
validates both, and outputs the secondary color */

int main()
{   //variable initialization
    string color1, color2, secondaryColor;
    bool purple, orange, green;

    //gets the two primary colors from the user and checks if either are invalid
    cout << "Please enter either red, blue, or yellow: ";
    cin >> color1;

    if (color1 != "blue" && color1 != "red" && color1 != "yellow")
    {
        cout << "Not a valid color!";
        return 1;
    }

    cout << "Enter a second color: ";
    cin >> color2;

    if (color2 != "blue" && color2 != "red" && color2 != "yellow")
    {
        cout << "The second color is not valid!";
        return 2;
    }
    //the respective secondary color returns a true if the two primary colors match, else it returns false
    else
    {
        purple = (color1 == "red" && color2 == "blue") || (color1 == "blue" && color2 == "red") ? true : false;
        orange = (color1 == "red" && color2 == "yellow") || (color1 == "yellow" && color2 == "red") ? true : false;
        green = (color1 == "yellow" && color2 == "blue") || (color1 == "blue" && color2 == "yellow") ? true : false;

        //secondaryColor is assigned a secondary color based on the conditional expressions above
        if (purple)
            secondaryColor = "purple.";
        else if (orange)
            secondaryColor = "orange.";
        else
            secondaryColor = "green.";

        //outputs the secondary color
        cout << "Your secondary color is " << secondaryColor;
    }

    return 0;
}