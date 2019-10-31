#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct playerInfo
{
    int jerseyNum,
        ratingNum;
};

void displayMenu();
char getMenuInput();
void addPlayer(vector<playerInfo> &);
void deletePlayer(vector<playerInfo> &);
int findPlayer(const vector<playerInfo> &, int );
void displayRoster(const vector<playerInfo> );
void displayRosterAbvRtng(const vector<playerInfo> );
void updatePlayerRating(vector<playerInfo> &);
void sortVector(vector<playerInfo> &, bool);
int getInt();


int main()
{
    char inputChar,
         quitChar = 'q';
    bool isSortByJersey = false;

    vector<playerInfo> players(0);

    do
    {
        displayMenu();
        inputChar = getMenuInput();

        switch (inputChar)
        {
        case 'a':
            addPlayer(players);
            break;
        case 'o':
            displayRoster(players);
            break;
        case 'd':
            deletePlayer(players);
            break;
        case 'u':
            updatePlayerRating(players);
            break;
        case 'r':
            displayRosterAbvRtng(players);
        case 'j':
            isSortByJersey = true;
            sortVector(players, isSortByJersey);
            break;
        case 's':
            sortVector(players, isSortByJersey);
            break;
        default:
            break;
        }
            
    } while (inputChar != quitChar);

    //cout << inputChar;

    return 0;
}

//shows all the options
void displayMenu()
{
    cout << "\nMENU\n" << "a - Add player\n" << "d - Remove player\n" <<
            "u - Update player rating\n" <<
            "r - Output players above a rating\n" << 
            "o - Output roster\n" <<
            "s - Sort roster by player rating\n" <<
            "j - Sort roster by jersey number\n" <<
            "q - Quit\n";
}

//gets a single char
char getMenuInput()
{
    char input;

    cout << "\nChoose an option: ";
    cin >> input;

    return input;
}

//appends a new player to the main vector
void addPlayer(vector<playerInfo> &playerList)
{
    playerInfo tempPlayer;

    cout << "Enter player's jersey number:\n";
    tempPlayer.jerseyNum = getInt();
    cout << "Enter player's rating:\n";
    tempPlayer.ratingNum = getInt();

    playerList.push_back(tempPlayer);
}

//simply gets an int from user
int getInt()
{
    int intInput;
    cin >> intInput;
    return intInput;
}

//outputs roster of soccer team
void displayRoster(const vector<playerInfo> playerList)
{
    int currJerseyNum, currRating;

    cout << "\nROSTER\n";
    for (int index = 0; index < playerList.size(); index++)
    {
        currJerseyNum = playerList.at(index).jerseyNum;
        currRating = playerList.at(index).ratingNum;

        cout << "Player " << index + 1 << " -- " << "Jersey number: " << currJerseyNum << ", ";
        cout << "Rating: " << currRating << endl;
    }
    cout << endl;
}

//gets jersey number and deletes that player
void deletePlayer(vector<playerInfo> &playerList)
{
    int jerseyNum;

    cout << "Enter a jersey number:\n";
    jerseyNum = getInt();

    int playerIndex = findPlayer(playerList, jerseyNum);

    playerList.erase(playerList.begin() + playerIndex);
}

//finds player's index within vector
int findPlayer(const vector<playerInfo> &playerList, int jersey)
{
    bool foundPlayer = false;
    int index = 0,
        vsize = playerList.size(),
        currNum;

    while(!foundPlayer && index < vsize)
    {
        currNum = playerList.at(index).jerseyNum;

        if (currNum == jersey)
        {
            foundPlayer = true;
        }
        index++;
    }

    if (!foundPlayer)
        index = 0;

    return index - 1;
}

void updatePlayerRating(vector<playerInfo> &playerList)
{
    int jersey,
        playerIndex,
        newRating;

    cout << "Enter a jersey number:\n";
    jersey = getInt();

    cout << "Enter a new rating for player:\n";
    newRating = getInt();

    playerIndex = findPlayer(playerList, jersey);

    playerList.at(playerIndex).ratingNum = newRating;
}

void displayRosterAbvRtng(const vector<playerInfo> playerList)
{
    int rating,
        currRating,
        currJersey;

    cout << "Enter a rating:\n";
    rating = getInt();

    cout << "\nABOVE " << rating << "\n";

    for (size_t i = 0; i < playerList.size(); i++)
    {
        currRating = playerList.at(i).ratingNum;
        currJersey = playerList.at(i).jerseyNum;

        if (currRating > rating)
        {
            cout << "Player " << i + 1 << " -- " << "Jersey number: " << currJersey << ", ";
            cout << "Rating: " << currRating << endl;
        }           
    }
}

void sortVector(vector<playerInfo> &playerList, bool sortByJersey)
{
    int index,
        scan,
        unsorted,
        unsorted1;

    if (sortByJersey)
    {
        for (index = 1; index < playerList.size(); index++)
        {
            unsorted = playerList.at(index).jerseyNum;
            unsorted1 = playerList.at(index).ratingNum;
            scan = index;
            while(scan > 0 && playerList.at(scan - 1).jerseyNum > unsorted)
            {
                playerList.at(scan).jerseyNum = playerList.at(scan - 1).jerseyNum;
                playerList.at(scan).ratingNum = playerList.at(scan - 1).ratingNum;
                scan--;
            }
            playerList.at(scan).jerseyNum = unsorted;
            playerList.at(scan).ratingNum = unsorted1;
        }
        
    }
    else
    {
        for (index = 1; index < playerList.size(); index++)
        {
            unsorted1 = playerList.at(index).jerseyNum;
            unsorted = playerList.at(index).ratingNum;
            scan = index;
            while(scan > 0 && playerList.at(scan - 1).ratingNum > unsorted)
            {
                playerList.at(scan).jerseyNum = playerList.at(scan - 1).jerseyNum;
                playerList.at(scan).ratingNum = playerList.at(scan - 1).ratingNum;
                scan--;
            }
            playerList.at(scan).jerseyNum = unsorted1;
            playerList.at(scan).ratingNum = unsorted;
        }
    }
    
}