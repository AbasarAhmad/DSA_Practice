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
void Insert(stack<int> &st, int cont, int val, int size)
{
      // we can use another logic we give the base case that if stack is empty " st.empty" then then
      // we push element and return
      if (cont == size)
      {
            // cout << "the value of cont is " << cont << " and size is" << size;
            st.push(val);
            return;
      }
      int store = st.top();
      st.pop();
      Insert(st, cont + 1, val, size);
      st.push(store);
}
void InsertAtBottom(stack<int> &st, int val)
{
      int n = st.size();
      int cont = 0;
      Insert(st, cont, val, n);
}
int main()
{
      stack<int> st;
      st.push(23);
      st.push(17);
      st.push(40);
      st.push(11);
      st.push(99);
      print(st);
      cout << "\nEnter the value to insert" << endl;
      int val;
      cin >> val;
      InsertAtBottom(st, val);
      cout << "\n After insert value linkedlist show" << endl;
      print(st);
      return 0;
}