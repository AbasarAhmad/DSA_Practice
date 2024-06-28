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
int lengthOfLin(node *head)
{
      node *temp = head;
      int cnt = 0;
      while (temp != NULL)
      {
            temp = temp->next;
            cnt++;
      }
      return cnt;
}
int MiddleElePri(node *head, int k)
{
      node *temp = head;
      int cnt = 0;
      while (cnt < k)
      {
            temp = temp->next;
            cnt++;
      }
      return temp->data;
}
// OR
node *GetMiddle(node *head)
{
      // if linkedlist have null or one element
      if (head == NULL || head->next == NULL)
      {
            return head;
      }
      // if there will be two element
      if (head->next->next == NULL)
      {
            return head->next;
      }
      node *slow = head;
      node *fast = head->next;
      while (fast != NULL)
      {
            fast = fast->next;
            if (fast != NULL)
            {
                  fast = fast->next;
            }
            slow = slow->next;
      }
      cout << "Middle element is " << slow->data;
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
      int i = n / 2;
      cout << "Middle elment is " << MiddleElePri(head, i) << endl;
      GetMiddle(head);

      return 0;
}