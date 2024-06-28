#include <iostream>
#include <map>
using namespace std;
class node
{
public:
      int data;

      node *next;
      // constructor
      node(int data)
      {
            this->data = data;
            this->next = NULL;
      }
};
void inserAtHead(node *&head, int d)
{
      // new node created
      node *temp = new node(d);
      temp->next = head;
      head = temp;
}
void inserAtTail(node *&head, int d)
{
      // new node created
      node *temp = new node(d);
      head->next = temp;
      head = temp;
}

void print(node *head)
{
      node *temp = head;
      while (temp != NULL)
      {
            cout << temp->data << " ";
            temp = temp->next;
      }
}
// To check that is there are loop present;
bool detectLoop(node *head)
{
      if (head == NULL)
      {
            return false;
      }
      map<node *, bool> visited;
      node *temp = head;
      while (temp != NULL)
      {
            // cycle is present then return true and out of function
            if (visited[temp] == true)
            {
                  // cout << "Loop present in " << temp->data << endl;
                  return true;
            }
            visited[temp] = true;
            temp = temp->next;
      }
      return false;
}
void RemoveLoop(node *&head)
{
      node *temp = head;
      if (head == NULL)
      {
            return;
      }
      map<node *, bool> visited;
      while (temp != NULL)
      {
            // cycle is present then return true and out of function
            if (visited[temp->next] == true)
            {
                  temp->next = NULL;
                  // return head;
            }
            visited[temp] = true;
            temp = temp->next;
      }
}
int findFirstNode(node *&head)
{
      int ans = -1;
      node *slow = head;
      node *fast = head;
      while (fast != NULL && fast->next != NULL)
      {
            slow = slow->next;
            fast = fast->next;
            if (fast->next != NULL)
            {
                  fast = fast->next;
            }
            if (slow == fast)
            {
                  ans = fast->data;
                  break;
            }
      }
      if (fast != NULL && fast->next != NULL)
      {
            slow = head;
            while (slow->next != fast->next)
            {
                  slow = slow->next;
                  fast = fast->next;
            }
            ans = slow->next->data;
      }
      return ans;
}
void removeLoop(node *head)
{
      node *slow = head;
      node *fast = head;
      node *ab;
      while (fast != NULL && fast->next != NULL)
      {
            slow = slow->next;
            ab = fast->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                  break;
            }
      }
      ab->next = NULL;
}
int main()
{
      node *nodel = new node(33);

      node *head = nodel;
      node *tail = nodel;

      inserAtTail(tail, 100);
      inserAtTail(tail, 103);
      inserAtTail(tail, 105);
      print(head);
      cout << endl;
      // creting loop in linkedlist
      tail->next = head->next;

      // To know the loop status in linkedlist
      cout << endl;
      // cout << "Loop is in " << findFirstNode(tail);
      cout << endl;

      cout << "DETECT" << endl;
      if (detectLoop(tail))
      {
            cout << "Here loop are present\n";
      }
      else
      {
            cout << "Loop are not present\n";
      }
      // cout << endl;
      // RemoveLoop(head);
      // To know the loop status in linkedlist
      removeLoop(tail);
      if (detectLoop(tail))
      {
            cout << "Here loop are present\n";
      }
      else
      {
            cout << "Loop are not present\n";
      }
      // cout << endl;
      // print(head);
      return 0;
}