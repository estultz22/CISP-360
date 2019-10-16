#include <iostream>
using namespace std;

int main() {
   int counter = 0, maxNum = 0, userInput, sumNum;
   double average;
   
   cin >> userInput;
   while (userInput >= 0)
   {
      counter++;
      if (userInput > maxNum)
      {
        maxNum = userInput; 
      }
      
      sumNum += userInput;
      
      cin >> userInput;
   }   
   average = static_cast<double>(sumNum) / counter;
   cout << average << ' ' << maxNum << endl;
   
   
   return 0;
}
