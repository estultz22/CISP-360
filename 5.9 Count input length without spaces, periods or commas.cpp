#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
   string userString;
   int counter = 0, i = 0;
   
   getline(cin, userString);
   
   while (i < userString.length())
   {
      if ((userString[i] != ' ') && (userString[i] != '.') && (userString[i] != ','))
         counter++;  
      i++;
   }
   cout << counter << endl;
   return 0;
}