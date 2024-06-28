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
void InsertData(node *&head, int val)
{
      node *n = new node(val);
      if (head == NULL)
      {
            head = n;
            return;
      }
      node *temp = head;
      while (temp->next != NULL)
      {
            temp = temp->next;
      }
      temp->next = n;
}
void display(node *head)
{
      node *temp = head;
      while (temp != NULL)
      {
            cout << temp->data << "->";
            temp = temp->next;
      }
      cout << "NULL";
}

/* // Remove duplicate from unsorting linkedlist through Map
node *RemInUnSortListMap(node *head)
{
      if (head == NULL)
      {
            return NULL;
      }
      map<int, bool> visited;
      node *temp = head;
      while (temp->next != NULL)
      {
            visited[temp->data] = true;
            if (visited[temp->next->data] == true)
            {
                  temp->next = temp->next->next;
            }
            else
            {
                  temp = temp->next;
            }
      }
      return head;
} */

// Remove Duplicate from Unsorted linked list Using normal iteration method
node *RemInUnSortList(node *head)
{

      if (head == NULL)
      {
            return NULL;
      }
      node *curr = head;
      while (curr != NULL)
      {
            node *temp = curr;
            while (temp != NULL)
            {
                  if (temp->next != NULL && curr->data == temp->next->data)
                  {
                        node *next_next = temp->next->next;
                        node *nodeToDelete = temp->next;
                        delete (nodeToDelete);
                        temp->next = next_next;
                  }
                  else
                  {
                        temp = temp->next;
                  }
            }
            curr = curr->next;
      }
      return head;
}
/* // Removes Duplicate's in Accending Order
node *RemDupInAccenOrd(node *head)
{
      if (head == NULL)
      {
            return NULL;
      }
      node *curr = head;
      while (curr != NULL)
      {
            if ((curr->next != NULL) && curr->data == curr->next->data)
            {
                  node *next_next = curr->next->next;
                  node *toDe = curr->next;
                  delete (toDe);
                  curr->next = next_next;
            }
            else
            {
                  curr = curr->next;
            }
      }
      return head;
} */
int main()
{
      node *head1 = NULL;
      node *head = head1;
      InsertData(head, 11);
      InsertData(head, 11);
      InsertData(head, 11);
      InsertData(head, 8);
      InsertData(head, 16);
      InsertData(head, 11);
      display(head);
      cout << endl;
      // SortLinkedList(head);
      // node *outp = RemDupInAccenOrd(head);
      // display(outp);
      // Remove duplicate using Map fuction
      // node *ab = RemInUnSortListMap(head);
      // display(ab);
      // Remove duplicate using Normal Method
      node *bc = RemInUnSortList(head);
      display(bc);

      return 0;
}