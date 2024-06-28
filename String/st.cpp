#include <bits/stdc++.h>
using namespace std;

int main()
{
      string s = "abcdef";
      /*    int i = 0;
         while (i < s.length())
         {
               char c = s[i];
               s[i] = s[i + 1];
               s[i + 1] = c;
               i += 4;
         } */
      reverse(s.begin(), s.end());
      cout << s;

      return 0;
}