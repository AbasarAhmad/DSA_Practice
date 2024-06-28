#include <iostream>
#include <stack>
#include <math.h>
using namespace std;
// code for Postfix evaluation , means  code for solve postfix expression
int PostfixEval(string s)
{
      stack<int> st;
      for (int i = 0; i < s.length(); i++)
      {
            if (s[i] >= '0' && s[i] <= '9')
            {
                  st.push(s[i] - '0');
            }
            else
            {
                  int opt2 = st.top();
                  st.pop();
                  int opt1 = st.top();
                  st.pop();
                  switch (s[i])
                  {
                  case '+':
                        st.push(opt1 + opt2);
                        break;

                  case '-':
                        st.push(opt1 - opt2);
                        break;

                  case '*':
                        st.push(opt1 * opt2);
                        break;

                  case '/':
                        st.push(opt1 / opt2);
                        break;

                  case '^':
                        st.push(pow(opt1, opt2));
                        break;

                  default:
                        cout << "something going wrong" << endl;
                        break;
                  }
            }
      }
      return st.top();
}

// code for prefix evaluation
/*
int prefixEval(string s)
{
      stack<int> st;
      for (int i = s.length() - 1; i >= 0; i--)
      {
            if (s[i] >= '0' && s[i] <= '9')
            {
                  st.push(s[i] - '0');
            }
            else
            {
                  int opt1 = st.top();
                  st.pop();
                  int opt2 = st.top();
                  st.pop();
                  switch (s[i])
                  {
                  case '+':
                        st.push(opt1 + opt2);
                        break;

                  case '-':
                        st.push(opt1 - opt2);
                        break;

                  case '*':
                        st.push(opt1 * opt2);
                        break;

                  case '/':
                        st.push(opt1 / opt2);
                        break;

                  case '^':
                        st.push(pow(opt1, opt2));
                        break;

                  default:
                        cout << "something going wrong" << endl;
                        break;
                  }
            }
      }
      return st.top();
} */
int main()
{
      cout << "Enter the string to evaluate" << endl;
      string s;
      // cin >> s;
      // cout << "Answer is " << prefixEval(s);
      cout << " Postfix evaluation is " << PostfixEval("46+2/5*7+");
      return 0;
}