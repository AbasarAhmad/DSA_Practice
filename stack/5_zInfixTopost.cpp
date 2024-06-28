#include <iostream>
#include <stack>
using namespace std;
int prec(char c)
{
      if (c == '^')
      {
            return 3;
      }
      else if (c == '/' || c == '*')
      {
            return 2;
      }
      else if (c == '+' || c == '-')
      {
            return 1;
      }
      else
      {
            return -1;
      }
}
string InfixToPostFix(string s, int n)
{
      stack<char> st;
      string temp;
      for (int i = 0; i < n; i++)
      {
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
            {
                  temp += s[i];
            }
            else if (s[i] == '(')
            {
                  st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                  while (!st.empty() && st.top() != '(')
                  {
                        temp += st.top();
                        st.pop();
                  }
                  if (!st.empty())
                  {
                        st.pop();
                  }
            }
            else
            {
                  while (!st.empty() && prec(st.top()) > prec(s[i]))
                  {
                        temp += st.top();
                        st.pop();
                  }
                  st.push(s[i]);
            }
      }
      while (!st.empty())
      {
            temp += st.top();
            st.pop();
      }
      return temp;
}
int main()
{
      string s = "(a-b/c)*(a/k-l)";
      // cout << "Enter a string to convert infix to prefix" << endl;
      cout << InfixToPostFix(s, s.length() - 1);
      return 0;
}