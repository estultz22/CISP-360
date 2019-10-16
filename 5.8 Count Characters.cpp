#include <iostream>
#include <string>
using namespace std;

int main() {

   int counter = 0, i;
   char findToken;
   string userString;
   
   cin >> findToken;
   getline(cin, userString);
   
   while (i < userString.length())
   {
      if (userString.at(i) == findToken)
         counter++;
      i++;
   }   
   
   cout << counter << endl;
   

   return 0;
}