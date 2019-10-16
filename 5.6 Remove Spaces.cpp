#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
   
   string userInput;
   int tokenPos;
   
   getline(cin, userInput);
   
   while (userInput.find(' ') != string::npos)
   {
      tokenPos = userInput.find(' '); 
      if (isspace(userInput[tokenPos]))
      {
         userInput = userInput.replace(tokenPos, 1, "");
      }
   }
   cout << userInput << endl;

   return 0;
}