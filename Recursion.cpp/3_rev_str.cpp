// // reverse the string through recursion
// #include <iostream>
// using namespace std;
// void rec(string s, int n)
// {
//       if (n == 0)
//       {
//             return;
//       }
//       cout << s[n - 1];
//       rec(s, n - 1);
// }
// int main()
// {
//       cout << "Enter the string" << endl;
//       string s;
//       cin >> s;
//       int n = s.length();
//       rec(s, n);
//       return 0;
// }

//                 OR

#include <iostream>
using namespace std;
void rec(string &s, int i, int j)

{
      cout << s << "  at step " << i << endl;
      // base  case
      if (i > j)
      {
            return;
      }
      swap(s[i], s[j]);
      i++;
      j--;
      rec(s, i, j);
}
int main()
{
      cout << "Enter the string" << endl;
      string s;
      cin >> s;
      int n = s.length() - 1;
      rec(s, 0, n);
      cout << s;
      return 0;
}