/* // INput :- 11,12,13,14,15,16,17,18,19,20
// OUTput ;- 11,16,12,17,13,18,14,19,15,20
#include <iostream>
#include <queue>
using namespace std;
void ReveFromBetween(int aar[], int n)
{
      queue<int> qt;
      queue<int> qt2;
      queue<int> qt3;
      int half = n / 2;
      for (int i = 0; i < half; i++)
      {
            qt.push(aar[i]);
      }
      for (int i = half; i < n; i++)
      {
            qt2.push(aar[i]);
      }
      while (!qt.empty() || !qt2.empty())
      {
            if (!qt.empty())
            {
                  qt3.push(qt.front());
                  qt.pop();
            }
            qt3.push(qt2.front());
            qt2.pop();
      }

      while (!qt3.empty())
      {
            cout << qt3.front() << " ";
            qt3.pop();
      }
}
int main()
{
      int n;
      cout << "Enter the number of element" << endl;
      cin >> n;
      int aar[n];
      cout << "Enter the data " << endl;
      for (int i = 0; i < n; i++)
      {
            cin >> aar[i];
      }
      ReveFromBetween(aar, n);
      return 0;
} */

// Now Using Stack
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
void ReverseFromBetween(queue<int> qt, int n)
{
      stack<int> st;
      int k = n / 2;
      // we input first half of queue in stack
      for (int i = 0; i < k; i++)
      {
            st.push(qt.front());
            qt.pop();
      }
      // while stack is not empty we put all the elment of stack in queue
      while (!st.empty())
      {
            qt.push(st.top());
            st.pop();
      }
      // Now we will reverse half of queue
      int f = n - k;
      while (f--)
      {
            int val = qt.front();
            qt.pop();
            qt.push(val);
      }

      // Again Input the firset half element in stack
      for (int i = 0; i < k; i++)
      {
            st.push(qt.front());
            qt.pop();
      }

      // Now we put one element from stack and one element front front of queue and insert in back of stack
      while (!st.empty())
      {
            int val = st.top();
            st.pop();
            qt.push(val);
            int val2 = qt.front();
            qt.pop();
            qt.push(val2);
      }

      cout << qt.front() << endl;
      cout << qt.back() << endl;
      // Print the element
      while (!qt.empty())
      {
            cout << qt.front() << " ";
            qt.pop();
      }
}
int main()
{
      queue<int> qt;
      int n;
      cout << "Enter the number of value" << endl;
      int k;
      cin >> n;
      for (int i = 0; i < n; i++)
      {
            cin >> k;
            qt.push(k);
      }
      // queue<int> st;
      // st =
      ReverseFromBetween(qt, n);
      return 0;
}