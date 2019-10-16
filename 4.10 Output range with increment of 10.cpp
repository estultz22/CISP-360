#include <iostream>
using namespace std;

int main()
{
   int userInt1, userInt2;
   bool invalidInput;
   
   //cout << "Enter the first integer: ";
   cin >> userInt1;
   //cout << "Enter the second integer: ";
   cin >> userInt2;
   
   invalidInput = (userInt2 < userInt1) ? true : false;
   
   if (invalidInput)
   {
      cout << "Second integer can't be less than the first." << endl;
      return 1;
   }
   else
   {
      while (userInt1 <= userInt2) 
      {
         cout << userInt1 << ' ';
         userInt1 += 10;
      }
   }
   cout << endl;
   

   return 0;
}
