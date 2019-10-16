#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int heightInches;
    float weightPounds, BMI;
    string bmiResult;
    //user input
    cout << "Please enter your height in inches: ";
    cin >> heightInches;

    cout << "Now enter your weight in pounds: ";
    cin >> weightPounds;
    //calculating BMI
    BMI = (fabs(weightPounds) * 703) / pow(fabs(heightInches), 2);

    //compares BMI to given criteria
    if (BMI > 29)
        bmiResult = "obese";
    else if (BMI >= 25 && BMI < 29)
        bmiResult = "overweight";
    else if (BMI >= 18.5 && BMI < 25)
        bmiResult = "optimal";
    else
        bmiResult = "underweight";

    //outputs results
    cout << "According to your BMI, you are " << bmiResult << endl;
    return 0;
}