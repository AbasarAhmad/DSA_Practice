#include <iostream>
#include <stack>
#include <queue>
using namespace std;
// INPUT :- 1,2,3,4,5
// OUTPUT :- 2,1,3,4,5
/* void ReverseK_Nodes(queue<int> &qt, int k)
{
      stack<int> st;

      for (int i = 0; i < k; i++)
      {
            int val = qt.front();
            qt.pop();
            st.push(val);
      }
      while (!st.empty())
      {
            qt.push(st.top());
            st.pop();
      }
      int t = qt.size() - k;
      while (t--)
      {
            int val = qt.front();
            qt.pop();
            qt.push(val);
      }
} */
// INPUT :- 1,2,3,4,5
// OUTPUT :- 2,1,4,3,5
void ReverseK_Nodes(queue<int> &qt, int k)
{
      stack<int> st;
      if (qt.size() % 2 == 0)
      {

            for (int j = 1; j < qt.size(); j += k)
            {

                  for (int i = 0; i < k; i++)
                  {
                        int val = qt.front();
                        qt.pop();
                        st.push(val);
                  }
                  while (!st.empty())
                  {
                        qt.push(st.top());
                        st.pop();
                  }
            }
      }
      else
      {
            for (int j = 1; j < qt.size(); j += k)
            {

                  for (int i = 0; i < k; i++)
                  {
                        int val = qt.front();
                        qt.pop();
                        st.push(val);
                  }
                  while (!st.empty())
                  {
                        qt.push(st.top());
                        st.pop();
                  }
            }
            int val = qt.front();
            qt.pop();
            qt.push(val);
      }
}
void print(queue<int> qt)
{
      while (!qt.empty())
      {
            cout << qt.front() << " ";
            qt.pop();
      }
}
int main()
{
      queue<int> qt;
      qt.push(1);
      qt.push(2);
      qt.push(3);
      qt.push(4);
      qt.push(5);
      qt.push(6);
      qt.push(7);
      // qt.push(6);
      cout << "front of queue is " << qt.front() << endl;
      cout << "Back of queue is " << qt.back() << endl;
      print(qt);
      ReverseK_Nodes(qt, 2);
      cout << endl
           << "After Rverse through using a stack" << endl;
      cout << "front of queue is " << qt.front() << endl;
      cout << "Back of queue is " << qt.back() << endl;
      print(qt);
      return 0;
}