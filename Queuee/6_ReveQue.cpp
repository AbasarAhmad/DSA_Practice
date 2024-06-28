/* #include <iostream>
#include <stack>
#include <queue>
using namespace std;
// Reverse Queue using stack
void ReverseQueue(queue<int> &qt)
{
      stack<int> st;
      if (qt.empty())
      {
            cout << "Queue is empty" << endl;
            return;
      }
      while (!qt.empty())
      {
            st.push(qt.front());
            qt.pop();
      }
      while (!st.empty())
      {
            qt.push(st.top());
            st.pop();
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
      cout << "front of queue is " << qt.front() << endl;
      cout << "Back of queue is " << qt.back() << endl;
      ReverseQueue(qt);
      cout << "After Rverse through using a stack" << endl;
      cout << "front of queue is " << qt.front() << endl;
      cout << "Back of queue is " << qt.back() << endl;

      return 0;
}
 */

// Reverse a Queue using Recursion
#include <iostream>
#include <queue>
using namespace std;
// Reverse Queue using stack
void insertInReverse(queue<int> &qt, int element)
{
      if (qt.empty())
      {
            qt.push(element);
            return;
      }
      int tuple = qt.front();
      qt.pop();
      insertInReverse(qt, element);
      qt.push(tuple);
}
void ReverseQueue(queue<int> &qt)
{
      if (qt.empty())
      {
            return;
      }
      int ele = qt.front();
      qt.pop();
      ReverseQueue(qt);
      insertInReverse(qt, ele);
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
      cout << "front of queue is " << qt.front() << endl;
      cout << "Back of queue is " << qt.back() << endl;
      ReverseQueue(qt);
      cout << "After Rverse through using a stack" << endl;
      cout << "front of queue is " << qt.front() << endl;
      cout << "Back of queue is " << qt.back() << endl;

      return 0;
}