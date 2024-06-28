#include <iostream>
using namespace std;
class node
{
public:
      int data;
      node *prev;
      node *next;
      node(int Value)
      {
            data = Value;
            prev = NULL;
            next = NULL;
      }
      // this is distractor
      ~node()
      {
            int val = this->data;
            if (next != NULL)
            {
                  delete next;
                  next = NULL;
            }
            cout << "memeory free for node " << val << endl;
      }
};
// code for print the element of dubuly linkedlist
void print(node *head)
{
      node *temp = head;   // here temp points to head
      while (temp != NULL) // until last node not reach to null
      {
            cout << temp->data << "->";
            temp = temp->next;
      }
      cout << "NULL";
}
void inserAtHead(node *&head, int data)
{
      node *temp = head;
      node *insert = new node(data);
      insert->next = temp;
      head->prev = temp;
      head = insert;
}
void insertAtTail(node *&tail, int data)
{
      node *put = new node(data);
      tail->next = put;
      put->prev = tail;
      tail = put;
}
void insertInMiddle(node *&head, node *&tail, int data, int pos)
{
      if (pos == 1)
      {
            inserAtHead(head, data);
            return;
      }
      node *put = new node(data);
      node *temp = head;
      int cnt = 1;
      while (cnt < pos - 1)
      {
            temp = temp->next;
            cnt++;
      }
      if (temp->next == NULL)
      {
            insertAtTail(tail, data);
            return;
      }
      put->next = temp->next;
      temp->next->prev = put;
      temp->next = put;
      put->prev = temp;
}
node *Reverse(node *&head)
{
      node *pre = NULL;
      node *curr = head;
      node *nextp = head->next;
      while (curr != NULL)
      {
            curr->next = pre;
            if(nextp!=NULL)
            {
            curr->prev = nextp;
            }
            pre = curr;
            curr = nextp;
            if(curr!=NULL)
            {
            nextp = nextp->next;
            }
      }
      return pre;
}
int main()
{
      node *headl = new node(13);
      node *head = headl;
      node *tail = headl;
      print(head);
      inserAtHead(head, 23);
      inserAtHead(head, 4);
      inserAtHead(head, 8);
      cout << endl;
      print(head);
      cout << endl;
      node *ans = Reverse(head);
      print(ans);
      // cout << endl;
      return 0;
}