#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
   string userString;
   
   getline(cin, userString);

   if (userString.find('!') != string::npos || userString.find(',') != string::npos || userString.find('.') != string::npos)
      cout << "no" << endl;
   else
      cout << "yes" << endl;

   return 0;
}
