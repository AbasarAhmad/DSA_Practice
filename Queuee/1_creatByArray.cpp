/* #include <iostream>
#define n 20
using namespace std;
class queue
{
      int *aar;
      int front;
      int back;

public:
      queue()
      {
            aar = new int[n];
            front = -1;
            back = -1;
      }
      void enqueue(int x)
      {
            if (back == n - 1)
            {
                  cout << "queue is allready fulled" << endl;
                  return;
            }
            back++;
            aar[back] = x;
            if (front == -1)
            {
                  front++;
            }
      }
      void dequeue()
      {
            if (back == -1)
            {
                  cout << "Queue is underflow" << endl;
                  return;
            }
            front++;
      }
      int peek()
      {
            if (back == -1 || front > back)
            {
                  cout << "Queue is empty" << endl;
                  return -1;
            }
            return aar[front];
      }
      bool empty()
      {
            if (back == -1 || front > back)
            {
                  cout << "Queue is empty" << endl;
                  return true;
            }
            return false;
      }
};

int main()
{
      queue qt;
      qt.enqueue(34);
      qt.enqueue(49);
      qt.enqueue(5);
      qt.enqueue(10);
      cout << qt.peek();

      qt.dequeue();
      cout << endl;
      cout << qt.peek() << endl;
      cout << qt.empty() << endl;

      return 0;
} */

#include <iostream>
#include <queue>
using namespace std;

int main()
{
      queue<int> q;
      q.push(1);
      q.push(2);
      q.push(3);
      // q.pop();
      q.emplace(6);
      // Work of q.back() and q.emplace is almost same
      cout << q.front() << endl;
      cout << q.back() << endl;
      cout << q.empty() << endl;
      cout << q.size() << endl;
      return 0;
}