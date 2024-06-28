#include <iostream>
using namespace std;
class node
{
public:
      int data;
      node *next;
      node(int val)
      {
            data = val;
            next = NULL;
      }
};
class queue
{
      node *front;
      node *back;

public:
      queue()
      {
            front = NULL;
            back = NULL;
      }

      void Enqueue(int val)
      {
            node *n = new node(val);
            if (front == NULL)
            {
                  back = n;
                  front = n;
                  return;
            }
            back->next = n;
            back = n;
      }
      void pop()
      {
            if (front == NULL)
            {
                  cout << "Queue is empty" << endl;
                  return;
            }
            node *temp = front;
            front = front->next;

            delete temp;
      }
      int peek()
      {
            if (front == NULL)
            {
                  cout << "underflow means empty queue" << endl;
                  return -1;
            }
            return front->data;
      }
};
int main()
{
      queue qt;
      qt.Enqueue(15);
      qt.Enqueue(18);
      qt.Enqueue(35);
      qt.Enqueue(25);
      cout << qt.peek() << endl;
      qt.pop();
      cout << qt.peek() << endl;
      qt.pop();
      qt.pop();
      cout << qt.peek() << endl;
      qt.pop();
      cout << qt.peek() << endl;
      return 0;
}