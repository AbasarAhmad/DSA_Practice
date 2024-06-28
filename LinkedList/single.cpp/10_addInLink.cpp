// 1->9->9->9 +1 = 2->0->0->0
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
node *AddInLinkedlist(node *head, int val)
{
      node *temp = Reverse(head);
      node *n = new node(val);
      node *p = temp;
      int c = 0;
      static int cnt = 0;
      int sum = 0;
      // create a Node (Dummy) to store the added list data
      node *Dummy = NULL;
      while (p != NULL) // While linked list not empty
      {
            sum = 0;
            sum += p->data; // add  in sum the data of linkedlist
            if (cnt < 1)    // this if condition will run only once time
            {
                  sum += val; // add  data in first node of linkedlist only once
                  cnt++;
            }
            sum = sum + c;      // carry will added in cum
            c = sum / 10;       // now we update the value of carry
            sum = sum % 10;     // Now we take modulo of sum to store in dummy node
            insert(Dummy, sum); // insert addition data in Dummy Node
            p = p->next;
      }
      node *rev = Reverse(Dummy); // Reverse the dummy node and store in rev
      return rev;
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
            cout << "Enter value of link " << i << endl;
            cin >> val;
            insert(head, val);
      }
      display(head);
      cout << endl;
      cout << "Enter the value to add" << endl;
      int value;
      cin >> value;

      node *ans = AddInLinkedlist(head, value);
      display(ans);

      return 0;
}
