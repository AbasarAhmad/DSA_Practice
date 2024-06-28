/* #include <iostream>
#include <stack>
using namespace std;
void print(stack<int> st)
{
      while (!st.empty())
      {
            cout << st.top() << " ";
            st.pop();
      }
}
void RemeveElement(stack<int> &st)
{
      stack<int> temp;
      int middle = st.size();
      middle = middle / 2;
      for (int i = 0; i < middle; i++)
      {
            temp.push(st.top());
            st.pop();
      }
      st.pop();
      for (int i = 0; i < middle; i++)
      {
            st.push(temp.top());
            temp.pop();
      }
}
int main()
{
      stack<int> st;
      st.push(12);
      st.push(18);
      st.push(24);
      st.push(30);
      st.push(9);
      print(st);
      // now we want remove middle element of  stack
      RemeveElement(st);
      cout << "\nAfter Remove middle element" << endl;
      print(st);
      return 0;
} */

// Now Remove middle element of stack through stack
#include <iostream>
#include <stack>
using namespace std;
void print(stack<int> st)
{
      while (!st.empty())
      {
            cout << st.top() << " ";
            st.pop();
      }
}
void solve(stack<int> &st, int cont, int size)
{
      if (cont == size / 2)
      {
            st.pop();
            return;
      }
      int store = st.top();
      st.pop();
      solve(st, cont + 1, size);
      st.push(store);
}
void RemeveElement(stack<int> &st)
{
      int n = st.size();
      int cont = 0;
      solve(st, cont, n);
}
int main()
{
      stack<int> st;
      st.push(12);
      st.push(18);
      st.push(24);
      st.push(30);
      st.push(9);
      print(st);
      // now we want remove middle element of  stack
      RemeveElement(st);
      cout << "\nAfter Remove middle element" << endl;
      print(st);
      return 0;
}