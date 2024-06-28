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
void print(node *&head)
{
      node *temp = head;
      while (temp != NULL)
      {
            cout << temp->data << "->";
            temp = temp->next;
      }
      cout << "NULL";
}
void insertAtHead(node *&head, int data)
{
      node *insert = new node(data);
      insert->next = head;
      head = insert;
}
void insertAtTail(node *&head, int value)
{
      node *insert = new node(value);
      node *temp = head;
      while (temp->next != NULL)
      {
            temp = temp->next;
      }
      temp->next = insert;
      insert->next = NULL;
}
void insertAtMiddle(node *&head, int pos, int val)
{
      if (pos == 1)
      {
            insertAtHead(head, val);
            return;
      }
      node *insert = new node(val);
      node *temp = head;
      int cnt = 1;
      while (cnt < pos - 1)
      {
            temp = temp->next;
            cnt++;
      }
      if (temp->next == NULL)
      {
            insertAtTail(head, val);
            return;
      }
      insert->next = temp->next;
      temp->next = insert;
}
void Deletion(node *&head, int pos)
{
      if (pos == 1)
      {
            node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
      }
      else
      {
            node *cur = head;
            node *pre = NULL;
            int cnt = 1;
            while (cnt < pos)
            {
                  pre = cur;
                  cur = cur->next;
                  cnt++;
            }
            pre->next = cur->next;
            cur->next = NULL;
            delete cur;
      }
}

int main()
{
      node *model = new node(10);
      node *head = model;
      node *tail = model;
      print(head);
      cout << endl;
      cout << "insertion in head" << endl;
      insertAtHead(head, 11);
      insertAtHead(head, 22);
      insertAtHead(head, 33);
      print(head);
      cout << endl;
      cout << "insertion in tail" << endl;
      insertAtTail(head, 44);
      insertAtTail(head, 55);
      print(head);
      cout << endl;
      insertAtMiddle(head, 4, 66);
      insertAtMiddle(head, 8, 80);
      print(head);
      cout << endl;
      cout << "Deletion start" << endl;
      Deletion(head, 8);
      print(head);

      return 0;
}