#include 
using std::cout;
using std::cin;
using std:: endl;

void checkerBoard(int);
void getWidth(int&);
bool isValid(int);

const int MAX_WIDTH = 40, MAX_HEIGHT = MAX_WIDTH / 2;

int main()
{
    int userWidth;

    do
    {
        cout << "Enter your checkerboard width: ";
        getWidth(userWidth);
    }while (!isValid(userWidth));

    checkerBoard(userWidth);
    return 0;
}

void checkerBoard(int boardWidth)
{
    char asterisk = '*', period = '.';
    bool flipFlag = false;

    for (int i = 0; i < MAX_HEIGHT; i++)
    {
        flipFlag = (i % 2 == 1) ? false : true;
        for (int j = 0; j < MAX_WIDTH / 4; j++)
        {
            if (flipFlag)
            {
                cout << period << asterisk;
            }

            else
                cout << asterisk << period;
        }
        cout << endl;
    }

    cout << endl;
    cout << boardWidth;

}

void getWidth(int& inputWidth)
{
    cin >> inputWidth;
}

bool isValid(int inputWidth)
{
    bool widthIsValid = false;

    if ((inputWidth <= MAX_WIDTH) && inputWidth > 0)
    {
        widthIsValid = true;
    }
    else
    {
        cout << "Width is not valid." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    return widthIsValid;