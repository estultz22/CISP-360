#include <iostream>
using namespace std;

/*conversation bot by Elijah Stultz
September 3rd, 2019 */

int main()
{
    string userName;
    string userFavoriteCity;
    int userAge;

    cout << "What is your name? ";
    getline(cin, userName);

    cout << "What is your age? ";
    cin >> userAge;
    cin.ignore();

    cout << "What is your favorite city? ";
    getline(cin, userFavoriteCity);

    cout << "Hello " << userName << "!  " << userAge << " is a great age.  " << "I like " << userFavoriteCity << " too!";


    return 0;
}
