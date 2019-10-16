#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

void generateLottery(int[], const int);
void getUserLotto(int[], const int);
void printLottos(int[], int[], int);
void getLottoMatches(int[], int[], int&, const int);
bool numIsValid(int);


int main()
{
    const int LOTTERY_SIZE = 5;
    int lottery[LOTTERY_SIZE],
        userLottoNums[LOTTERY_SIZE],
        numMatches = 0;

    srand(time(NULL));


    generateLottery(lottery, LOTTERY_SIZE);
    getUserLotto(userLottoNums, LOTTERY_SIZE);
    printLottos(lottery, userLottoNums, LOTTERY_SIZE);
    getLottoMatches(lottery, userLottoNums, numMatches, LOTTERY_SIZE);

    cout << "And the total matches is: " << numMatches << "!!";
    if (numMatches == 5)
        cout << "Congrats, you won the GRAND PRIZE!!!";

    return 0;
}

void generateLottery(int lotteryArr[], const int lotterySize)
{
    for (int index = 0; index < lotterySize; ++index)
    {
        lotteryArr[index] = rand() % 10;
    }
}

void getUserLotto(int userNums[], const int lotterySize)
{
    for (int index = 0; index < lotterySize; ++index)
    {
        cout << "Enter a lotto number (0 - 9) with a space in between: ";
        cin >> userNums[index];

        while (!numIsValid(userNums[index]))
        {
            cout << userNums[index] << " is invalid!!" << endl;
            cout << "Enter a lotto number (0 - 9) with a space in between: ";
            cin >> userNums[index];
        }

    }
}

void printLottos(int lotteryArr[], int userNums[], int lotterySize)
{
    cout << "lottery numbers: ";
    for (int index = 0; index < lotterySize; index++)
    {
        cout << lotteryArr[index] << ' ';
    }
    cout << endl;

    cout << "   user numbers: ";
    for (int index = 0; index < lotterySize; index++)
    {
        cout << userNums[index] << ' ';
    }
    cout << endl << endl;

}

void getLottoMatches(int lotteryArr[], int userNums[], int& numLottoMatches, const int lotterySize)
{
    for (int index = 0; index < lotterySize; ++index)
    {
        numLottoMatches = (lotteryArr[index] == userNums[index]) ? (numLottoMatches + 1) : numLottoMatches;
    }
}

bool numIsValid(int currNum)
{
    const int MAX = 9, MIN = 0;
    bool isValid = false;
    isValid = ((currNum <= MAX) && (currNum >= MIN)) ? true : false;

    return isValid;

}