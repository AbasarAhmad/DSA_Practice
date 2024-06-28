// Sort an Array using Recursion
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
void InsertInSorted(stack<int> &st, int num)
{
      // if (st.empty() || (!st.empty() && st.top() < num)) // Reverse Order (decreasing order)
      if (st.empty() || (!st.empty() && st.top() > num)) // Increasing order
      {
            st.push(num);
            return;
      }
      int temp = st.top();
      st.pop();
      InsertInSorted(st, num);
      st.push(temp);
}
void ReverseStack(stack<int> &st)
{
      if (st.empty())
      {
            return;
      }
      int store = st.top();
      st.pop();
      ReverseStack(st);
      InsertInSorted(st, store);
}
int main()
{
      stack<int> st;
      st.push(4);
      st.push(8);
      st.push(2);
      st.push(40);
      st.push(-11);
      st.push(9);
      st.push(26);
      st.push(1);
      print(st);

      ReverseStack(st);
      cout << "\n After insert value linkedlist show" << endl;
      print(st);
      return 0;
}