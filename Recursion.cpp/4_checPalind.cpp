#include <iostream>
using namespace std;
bool checkPalindrome(string s, int i, int j)
{
      if (i > j)
      {
            return 0;
      }
      if (s[i] == s[j])
      {
            return true;
      }
      else
      {
            return false;
      }
      // i++;
      // j--;
      checkPalindrome(s, i + 1, j - 1);
}
int main()
{
      cout << "Enter the string" << endl;
      string s;
      cin >> s;
      int n = s.length() - 1;
      cout << n << endl;
      int ans = checkPalindrome(s, 0, n);
      if (ans)
      {
            cout << s << "  is palindrome" << endl;
      }
      else
      {
            cout << "Not palindrome";
      }
      return 0;
}