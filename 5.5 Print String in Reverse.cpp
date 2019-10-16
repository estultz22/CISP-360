#include <iostream>
#include <string>
using namespace std;

int main() {
   string inputString;
  do{
     
   getline(cin, inputString);
   
   if (inputString == "Quit" || inputString == "q" || inputString == "quit")
      break;
      
   for(auto it = inputString.rbegin(); it != inputString.rend(); ++it)
      std::cout << *it;
      
   cout << endl;
         
   }while(inputString != "Quit" || inputString != "q" || inputString != "quit");

   return 0;
}
