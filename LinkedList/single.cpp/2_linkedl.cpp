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
void insertInMiddle(node *&head, int pos, int d)
{
      // to insert in first postition
      if (pos == 1)
      {
            inserAtHead(head, d);
            return;
      }
      // point temp to head
      node *temp = head;
      int cnt = 1;
      while (cnt < pos - 1)
      {
            temp = temp->next;
            cnt++;
      }
      // if (temp->next == NULL)
      // {
      //       inserAtTail(head, d);
      //       return;
      // }
      // create node
      node *Tochange = new node(d);
      Tochange->next = temp->next;
      temp->next = Tochange;
}
void deletion(node *&head, int position)
{
      node *temp = head;
      int ctr = 1;
      while (ctr < position)
      {
            temp = temp->next;
      }
      temp->next = temp->next->next;
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
                  cout << "Loop present in " << temp->data << endl;
                  return true;
            }
            visited[temp] = true;
            temp = temp->next;
      }
      return false;
}
// detect Cycle loop by floyed detect method
bool floydDetectLoop(node *head)
{
      if (head == NULL)
      {
            return NULL;
      }
      node *slow = head;
      node *fast = head;
      while (slow != NULL && fast != NULL)
      {
            fast = fast->next;
            if (fast != NULL)
            {
                  fast = fast->next;
            }
            slow = slow->next;
            if (slow == fast)
            {
                  cout << "loop exist in the data " << slow->data << endl;
                  return slow;
            }
      }
      return NULL;
}
int main()
{
      node *nodel = new node(33);
      // cout << " data is " << nodel->data << endl;
      // cout << " and adderess is " << nodel->next;
      node *head = nodel;
      node *tail = nodel;
      // inserAtHead(head, 23);
      // inserAtHead(head, 99);
      // inserAtHead(head, 50);
      // print(head);
      // Insertion in Tail
      inserAtTail(tail, 100);
      inserAtTail(tail, 103);
      inserAtTail(tail, 105);
      print(head);
      cout << endl;
      // creting loop in linkedlist
      // tail->next = head->next;

      // print(head);
      // To know the loop status in linkedlist
      if (detectLoop(tail))
      {
            cout << "Here loop are present\n";
      }
      else
      {
            cout << "Loop are not present\n";
      }
      cout << endl;
      // by floyd method to know the loop status of linkedlist
      if (floydDetectLoop(head))
      {
            cout << "Here loop are present\n";
      }
      else
      {
            cout << "Loop are not present\n";
      }
      cout << endl;
      // cout << "head's data is " << head->data << endl;
      // cout << "tail's data is " << tail->data << endl;
      // insert in tail
      // insertInMiddle(head, 5, 88);
      // print(head);
      // deletion(head, 3);
      // print(head);

      return 0;
}