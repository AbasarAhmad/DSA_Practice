/* // Implement Queue using Two Stack
#include <iostream>
#include <stack>
using namespace std;
class Que
{
      stack<int> st1;
      stack<int> st2;

public:
      void push(int x)
      {
            st1.push(x);
      }
      int pop()
      {
            if (st1.empty() && st2.empty())
            {
                  cout << " Queue is empty " << endl;
                  return -1;
            }
            if (st2.empty())
            {
                  while (!st1.empty())
                  {
                        st2.push(st1.top());
                        st1.pop();
                  }
            }
            int ab = st2.top();
            st2.pop();
            return ab;
      }
      bool empty()
      {
            if (st1.empty() && st2.empty())
            {
                  return true;
            }
            return false;
      }
};
int main()
{
      Que st;
      st.push(1);
      st.push(2);
      st.push(3);
      st.push(4);
      st.push(5);
      cout << st.pop() << endl;
      cout << st.empty() << endl;

      return 0;
} */

// Implement using recursively
#include <iostream>
#include <stack>
using namespace std;
class Que
{
      stack<int> st1;

public:
      void push(int x)
      {
            st1.push(x);
      }
      int pop()
      {
            if (st1.empty())
            {
                  cout << " Queue is empty " << endl;
                  return -1;
            }
            int x = st1.top();
            st1.pop();
            if (st1.empty())
            {
                  return x;
            }
            int item = pop();
            st1.push(x);
            return item;
      }
      bool empty()
      {
            if (st1.empty())
            {
                  return true;
            }
            return false;
      }
};
int main()
{
      Que st;
      st.push(1);
      st.push(2);
      st.push(3);
      st.push(4);
      st.push(5);
      cout << st.pop() << endl;

      cout << st.empty() << endl;
      // for (auto i : st)
      // {
      //      cout << i << " ";
      // }

      return 0;
}