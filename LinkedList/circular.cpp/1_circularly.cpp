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
void deletetion(node *&tail, int element)
{
      // empty list
      if (tail == NULL)
      {
            cout << "list is empty,please check again" << endl;
            return;
      }
      // assuming that "valur" is present in the linked lis
      else
      {
            node *prev = tail;
            node *curr = prev->next;
            while (curr->data != element)
            {
                  prev = curr;
                  curr = curr->next;
            }
            prev->next = curr->next;
            // 1 Node linkedlist
            if (curr == prev)
            {
                  tail = NULL;
            }
            // >=2 node linkedlist
            else if (tail == curr)
            {
                  tail = prev;
            }
            curr->next = NULL;
            delete curr;
      }
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
      // deletetion(tail, 5);
      // print(tail);

      return 0;
}