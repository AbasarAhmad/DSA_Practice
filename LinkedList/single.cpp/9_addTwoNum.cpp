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
node *Reverse(node *head)
{
      if (head == NULL)
      {
            return NULL;
      }
      node *pre = NULL;
      node *curr = head;
      node *nextp;
      while (curr != NULL)
      {
            nextp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nextp;
      }
      return pre;
}
node *AddTwoNumber(node *head1, node *head2, node *store)
{
      node *head3 = Reverse(head1);
      node *head4 = Reverse(head2);
      node *p = head3;
      node *q = head4;
      int c = 0, s = 0;
      node *head5 = store;
      while (p != NULL || q != NULL || c != 0)
      {
            s = 0;
            if (p != NULL)
            {
                  s += p->data;
            }
            if (q != NULL)
            {
                  s += q->data;
            }
            s += c;
            c = s / 10;
            s = s % 10;
            insert(head5, s);
            if (p != NULL)
            {
                  p = p->next;
            }
            if (q != NULL)
            {
                  q = q->next;
            }
      }
      node *abc = head5;
      return abc;
}
int main()
{
      node *head = NULL;
      cout << "Size of first link list " << endl;
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
      node *head2 = NULL;
      cout << "Size of Second link list " << endl;
      int s, vale;
      cin >> s;
      for (int i = 1; i <= s; i++)
      {
            // cout << "Enter value of link " << i << endl;
            cin >> vale;
            insert(head2, vale);
      }
      display(head2);
      // node *res = Reverse(head2);
      // cout << "Reverse is " << endl;
      // display(res);
      cout << endl;
      node *head8 = NULL;
      node *Res = AddTwoNumber(head, head2, head8);
      node *ans = Reverse(Res);
      cout << "Addition of linkedList is : " << endl;
      display(ans);
      return 0;
}