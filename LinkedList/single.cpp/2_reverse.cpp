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
void insert(node *&head, int val)
{
      node *ins = new node(val);
      if (head == NULL)
      {
            head = ins;
            return;
      }
      node *temp = head;
      while (temp->next != NULL)
      {
            temp = temp->next;
      }
      temp->next = ins;
}
void print(node *head)
{
      node *temp = head;
      while (temp != NULL)
      {
            cout << temp->data << "->";
            temp = temp->next;
      }
      cout << "NULL";
}
/*
void Reverse(node *&head)
{
      node *pre = NULL;
      node *curr = head;
      node *nextp = NULL;
      while (curr != NULL)
      {
            nextp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nextp;
      }
      head = pre;
} */
// OR
node *Reverse(node *head)
{
      // base case
      if (head == NULL || head->next == NULL)
      {
            return head;
      }
      node *smallhead = Reverse(head->next);
      head->next->next = head;
      head->next = NULL;
      return smallhead;
}
/*
node *Reverse(node *head)
{
      if (head == NULL || head->next == NULL)
      {
            return head;
      }
      node *pre = NULL;
      node *curr = head;
      node *nextp = NULL;
      while (curr != NULL)
      {
            nextp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nextp;
      }
      return pre;
} */

int main()
{
      node *head = NULL;
      cout << "Input the number of nodes:" << endl;
      int n, k;
      cin >> n;
      for (int i = 1; i <= n; i++)
      {
            cout << "\n Input the data for " << i << " :";
            cin >> k;
            insert(head, k);
      }
      print(head);
      cout << endl;

      cout << "Reverse of linkedlist is:   ";
      // Reverse(head);
      // OR
      node *newhead = Reverse(head);

      print(newhead);
      return 0;
}