#include <iostream>
#include <map>
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
void sortLL(node *&head)
{
      if (head == NULL)
            return;

      node *cur = head;

      while (cur->next != NULL)
      {
            node *temp = cur->next;
            while (temp != NULL)
            {
                  if (cur->data >= temp->data)
                  {

                        swap(cur->data, temp->data);
                  }
                  temp = temp->next;
            }
            cur = cur->next;
      }
}
void Removeduplicates(node *&head)
{
      if (head == NULL)
            return;

      map<int, bool> visited;
      node *cur = head;

      while (cur->next != NULL)
      {
            visited[cur->data] = true;
            if (visited[cur->next->data] == true)
            {
                  cur->next = cur->next->next;
            }
            else
            {
                  cur = cur->next;
            }
      }
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
      sortLL(head);
      cout << endl;
      display(head);
      Removeduplicates(head);
      cout << endl;
      display(head);
}