// Insert IN sorted linked list and Linkedlist will be in sorted
#include <iostream>
using namespace std;
class node
{
public:
      int data;
      node *next;
      node(int x)
      {
            data = x;
            next = NULL;
      }
};
void insert(node *&head, int k)
{
      node *temp = head;
      node *n = new node(k);
      if (head == NULL)
      {
            head = n;
            return;
      }
      while (temp->next != NULL)
      {
            temp = temp->next;
      }
      temp->next = n;
}
void InsertInSortedLinkedlist(node *&head, int val)
{
      node *temp = head;
      node *n = new node(val);
      if (head == NULL)
      {
            head = n;
            return;
      }
      if (temp->next == NULL)
      {
            if (temp->data > val)
            {
                  cout << "temp->data is " << temp->data << endl;
                  n->next = temp;
                  temp->next = NULL;
                  head = n;
                  return;
            }
            else
            {
                  temp->next = n;
                  return;
            }
      }
      while (temp->next != NULL)
      {
            if (temp->next->data > val)
            {
                  node *ab = temp->next;
                  temp->next = n;
                  n->next = ab;
                  return;
            }

            temp = temp->next;
      }
      temp->next = n;
}
void printLikedList(node *head)
{
      node *temp = head;
      while (temp != NULL)
      {
            cout << temp->data << " ";
            temp = temp->next;
      }
}

int main()
{
      node *head = NULL;
      int n;
      cout << "Enter the Number to Insert In linkedlist" << endl;
      cin >> n;
      cout << "Enter the element in linkedlist" << endl;
      int k;
      for (int i = 0; i < n; i++)
      {
            cin >> k;
            insert(head, k);
      }
      printLikedList(head);
      cout << endl;
      int a;
      cout << "Enter the element in Sorted Linkedlist" << endl;
      cout << endl;
      cin >> a;
      InsertInSortedLinkedlist(head, a);
      cout << "Linkedlist is " << endl;
      printLikedList(head);
      return 0;
}