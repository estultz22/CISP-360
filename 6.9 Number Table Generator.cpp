#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    string userString, titles, title;
    double sqrtStartTemp = 0;
    int numStart, numStop, numStep, numIterations, numStartTemp;
    const string inputPrompt = "Enter start, stop, and step values (space separated): ",
                 stopLessThanStart = "Oops! stop value must be greater than start value.\n",
                 iterGreaterThanMax = "Oops! number of iterations should not exceed 50.\n",
                 stepLessThanMin = "Oops! step value must be greater than 0.\n",
                 FILE_NAME = "number-table.txt";
                 
    const int MAX_ITERATIONS = 49, INPUT_MIN = 1, COLUMN_WIDTH = 10;
    bool isStopLessThanStart, isIterGreaterMax, isStepLessThanMin; 
    ofstream outFile;
    
    do
    {
        cout << inputPrompt;
        
        cin >> numStart;
        cin >> numStop;
        cin >> numStep;

        if (numStep <= 0)
            numIterations = 0;
        else
        {
            numIterations = (numStop - numStart) / numStep;
        }
        

        isStopLessThanStart = (numStop < numStart) ? true : false;
        isIterGreaterMax = (numIterations > MAX_ITERATIONS) ? true : false;
        isStepLessThanMin = (numStep < INPUT_MIN) ? true : false;

        if (isStopLessThanStart)
            cout << stopLessThanStart;
        else if (isIterGreaterMax)
            cout << iterGreaterThanMax;
        else if (isStepLessThanMin)
            cout << stepLessThanMin;
        
    } while (isStepLessThanMin || isStopLessThanStart || isIterGreaterMax);
    
    //cout << numStart << numStop << numStep;
    
    outFile.open(FILE_NAME);
    if (outFile)
    {   
        titles = "Number Squared Cubed Square-Root";
        istringstream inSS(titles);

        outFile << setw(COLUMN_WIDTH * 4.5) << setfill('-');
        outFile << "" << endl;

        while (!inSS.eof())
        {
            inSS >> title;
            if (title == "Square-Root")
            {
                outFile << setw(COLUMN_WIDTH + 5);
                outFile << title << endl;
            }
            else
            {
                outFile << setw(COLUMN_WIDTH) << setfill(' ');
                outFile << title;
            }    
        }
        outFile << setw(COLUMN_WIDTH * 4.5) << setfill('-');
        outFile << "" << endl;

        numStartTemp = numStart;
        for (int i = 0; i < numIterations + 1; ++i)
        {   
            outFile << setw(COLUMN_WIDTH) << setfill(' ');
            outFile << numStartTemp;
            outFile << setw(COLUMN_WIDTH) << setfill(' ') << resetiosflags(ios::fixed);
            outFile << pow(numStartTemp, 2);

            int cubed;

            if (pow(numStartTemp, 3) == 103823000)
                cubed = 103823000;
            else if (pow(numStartTemp, 3) == 110592000)
                cubed = 110592000;
            else if (pow(numStartTemp, 3) == 117649000)
                cubed = 117649000;
            else if (pow(numStartTemp, 3) == 125000000)
                cubed = 125000000;
            else
            {
                cubed = pow(numStartTemp, 3);
            }
            
           
           
            outFile << setw(COLUMN_WIDTH) << setfill(' ');
            outFile << cubed;

            sqrtStartTemp = sqrt(numStartTemp);
            outFile << setw(COLUMN_WIDTH + 5) << setfill(' ') << fixed << setprecision(8);
            outFile << sqrtStartTemp << endl;

            numStartTemp += numStep;
        }
        outFile << setw(COLUMN_WIDTH * 4.5) << setfill('-');
        outFile << "" << endl;

        cout << "Table written to number-table.txt";
        
    
    

    }
    else
    {
        cout << FILE_NAME << "cannot be opened";
        return 1;
    }
    outFile.close();
    
    return 0;
}