#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;
using std::string;
using std::cin;

const int ROWS = 3;
const int COLS = 3;

void fillBoard(char [][COLS]);
void showBoard(char [][COLS]);
void getChoice(char [][COLS], bool);
bool gameOver(char [][COLS]);
bool isValid (int);

int main()
{
    char board[ROWS][COLS];
    bool playerToggle = false;

    fillBoard(board);
    showBoard(board);
   
   while (!gameOver(board))
    {
        getChoice(board, playerToggle);
        showBoard(board);
        playerToggle = !playerToggle;
    }

    return 0;
}

void fillBoard(char boardToFill[][COLS])
{
    for (int index = 0; index < ROWS; ++index)
    {
        for (int indexk = 0; indexk < COLS; indexk++)
        {
            boardToFill[index][indexk] = '*';
        }
        
    }
}

void showBoard(char boardToPrint[][COLS])
{
    std::cout << "  1 2 3" << endl;
    for (int index = 0; index < ROWS; index++)
    {
        cout << index + 1 << ' ';
        for (int indexk = 0; indexk < ROWS; indexk++)
        {
            cout << boardToPrint[index][indexk] << ' ';
        }
        cout << endl;
    }
    
}

void getChoice(char boardPosToChoose[][COLS], bool playerSwitch)
{
    int user1Row = 0, user1Col = 0, user2Row = 0, user2Col = 0;
    bool boardPosIsTaken = true;
    //player 1
    if (!playerSwitch)
    {
        while (boardPosIsTaken)
        {
            while (!isValid(user1Row) || boardPosIsTaken)
            {
                cout << "Player 1, Row: ";
                cin >> user1Row;
                boardPosIsTaken = false;
            }
            boardPosIsTaken = true;
            while (!isValid(user1Col) || boardPosIsTaken)
            {
                cout << "Player 1, Column: ";
                cin >> user1Col;
                boardPosIsTaken = false;
            }   
            boardPosIsTaken = (boardPosToChoose[user1Row - 1][user1Col - 1] != '*') ? true : false;
        }
        
        boardPosToChoose[user1Row - 1][user1Col - 1] = 'X';
    }
    //player 2
    else
    {
        while (boardPosIsTaken)
        {
            while (!isValid(user2Row) || boardPosIsTaken)
            {
                cout << "Player 2, Row: ";
                cin >> user2Row;
                boardPosIsTaken = false;
            }
            boardPosIsTaken = true;
            while (!isValid(user2Col) || boardPosIsTaken)
            {
                cout << "Player 2, Column: ";
                cin >> user2Col;
                boardPosIsTaken = false;
            }   
            boardPosIsTaken = (boardPosToChoose[user2Row - 1][user2Col - 1] != '*') ? true : false;
        }  
        
        boardPosToChoose[user2Row - 1][user2Col - 1] = 'O';
    }
    
}

bool isValid(int numToValidate)
{
    bool numIsValid = false;
    const int MIN = 1, MAX = 3;

    if (numToValidate >= MIN && numToValidate <= MAX)
    {
        numIsValid = true;
    }
    return numIsValid;
}

bool gameOver(char boardWinner[][COLS])
{
    bool isGameOver = false;

    const int NUM_WIN = 3;

    string winner;
    int XOCount = 0; //counts all spaces
    int Xcounter = 0, //counts horizontal Xs
        XVertCounter = 0, //counts vertical Xs
        XDiagCounter = 0, //counts principle diagonal Xs
        XRevDiagCounter = 0, //reverse diagonal Xs
        Ocounter = 0,
        OVertCounter = 0, 
        ODiagCounter = 0,
        ORevDiagCounter = 0;


    for (int index = 0, jindex = 0, kindex = COLS - 1; index < ROWS; index++, jindex++, kindex--)
    {
        Xcounter = 0;
        Ocounter = 0;
        //principle diagonals are of index [n][n]
        if (boardWinner[index][jindex] == 'X')
                XDiagCounter++;

        if (boardWinner[index][jindex] == 'O')
                ODiagCounter++;

        //reverse diagonals are of index [n+1][n-1]
        if (boardWinner[index][kindex] == 'X')
                XRevDiagCounter++;

        if (boardWinner[index][kindex] == 'O')
                ORevDiagCounter++;

        for (int kindex = 0; kindex < COLS; kindex++)
        {
            //checks every column for x 
            if (boardWinner[index][kindex] == 'X')
                Xcounter++;
            //checks every column for O
            if (boardWinner[index][kindex] == 'O')
                Ocounter++;

            //checks who won
            if (Xcounter == NUM_WIN || XDiagCounter == NUM_WIN || XRevDiagCounter == NUM_WIN)
            {
                winner = 'X';
                isGameOver = true;
            }
            else if (Ocounter == NUM_WIN || ODiagCounter == NUM_WIN || ORevDiagCounter == NUM_WIN)
            {
                winner = 'O';
                isGameOver = true;
            }

            //if all spaces are filled with X or O and neither X or O won, then its a tie
            if (boardWinner[index][kindex] != '*')
                XOCount++;
            
        }      
    }

    //verticals
    for (int index = 0; index < COLS; index++)
        {
            XVertCounter = 0;
            OVertCounter = 0;
            for (int kindex = 0; kindex < ROWS; kindex++)
            {
                if (boardWinner[kindex][index] == 'X')
                    XVertCounter++;

                if (boardWinner[kindex][index] == 'O')
                    OVertCounter++;

                if (XVertCounter == NUM_WIN)
                {
                    winner = boardWinner[kindex][index];
                    isGameOver = true;
                }
         
                if (OVertCounter == NUM_WIN)
                {
                    winner = boardWinner[kindex][index];
                    isGameOver = true;
                }
                    
                
            }
        }
    if (winner == "X")
        {
            cout << "Player 1 wins!";
        }
    else if (winner == "O")
    {
        cout << "Player 2 wins!";
    }
    //if neither player wins
    else if ((XOCount == 9) && (winner != "X") && (winner != "O"))
    {
        cout << "Tie!";
        isGameOver = true;
    }
    return isGameOver;
}
