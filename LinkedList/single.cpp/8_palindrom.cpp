#include <iostream>
#include <vector>
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
bool CheckPalindrome(vector<int> aar)
{
      int n = aar.size();
      int s = 0;
      int e = n - 1;
      while (s <= e)
      {
            if (aar[s] != aar[e])
            {
                  return 0;
            }
            s++;
            e--;
      }
      return 1;
}
bool isPalindrome(node *head)
{
      // Creating an array
      vector<int> aar;
      node *temp = head;
      while (temp != NULL)
      {
            aar.push_back(temp->data);
            temp = temp->next;
      }
      return CheckPalindrome(aar);
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
      int ans = isPalindrome(head);
      if (ans)
      {
            cout << "Linkedlist is Palindrome" << endl;
      }
      else
      {
            cout << "not Palindrome" << endl;
      }
      return 0;
}