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
void insert(node *&head, int val)
{
      node *n = new node(val);
      if (head == NULL)
      {
            head = n;
            return;
      }
      node *temp;
      temp = head;
      while (temp->next != NULL)
      {
            temp = temp->next;
      }
      temp->next = n;
}
node *reverseKnode(node *&head, int k)
{
      // base case
      if (head == NULL)
      {
            return NULL;
      }
      // step1 : revesre first K nodes
      node *nextp = NULL;
      node *curr = head;
      node *prev = NULL;
      int cont = 0;
      while (curr != NULL && cont < k)
      {
            nextp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nextp;
            cont++;
      }
      // step2:- recursion will solve this
      if (nextp != NULL)
      {
            head->next = reverseKnode(curr, k);
      }
      // return head of reversed list
      return prev;
}
// to find that linklist is circular of not
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
void display(node *head)
{
      node *temp;
      temp = head;
      while (temp != NULL)
      {
            cout << temp->data << "->";
            temp = temp->next;
      }
      cout << "NULL";
}
int main()
{
      node *head;
      head = NULL;
      cout << "Size of link list " << endl;
      int n, val;
      cin >> n;
      for (int i = 1; i <= n; i++)
      {
            cout << "Enter value of node " << i << ":  ";
            cin >> val;
            insert(head, val);
      }
      display(head);
      cout << endl;
      cout << "\n Enter the steps to reverse" << endl;
      int k;
      cin >> k;
      node *store = reverseKnode(head, k);
      display(store);
      cout << endl;
      if (isCircular(head))
      {
            cout << "linkedlist is circular" << endl;
      }
      else
      {
            cout << "linkedlist is not circular" << endl;
      }

      return 0;
}