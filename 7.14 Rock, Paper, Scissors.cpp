#include <iostream>
#include <cstdlib>
using namespace std;

void displayMenu(); //– display the menu
int getUserInput(); // – get user input as one of the menu choices and return it as an int
bool isValidUserInput(int choice); // -validates the user input: returns true when the int argument choice is in the range 1 - 4 (inclusive) and false otherwise
int generateComputerChoice();// – generate the computers choice and return it as an int
void displayChoice(int, int);// – display the choice the computer and the user made based on the menu
void selectWinner(int, int);// – select the winner or tie based on the computer’s choice and the user’s input

enum rockPaperScissors {ROCK = 1, PAPER = 2, SCISSORS = 3};

int main()
{
    int userChoice, 
        computerChoice;

    std::srand(2019);

    displayMenu();
    userChoice = getUserInput();
    
    while (userChoice != 4)
    {
        if (isValidUserInput(userChoice))
        {
        computerChoice = generateComputerChoice();
        displayChoice(userChoice, computerChoice);
        selectWinner(userChoice, computerChoice);
        }  
        userChoice = getUserInput();
    }
    
    if (userChoice == 4)
        cout << "Good Bye!";
    return 0;
}

void displayMenu()
{
    cout << "Play Rock, Paper, Scissors\n\n"; 
    cout << "1.    Rock\n\n";
    cout << "2.    Paper\n\n";
    cout << "3.    Scissors\n\n";
    cout << "4.    Quit\n" << endl;  
}

int getUserInput()
{
    int numChoice;
    cout << "Enter your choice (1 - 4): ";
    cin >> numChoice;
    cout << endl;
    return numChoice;
}

bool isValidUserInput(int numChoice)
{
    int inputMax = 4, inputMin = 1;
    bool isValid = false;

    if (numChoice >= inputMin && numChoice <= inputMax)
        isValid = true;

    return isValid;
}

int generateComputerChoice()
{
    int randIntChoice = (rand() % 3) + 1;
    return randIntChoice;
}

void displayChoice(int playerChoiceInt, int compChoiceInt)
{
    string rockString = "Rock", paperString = "Paper", scissorsString = "Scissors", 
           playerChoice, computerChoice;

    if (playerChoiceInt == ROCK)
        playerChoice = rockString;
    else if (compChoiceInt == ROCK)
        computerChoice = rockString;

    if (playerChoiceInt == PAPER)
        playerChoice = paperString;
    else if (compChoiceInt == PAPER)
        computerChoice = paperString;

    if (playerChoiceInt == SCISSORS)
        playerChoice = scissorsString;
    else if (compChoiceInt == SCISSORS)
        computerChoice = scissorsString;

    if (playerChoiceInt == compChoiceInt)
        computerChoice = playerChoice;

    cout << "You chose: " << playerChoice << "\n\n" << "Computer chose: " << computerChoice << "\n\n";
}

void selectWinner(int playerChoiceInt, int compChoiceInt)
{
    string winner, player = "You win!!!\n\n", computer = "Computer wins...\n\n", tie = "It's a tie!!\n\n";
    if (playerChoiceInt == ROCK && compChoiceInt == SCISSORS)
        winner = player;
    else if (playerChoiceInt == PAPER && compChoiceInt == ROCK)
        winner = player;
    else if (playerChoiceInt == SCISSORS && compChoiceInt == PAPER)
        winner = player;
    else if (playerChoiceInt == compChoiceInt)
        winner = tie;
    else
        winner = computer;

    if (winner == tie)
        cout << tie << endl;
    else
    {
        cout << winner << endl;
    }
}