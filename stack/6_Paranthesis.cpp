#include <bits/stdc++.h>
using namespace std;
bool BalanceParanthesis(string s)
{
      stack<char> st;
      int n = s.size();
      for (int i = 0; i < n; i++)
      {
            char curr = s[i];
            if (curr == '{' or curr == '(' || curr == '[')
            {
                  st.push(curr);
            }

            else
            {
                  char top = st.top();
                  if (!st.empty())
                  {
                        if ((curr == ')' && top == '(') || (curr == '}' && top == '{') || (curr == ']' && top == '['))
                        {
                              st.pop();
                              return true;
                        }
                        else
                        {
                              return false;
                        }
                  }
                  else
                  {
                        return false;
                  }
            }
      }
      if (!st.empty())
      {
            return false;
      }
      else
      {
            return true;
      }
}
int main()
{
      // string s = "[{)}]";
      string s;
      cout << "Enter the expression to check" << endl;
      cin >> s;
      if (BalanceParanthesis(s))
      {
            cout << "Paranthesis  is Balance" << endl;
      }
      else
      {
            cout << "Paranthesis ars not balance" << endl;
      }

      return 0;
}
/*
#include <bits/stdc++.h>
#include <stack>
using namespace std;
bool isBalance(char *ch)
{
      stack<char> st;

      int n = strlen(ch);
      for (int i = 0; i < n; i++)
      {
            if (ch[i] == '(' || ch[i] == '{' || ch[i] == ']')
            {
                  st.push(ch[i]);
            }
            else if (ch[i] == ')')
            {

                  if (!st.empty() && st.top() == '(')
                  {
                        st.pop();
                  }
                  else
                  {
                        break;
                  }
            }
            else if (ch[i] == '{')
            {

                  if (!st.empty() && st.top() == '}')
                  {
                        st.pop();
                  }
                  else
                  {
                        break;
                  }
            }
            else if (ch[i] == ']')
            {

                  if (!st.empty() && st.top() == '[')
                  {
                        st.pop();
                  }
                  else
                  {

                        break;
                  }
            }
      }
      if (!st.empty())
      {
            return false;
      }
      else
      {
            return true;
      }
}
int main()
{
      char ch[100];
      cout << "Enter the expression" << endl;
      cin >> ch;
      if (isBalance(ch))
      {

            cout << "Balanced!" << endl;
      }
      else
      {
            cout << "Not Balanced!" << endl;
            return 0;
      }
} */
