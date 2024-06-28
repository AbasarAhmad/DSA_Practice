// Merge two sorted linkedlist
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
node *mergeTwoLin(node *head1, node *head2)
{
      if (head1 == NULL)
      {
            return head2;
      }
      if (head2 == NULL)
      {
            return head1;
      }
      node *dummy = new node(-1);
      node *temp = dummy;
      while (head1 != NULL && head2 != NULL)
      {
            if (head1->data < head2->data)
            {
                  temp->next = head1;
                  temp = head1;
                  head1 = head1->next;
            }
            else
            {
                  temp->next = head2;
                  temp = head2;
                  head2 = head2->next;
            }
      }
      while (head1 != NULL)
      {
            temp->next = head1;
            temp = head1;
            head1 = head1->next;
      }
      while (head2 != NULL)
      {
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
      }
      dummy = dummy->next;
      return dummy;
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
            // cout << "Enter value of link " << i << endl;
            cin >> val;
            insert(head, val);
      }
      display(head);
      cout << endl;
      node *head2;

      head2 = NULL;
      cout << "Size of link2 list " << endl;
      int k, vale;
      cin >> k;
      for (int i = 1; i <= k; i++)
      {
            // cout << "Enter value of link " << i << endl;
            cin >> vale;
            insert(head2, vale);
      }
      display(head2);
      cout << endl
           << "merge linke list is : " << endl;
      node *res = mergeTwoLin(head, head2);
      display(res);

      return 0;
}