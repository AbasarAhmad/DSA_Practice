#include <bits/stdc++.h>
using namespace std;

string reverseWords(string S)
{
      // this function has O(n) time complexity
      stack<string> st;
      int n = S.length();
      string words = "";
      for (int i = 0; i < n; i++)
      {

            if (S[i] != '.' && i < n)
            {
                  words += S[i];
            }
            else
            {
                  st.push(words);
                  words = "";
            }
      }
      st.push(words);
      S = "";
      while (!st.empty())
      {
            S += st.top();
            S += ".";
            st.pop();
      }
      S.erase(S.end() - 1); // use for erase last index of string
      return S;
}
int main()
{
      /* stack<char> st;
       char saar[50];
       gets(saar);
       int n = strlen(saar);
       for (int i = 0; i < n; i++)
       {
             st.push(saar[i]);
       }

       for (int i = 0; i < n; i++)
       {
             cout << st.top();
             st.pop();
       }
  */
      stack<string> st;

      string s = "Hey, how are you doing?";
      int n = s.length();
      for (int i = 0; i < n; i++)
      {
            string words = "";
            while (s[i] != ' ' && i < n)
            {
                  words += s[i];
                  i++;
            }
            st.push(words);
      }
      while (!st.empty())
      {
            cout << st.top() << " ";
            st.pop();
      }
      return 0;
}