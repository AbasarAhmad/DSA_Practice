#include <bits/stdc++.h>
using namespace std;
string reverseWord(string &str)
{
      // Base case: if the string is empty or has only one character, return the string
      if (str.length() <= 1)
      {
            return str;
      }

      // Recursive call to reverse the rest of the string (excluding the first character)
      string ros = str.substr(1);
      reverseWord(ros);
      // Build the reversed string by appending the first character to the reversed substring
      string reversed = ros + str[0];

      return reversed;
}
int main()
{
      string s = "Hero";
      cout << reverseWord(s);
      return 0;
}