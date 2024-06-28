/* #include <iostream>
using namespace std;

int main()
{
      string s;
      cin >> s;
      string a = s;
      cout << a.size();
      int j = 0;
      while (j != 3)
      {
            for (int i = 0; i < 10; i++)
            {
                  if (i == 6)
                  {
                        cout << "breked" << endl;
                        break;
                  }
                  // cout << i << " ";
            }
            cout << endl;
            j++;
      }
      return 0;
} */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
      bool rotateString(string s, string goal)
      {
            int sz = s.size();
            int mid_s = sz / 2;
            int sz2 = goal.size();
            int mid_g = sz2 / 2;
            int j = 0;
            for (int i = 0; i < sz; i++)
            {
                  if (i < mid_s)
                  {
                        if (s[i] == goal[mid_g + 1])
                        {
                              mid_g++;
                              return true;
                        }
                        else
                        {
                              return false;
                        }
                  }

                  if (i >= mid_s)
                  {
                        if (s[i] == goal[j])
                        {
                              j++;
                              return true;
                        }
                        else
                        {
                              return false;
                        }
                  }
            }
      }
};
int main()
{
      string s = "abcde";
      string b = "cdeab";
      int a = s.size();
      a = a / 2;
      // cout << s.size() << endl;
      // cout << s[2];
      Solution st;
      // cout << st.rotateString(s, b);
      cout << s[0];
      return 0;
}