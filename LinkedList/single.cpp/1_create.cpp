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

void print(node *&head)
{
      node *temp = head;
      while (temp != NULL)
      {
            cout << temp->data << "-> ";
            temp = temp->next;
      }
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
      // int len = lengthOfLin(head);
      // cout << "Length of linkedList " << len << endl;
      return 0;
}