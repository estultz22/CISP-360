#include <iostream>
#include <iomanip>
using namespace std;

//Shipping charges by Elijah Stultz
//CISP 360, September 11, 2019

int main()
{   //dollar format
    cout << setprecision(1) << fixed << showpoint;

    //initialization
    const double TWO_LBS = 2.0, 
                 SIX_LBS = 6.0,  
                 TEN_LBS = 10.0;
    double shippingWeight, shippingCharges;
    bool isPositive;
    
    //User input
    cout << "Enter shipping weight: ";
    cin >> shippingWeight;

    //returns true if shippingWeight is positive; false otherwise
    isPositive = (shippingWeight > 0) ? true : false;

    if (isPositive)
    {   //assigns charges based on how high shippingWeight is
        if (shippingWeight <= TWO_LBS)
            shippingCharges = 1.10;
        else if (((shippingWeight - TWO_LBS) > 0.01) && ((shippingWeight - SIX_LBS) < 0.01))
            shippingCharges = 2.20;
        else if (((shippingWeight - SIX_LBS) > 0.01) && ((shippingWeight - TEN_LBS) < 0.01))
            shippingCharges = 3.70;
        else
            shippingCharges = 4.20;
    }
    else
    {   //error message
        cout << "Shipping weight cannot be zero or negative.";
        return 1;
    }
    //outputs shipping rate
    cout << "Shipping charges are: "<< '$' << shippingCharges << endl;

    return 0;
}