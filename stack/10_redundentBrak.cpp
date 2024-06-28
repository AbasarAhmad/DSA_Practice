#include <iostream>
#include <stack>
using namespace std;
bool RedundentBraket(string s)
{
      stack<char> st;
      int n = s.length();

      for (int i = 0; i < n; i++)
      {
            char a = s[i];
            if (a == '(' || a == '+' || a == '-' || a == '*' || a == '/')
            {
                  st.push(s[i]);
            }
            else
            {
                  if (a == ')')
                  {
                        bool isRedundant = true;
                        while (st.top() != '(')
                        {
                              char top = st.top();
                              if (top == '+' || top == '-' || top == '*' || top == '/')
                              {
                                    isRedundant = false;
                              }
                              st.pop();
                        }
                        if (isRedundant == true)
                        {
                              return true;
                        }
                        st.pop();
                  }
            }
      }
      return false;
}
int main()
{
      string st;
      cout << "Enter the expression to check" << endl;
      cin >> st;
      int n = RedundentBraket(st);
      if (n)
      {
            cout << "redundency" << endl;
      }
      else
      {
            cout << "Not Redundency" << endl;
      }
      return 0;
}