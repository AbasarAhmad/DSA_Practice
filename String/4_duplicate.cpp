#include <iostream>
using namespace std;
string RemoveDuplicate(string s)
{
      // THis is a recursively approach
      /* if (s.length() == 0)
      {
            return "";
      }
      char ch = s[0];
      string ans = RemoveDuplicate(s.substr(1));
      if (ch == ans[0])
      {
            return ans;
      }
      else
      {
            return ch + ans;
      } */

      // Normal Approach
      string str = "";
      cout << s.length();
      for (int i = 0; i < s.length(); i++)
      {
            if (s[i] != s[i + 1])
            {
                  str += s[i];
            }
      }
      return str;
}
int main()
{
      cout << RemoveDuplicate("aabccba");
      return 0;
}