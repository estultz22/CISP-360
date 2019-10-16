#include <iostream>
using namespace std;

const int ACRE = 43560;

int main()
{
    int num;
    double result;

    cout << "Enter square feet: " << endl;
    cin >> num;

    result = static_cast<double>(num) / ACRE;
    cout << result;

    return 0;
}

//edit: <double> didn't show up