#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

//Amortization by Elijah Stultz
//09/03

const int DECIMAL_CONVERSION = 100;

int main()
{   cout << setprecision(2) << fixed << showpoint;
    //initializing variables
    double monthlyPaymentA,
           initialLoanP,
           monthlyInteresti,
           amountPaidBack,
           interestPaid;

    int numPaymentsn;

    //get user input
    cout << "Enter the loan amount: ";
    cin >> initialLoanP;

    cout << "Enter the monthly interest rate as a decimal: ";
    cin >> monthlyInteresti;

    cout << "Enter the number of months: ";
    cin >> numPaymentsn;
    cout << endl;

    //amortization formula calculation
    monthlyPaymentA = (initialLoanP * monthlyInteresti) / (1 - pow(1 + monthlyInteresti, -1 * numPaymentsn));
    //amountPaidBack = initialLoanP * pow((1 + monthlyInteresti), numPaymentsn);
    amountPaidBack = monthlyPaymentA * numPaymentsn;
    interestPaid = amountPaidBack - initialLoanP;

    //outputting
    cout << "Loan Amount: $ " << initialLoanP << endl << "Monthly Interest Rate: " << monthlyInteresti * DECIMAL_CONVERSION << '%'
         << endl << "Number of Payments: " << numPaymentsn << endl << "Monthly Payment: $ " << monthlyPaymentA
         << endl <<"Amount Paid Back: $ " << amountPaidBack << endl << "Interest Paid: $ " <<interestPaid;

    return 0;
}


