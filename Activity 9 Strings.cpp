#include <iostream>
#include <cctype>
#include <sstream>

using namespace std;

int main()
{
    string userString, word;
    char currentChar;
    int wordsInString = 0,
        numericChars = 0,
        numSpaces = 0,
        numPunct = 0,
        numConsonants = 0;


    cout << "Please enter a string: ";
    getline(cin, userString);

    istringstream inSS(userString);

    while (!inSS.eof())
    {
        inSS >> word;
        wordsInString++;
        //debugging cout << word << wordsInString;
    }

    for (int i = 0; i < userString.length(); ++i)
    {
        if (isdigit(userString.at(i)))
            numericChars++;
        if (isspace(userString.at(i)))
            numSpaces++;
        if (ispunct(userString.at(i)))
            numPunct++;
        if (isalpha(userString.at(i)))
        {
            currentChar = tolower(userString.at(i));
            if ((currentChar != 'a') && (currentChar != 'e') && (currentChar != 'i') && (currentChar != 'o') && (currentChar != 'u'))
                numConsonants++;

        }
    }

    cout << "Summary: " << endl;
    cout << "The number of words = " << wordsInString << endl;
    cout << "The number of numeric characters = " << numericChars << endl;
    cout << "The number of spaces = " << numSpaces << endl;
    cout << "The number of punctuation = " << numPunct << endl;
    cout << "The number of consonants = " << numConsonants << endl;




    return 0;
}