#include <iostream>
#include <cctype>

using std::cout;
using std::cin;
using std::string;
using std::endl;

double calculateTotal(int, double, double, double); //- calculates the charges for an inpatient
double calculateTotal(double, double); //- calculates the charges for an outpatient
bool isValid(double); //- validates double values
bool isValid(int); //- validates int values
void getDays(int&);
double getInput();

int main()
{
    char inputchar;
    int numUserDays;
    double dRateUser, 
           hosChargeUser, 
           medChargeUser,
           chargeTotal;
    string admissionPrompt = "Were you admitted as an inpatient (press y or Y for yes)? ",
           dRatePrompt = "Enter the daily rate (> 0.0): ",
           hosChargePrompt = "Enter the hospital services (> 0.0): ",
           medChargePrompt = "Enter the medication charges (> 0.0): ",
           invalidDays = "Invalid input for number of days spent in hospital!!",
           invalidRate = "Invalid input for daily rate!!",
           invalidHosCharges = "Invalid input for hospital services!!",
           invalidMedCharges = "Invalid input for medication charges!!";

    cout << admissionPrompt;
    cin >> inputchar;
    //cout << endl;

    inputchar = tolower(inputchar);

    //inpatient
    if (inputchar == 'y')
    {
        getDays(numUserDays);
        while (!isValid(numUserDays))
        {
            cout << invalidDays << endl;
            getDays(numUserDays);
        }
        

        cout << dRatePrompt;
        dRateUser = getInput();
        while (!isValid(dRateUser))
        {
            cout << invalidRate << endl;
            cout << dRatePrompt;
            dRateUser = getInput();
        }
        
        cout << hosChargePrompt;
        hosChargeUser = getInput();
        while (!isValid(hosChargeUser))
        {
            cout << invalidHosCharges << endl;
            cout << hosChargePrompt;
            hosChargeUser = getInput();
        }
        
        cout << medChargePrompt;
        medChargeUser = getInput();
        while (!isValid(medChargeUser))
        {
            cout << invalidMedCharges << endl;
            cout << medChargePrompt;
            medChargeUser = getInput();
        }
        

        chargeTotal = calculateTotal(numUserDays, dRateUser, hosChargeUser, medChargeUser);
        cout << endl;
        cout << "Total charges incurred as an inpatient is: " << chargeTotal;

    }
    //outpatient
    else
    {
        cout << hosChargePrompt;
        hosChargeUser = getInput();
        while (!isValid(hosChargeUser))
        {
            cout << invalidHosCharges << endl;
            cout << hosChargePrompt;
            hosChargeUser = getInput();
        }
        
        cout << medChargePrompt;
        medChargeUser = getInput();
        while (!isValid(medChargeUser))
        {
            cout << invalidMedCharges << endl;
            cout << medChargePrompt;
            medChargeUser = getInput();
        }

        chargeTotal = calculateTotal(hosChargeUser, medChargeUser);
        cout << "Total charges incurred as an outpatient is: " << chargeTotal;

    }
    
    return 0;
}

double calculateTotal(int days, double dRate, double hosCharge, double medCharge)
{
    double totalCharges = (days * dRate) + hosCharge + medCharge;
    return totalCharges;
}

void getDays(int& daysInt)
{
    cout << "Enter the number of days spent in hospital (> 0): ";
    cin >> daysInt;
}

double getInput()
{
    double chargesToInput;
    cin >> chargesToInput;
    return chargesToInput;
}

bool isValid(int days)
{
    bool intIsValid = false;
    if (days > 0)
        intIsValid = true;
    return intIsValid;
}

bool isValid(double charges)
{
    bool doubleIsValid = false;
    if (charges >= 0.0)
        doubleIsValid = true;
    return doubleIsValid;
}

double calculateTotal(double hosCharge, double medCharge)
{
    double totalCharges = hosCharge + medCharge;
    return totalCharges;
}