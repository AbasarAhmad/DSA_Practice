// Implementation of Dequeue
#include <iostream>
using namespace std;
class Dequeue
{
      int *aar;
      int front;
      int rear;
      int size;

public:
      Dequeue(int n)
      {
            size = n;
            aar = new int(n);
            front = -1;
            rear = -1;
      }
      bool Push_front(int val)
      {
            if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
            {
                  cout << "Queue is allready Full" << endl;
                  return false;
            }
            else if (front == -1)
            {
                  front = rear = 0;
            }
            else if (front == 0 && front != 0)
            {
                  front = size - 1;
            }
            else
            {
                  front--;
            }
            aar[front] = val;
            return true;
      }
      bool Push_rear(int val)
      {
            if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
            {
                  cout << "Queue is allready Full" << endl;
                  return false;
            }
            else if (rear == -1)
            {
                  front = rear = 0;
            }
            else if (rear == size - 1 && front != 0)
            {
                  rear = 0;
            }
            else
            {
                  rear++;
            }
            aar[rear] = val;
            return val;
      }
      int pop_rear()
      {
            if (front == -1)
            {
                  cout << "Queue is allready empty" << endl;
                  return -1;
            }
            int ans = aar[rear];
            aar[rear] = -1;
            if (front == rear)
            {
                  rear = size - 1;
            }
            else
            {
                  rear--;
            }
            return ans;
      }
      int pop_front()
      {
            if (front == -1) // To check Queue is Empty
            {
                  cout << "Queue is Empty " << endl;
                  return -1;
            }
            int ans = aar[front];
            cout << " Dequeue element is " << ans << endl;
            aar[front] = -1;
            if (front == rear)
            { // Single element is present
                  front = rear = -1;
            }
            else if (front == size - 1)
            {
                  front = 0; // To maintain Cyclic Nature
            }
            else
            {
                  front++;
            }
            return ans;
      }
      int getRear()
      {
            if (isEmpty())
            {
                  return -1;
            }
            return aar[rear];
      }
      int getFront()
      {
            if (isEmpty())
            {
                  return -1;
            }
            return aar[front];
      }
      bool isEmpty()
      {
            if (front == -1)
            {
                  return true;
            }
            else
            {
                  return false;
            }
      }
};
int main()
{
      Dequeue dq(30);
      dq.Push_rear(23);
      dq.Push_rear(10);
      // dq.Push_front(10);
      cout << dq.getFront() << endl;

      cout << dq.getRear() << endl;
      return 0;
}