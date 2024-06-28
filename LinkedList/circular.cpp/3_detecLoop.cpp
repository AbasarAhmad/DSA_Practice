#include <iostream>
using namespace std;
class node
{
public:
      int data;
      node *next;
      node(int value)
      {
            data = value;
            next = NULL;
      }
};
void print(node *tail)
{
      if (tail == NULL)
      {
            cout << "list is empty" << endl;
      }
      node *temp = tail;
      do
      {
            cout << tail->data << "->";
            tail = tail->next;
      } while (tail != temp);
      cout << "NULL";
}
void inserNode(node *&tail, int element, int d)
{
      // empty list
      if (tail == NULL)
      {
            node *newNode = new node(d);
            tail = newNode;
            newNode->next = newNode;
      }
      else
      {
            // non empty list;
            // assuming that the element is present in the list
            node *curr = tail;
            while (curr->data != element)
            {
                  curr = curr->next;
            }
            // element found -> curr is representing element wala node
            node *temp = new node(d);
            temp->next = curr->next;
            curr->next = temp;
      }
}
bool isCircular(node *head)
{
      if (head == NULL)
      {
            return true;
      }
      node *temp = head->next;
      // if node node
      while (temp != head && temp != NULL)
      {
            temp = temp->next;
      }
      if (temp == head)
      {
            return true;
      }
      return false;
}
int main()
{
      node *tail = NULL;
      inserNode(tail, 5, 3);
      print(tail);
      cout << endl;
      inserNode(tail, 3, 5);
      print(tail);
      cout << endl;
      inserNode(tail, 5, 8);
      print(tail);
      cout << endl;
      inserNode(tail, 3, 9);
      print(tail);
      cout << endl;
      // To check the linkedlist is circular of not
      if (isCircular(tail))
      {
            cout << "linkedlist is circular" << endl;
      }
      else
      {
            cout << "linkedlist is not circular" << endl;
      }

      return 0;
}