#include <iostream>
#include <cctype>
using namespace std;


int main()
{
    double userInput, sum = 0;
    const string realNumberPrompt = "Enter a real number (0.0 - 100.0): ",
                 invalidInput = "Invalid input!! Number cannot contain non-numeric characters. Try again...",
                 lessThanMin = "Invalid input!! Number cannot be negative. Try again...",
                 greaterThanMax = "Invalid input!! Number cannot be greater than 100.0. Try again...",
                 continuePrompt = "Do you want to continue? Enter 'n' or 'N' to stop.: ";
    const char QUIT_CHAR1 = 'n', QUIT_CHAR2 = 'N';
    const double INPUT_MAX = 100.0, INPUT_MIN = 0;
    int counter = 0;
    bool isGreaterThanMax = false, isLessThanMin = false, isValid = false;
    char userContinue = 'a';

    while ((userContinue != QUIT_CHAR1) || (userContinue != QUIT_CHAR2))
    {
        cout << realNumberPrompt;
        cin >> userInput;

        while (cin.fail() || (userInput > INPUT_MAX) || (userInput < INPUT_MIN))
        {
            isGreaterThanMax = (userInput > INPUT_MAX) ? true : false;
            isLessThanMin = (userInput < INPUT_MIN) ? true : false;

            if (isGreaterThanMax)
            {
                cout << greaterThanMax << endl;
            }
            else if (isLessThanMin)
                cout << lessThanMin << endl;
            else if (cin.fail())
            {
                cout << invalidInput << endl;
            }
        
            cout << realNumberPrompt;
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> userInput;
        }
        counter++;
        sum += userInput;
        cout << continuePrompt;
        cin >> userContinue;

        if (userContinue == 'n' || userContinue == 'N')
            break;
    }
        
    cout << "Total: " << sum << endl;
    cout << "Average: " << sum / counter << endl;
    
    return 0;
}
