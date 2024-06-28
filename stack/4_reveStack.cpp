#include <iostream>
#include <stack>
using namespace std;
void inserAtBottom(stack<int> &st, int ele)
{
      if (st.empty())
      {
            st.push(ele);
            return;
      }
      int tuple = st.top();
      // cout << tuple << " ";
      st.pop();
      inserAtBottom(st, ele);
      st.push(tuple);
}
void reverse(stack<int> &st)
{
      if (st.empty())
      {
            return;
      }
      int ele = st.top();
      st.pop();
      reverse(st);
      inserAtBottom(st, ele);
}

void ElementsOfStack(stack<int> st)
{
      while (!st.empty())
      {
            cout << st.top() << " ";
            st.pop();
      }
}

void Reverse(stack<int> &St)
{
      stack<int> temp;
      while (!St.empty())
      {
            int x = St.top();
            temp.push(x);
            St.pop();
      }
      while (!temp.empty())
      {
            int y = temp.top();
            St.push(y);
            temp.pop();
      }
}
int main()
{
      stack<int> st;
      // cout << "How many time you want push" << endl;
      // int n;
      // cin >> n;
      // int k;
      // for (int i = 0; i < n; i++)
      // {
      //       cin >> k;
      //       st.push(k);
      // }
      // cout << endl;
      // ElementsOfStack(st);
      // cout << endl;

      st.push(1);
      st.push(2);
      st.push(3);
      st.push(4);
      st.push(5);
      st.push(6);
      ElementsOfStack(st);
      // reverse(st);
      // cout << endl;
      cout << "after" << endl;
      Reverse(st);
      ElementsOfStack(st);

      return 0;
}