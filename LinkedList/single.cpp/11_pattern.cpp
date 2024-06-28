// input :- 1->2->3->4->5->NULL
// OUTPUT :- 1->5->2->4->3->NULL
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
node *RevInPattern(node *head, int val)
{
      if (head->next == NULL)
      {
            cout << head->data;
            return 0;
      }
      node *temp = head;
      int n = val / 2;
      int cnt = 0;
      while (cnt < n)
      {
            node *temp2 = temp;
            node *temp3 = temp2->next;

            while (temp3->next != NULL)
            {
                  temp2 = temp2->next;
                  temp3 = temp3->next;
            }

            node *st = temp->next;
            temp->next = temp3;
            temp3->next = st;
            temp2->next = NULL;
            temp = temp->next->next;

            cnt++;
      }

      return head;
}

int main()
{
      node *head = NULL;
      cout << "Input the number of nodes:" << endl;
      int n, k;
      cin >> n;
      for (int i = 1; i <= n; i++)
      {
            // cout << "\n Input the data for " << i << " :";
            cin >> k;
            insert(head, k);
      }
      print(head);
      cout << endl;
      int len = lengthOfLin(head);
      cout << "Length of linkedList " << len << endl;
      node *ab = RevInPattern(head, len);
      print(ab);
      return 0;
}