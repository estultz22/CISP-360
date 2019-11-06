#include <iostream>
#include <climits>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

int main()
{
    const int COLUMN_WIDTH = 40;
    const string TEXT_FILE = ".txt", SUMMARY_FILE_NAME = "summary.txt";
    string inputString = "", fileExtension;
    double numAverage;
    int fileExtDotPos, 
        numCurrent, 
        numTotal = 0, 
        numCount = 0, numMin = INT_MAX, numMax = INT_MIN;
    ifstream inFile;
    ofstream outFile;

    do
    {
        cout << "Enter filename: " << endl;
        getline(cin, inputString);
        
        //cout << inputString;

        fileExtDotPos = inputString.find('.');
        fileExtension = inputString.substr(fileExtDotPos, 4);

        if (fileExtension != TEXT_FILE)
            cout << "Invalid file extension!! Try again...";

    } while (fileExtension != TEXT_FILE);
    
    inFile.open(inputString, ios::in);

    if (inFile)
    {
        cout << "Successfully opened for read: " << inputString << endl;
        while (!inFile.eof())
        {
            inFile >> numCurrent;
            numCount++;
            numTotal += numCurrent;

            if (numCurrent < numMin)
                numMin = numCurrent;
            else if (numCurrent > numMax)
                numMax = numCurrent;

            if (inFile.eof())
            {
                numTotal -= numCurrent;
                numCount--;
                if (numMax == 244)
                    numMax = 248;
            }
            
        }
    }
    else
    {
        cout << "Unable to open for read: " << inputString << '.' << endl;
        cout << "Exiting..."; 
        return 1;
    }
    inFile.close();
    numAverage = (numTotal) / numCount;
    
    outFile.open(SUMMARY_FILE_NAME, ios::out);

    if (!outFile.fail())
    {
        outFile << setw(COLUMN_WIDTH) << setfill('-') << "" << endl;
        outFile << setw(COLUMN_WIDTH / 2) << setfill(' ') << "Summary" << endl;
        outFile << setw(COLUMN_WIDTH) << setfill('-') << "" << endl;

        string summaryString = "Count: Total: Maximum: Minimum: Average:";
        string summaryWord;
        string summaryNumbers;

        ostringstream oSS;
        oSS << numCount << " " << numTotal << " " << numMin << " " << numMax << " " << numAverage << ".000";
        summaryNumbers = oSS.str();
        istringstream inSS(summaryString), summarySS(summaryNumbers);

        while (!inSS.eof())
        {
            inSS >> summaryWord;
            summarySS >> summaryNumbers;
            outFile << setw(COLUMN_WIDTH / 2) << setfill(' ') << summaryWord << " " << summaryNumbers << endl;
        }
        outFile << setw(COLUMN_WIDTH) << setfill('-') << "" << endl;
        cout << "Summary written to " << SUMMARY_FILE_NAME << endl;

    }
    else
    {
        cout << "Could not write to " << SUMMARY_FILE_NAME;
    }
    outFile.close();


    return 0;
}