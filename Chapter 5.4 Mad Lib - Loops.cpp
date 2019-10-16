#include <iostream>
#include <string>
using namespace std;

int main() {
   string userString;
   int userNum;
   
   cin >> userString;
   cin >> userNum;
   
   while ((userString != "quit") && (userNum != 0))
      {  
        
         cout << "Eating " << userNum << " " << userString << " a day keeps the doctor away." << endl;
         
         cin >> userString;
         cin >> userNum;
      }
   
   
   
   return 0;
}
