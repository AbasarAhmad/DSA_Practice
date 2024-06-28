// Insert IN sorted linked list and Linkedlist will be in sorted
#include <bits/stdc++.h>
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

void printLikedList(node *head)
{
      node *temp = head;
      while (temp != NULL)
      {
            cout << temp->data << " ";
            temp = temp->next;
      }
}
void rearrangeEvenOdd(node *head)
{
      vector<int> vt;
      node *temp = head;
      while (temp != NULL)
      {
            vt.push_back(temp->data);
            temp = temp->next;
      }
      for (int i = 0; i < vt.size(); i++)
      {
      }
      cout << " stack is  ";
      for (auto i : vt)
      {
            cout << i << " ";
      }
      cout << endl;
}
int main()
{
      node *head = NULL;

      insert(head, 1);
      insert(head, 2);
      insert(head, 3);
      insert(head, 4);
      insert(head, 5);
      insert(head, 6);

      printLikedList(head);
      cout << endl;
      rearrangeEvenOdd(head);
      printLikedList(head);
      return 0;
}