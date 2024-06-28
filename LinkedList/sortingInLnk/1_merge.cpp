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
node *FindMid(node *head)
{
      node *slow = head;
      node *fast = head->next;
      while (fast != NULL || fast->next != NULL)
      {
            slow = slow->next;
            fast = fast->next->next;
      }
      return slow;
}

node *mergeSort(node *head)
{
      if (head == NULL || head->next == NULL)
      {
            return head;
      }
      node *mid = FindMid(head);
      node *left = head;
      node *right = mid->next;
      mid->next = NULL;
      // recursive call to sort both halves
      left = mergeSort(left);
      right = mergeSort(right);
      // merge both left and right halves
      node *res = mergeTwoLin(left, right);
      cout << res->data << " ";
      return res;
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
      cout << "After Sorting is : " << endl;
      node *res = mergeSort(head);
      display(res);

      return 0;
}