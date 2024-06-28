/* #include <iostream>
#define n 100
using namespace std;
class stack
{
      int top;
      int *arr;

public:
      stack()
      {
            arr = new int[n];
            top = -1;
      }
      void push(int x)
      {
            if (top == n - 1)
            {
                  cout << "stack is overflow" << endl;
                  return;
            }
            else
            {
                  top++;
                  arr[top] = x;
            }
      }
      void pop()
      {
            if (top == -1)
            {
                  cout << "stack is underflow" << endl;
                  return;
            }
            else
            {
                  top--;
            }
      }
      int Top()
      {
            if (top == -1)
            {
                  cout << "stack is underflow" << endl;
                  return -1;
            }
            return arr[top];
      }
      bool Empty()
      {
            if (top == -1)
            {
                  return true;
            }
            else
            {
                  return false;
            }
      }
      void print()
      {
            if (top == -1)
            {
                  cout << "stack is allready empty" << endl;
                  return;
            }
            while (top != -1)
            {
                  cout << arr[top] << " ";
                  top--;
            }
      }
};

int main()
{

      stack st;

      cout << "Top element is " << st.Top() << endl;
      cout << "is Stack is empty  " << st.Empty() << endl;
      st.pop();
      st.push(3);
      st.push(45);
      st.push(18);
      st.push(30);
      cout << "Top element is " << st.Top() << endl;
      cout << "elements of stack is  : ";
      st.print();
      return 0;
} */

#include <iostream>
using namespace std;
class stack
{
public:
      int top;
      int *arr;
      int size;
      stack(int size)
      {
            this->size = size;
            arr = new int[size];
            top = -1;
      }
      void push(int x)
      {
            if (top == size - 1)
            {
                  cout << "stack is overflow" << endl;
                  return;
            }
            else
            {
                  top++;
                  arr[top] = x;
            }
      }
      void pop()
      {
            if (top == -1)
            {
                  cout << "stack is underflow" << endl;
                  return;
            }
            else
            {
                  top--;
            }
      }
      int Top()
      {
            if (top == -1)
            {
                  cout << "stack is underflow" << endl;
                  return -1;
            }
            return arr[top];
      }
      bool Empty()
      {
            if (top == -1)
            {
                  return true;
            }
            else
            {
                  return false;
            }
      }
      void print()
      {
            if (top == -1)
            {
                  cout << "stack is allready empty" << endl;
                  return;
            }
            while (top != -1)
            {
                  cout << arr[top] << " ";
                  top--;
            }
      }
};
int main()
{
      stack st(20);
      cout << "Top element is " << st.Top() << endl;
      cout << "is Stack is empty  " << st.Empty() << endl;
      st.pop();
      st.push(3);
      cout << "is Stack is empty  " << st.Empty() << endl;
      st.push(45);
      st.push(18);
      st.push(30);
      cout << "Top element is " << st.Top() << endl;

      return 0;
}