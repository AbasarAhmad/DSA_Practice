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

// detect Cycle loop by floyed detect method
node *floydDetectLoop(node *head)
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
} // to know the starting loop number
node *getStartingLoop(node *head)
{
      if (head == NULL)
      {
            return NULL;
      }
      node *intersection = floydDetectLoop(head);
      node *slow = head;
      while (slow != intersection)
      {
            slow = slow->next;
            intersection = intersection->next;
      }
      return slow;
}
void RemoveLoop(node *&head)
{
      if (head == NULL)
      {
            return;
      }
      node *getS = getStartingLoop(head);
      node *temp = getS;
      while (temp->next != getS)
      {
            temp = temp->next;
      }
      temp->next = NULL;
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
      node *get = getStartingLoop(head);
      cout << "Starting of loop is " << get->data << endl;
      RemoveLoop(head);
      // by floyd method to know the loop status of linkedlist
      if (floydDetectLoop(head))
      {
            cout << "Here loop are present\n";
      }
      else
      {
            cout << "Loop are not present\n";
      }

      return 0;
}