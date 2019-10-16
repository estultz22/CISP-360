#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/*Activity 6: A Dice Game by Elijah Stultz
September 17, 2019
CISP 360*/

int main()
{   //declaring and initializing variables
    const int DICE_SIDES = 8;
    int rollOne, rollTwo, rollSum,
        player1Points = 0, player2Points = 0;
    bool player1Win, sumEven;
    //declaring srand with a seed based on time()
    srand(time(NULL));

    cout << "Rolling dice now!" << endl;
    //executes two 8-sided dice rolls 11 times
    for (int i = 0; i < 11; i++)
    {
        rollOne = (rand() % DICE_SIDES + 1);
        rollTwo = (rand() % DICE_SIDES + 1);
        rollSum = rollOne + rollTwo;
        //conditional expression returns true if each roll is even
        sumEven = ((rollSum % 2) == 0) ? true : false;

        if (sumEven)
            player1Points++;
        else
            player2Points++;
    }
    //player 1 wins if they have more points than player 2
    player1Win = (player1Points > player2Points) ? true : false;
    //outputs the winner
    if (player1Win)
        cout << "And the winner is Player 1!";
    else
        cout << "And the winner is Player 2!";

    return 0;
}