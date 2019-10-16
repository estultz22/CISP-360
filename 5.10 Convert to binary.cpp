#include <iostream>
using namespace std;

int main() {

   int userPosInt, binaryDigit;
   
   cin >> userPosInt;
   
   do{
      binaryDigit = userPosInt % 2;
      cout << binaryDigit;
      userPosInt /= 2;
      
   }while(userPosInt > 0);
   cout << endl;

   return 0;
}
