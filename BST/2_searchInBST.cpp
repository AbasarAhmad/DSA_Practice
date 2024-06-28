// Program to construct BST
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class node
{
public:
      int data;
      node *left;
      node *right;
      node(int val)
      {
            data = val;
            left = NULL;
            right = NULL;
      }
};
node *insertIntoBst(node *&root, int data)
{
      if (root == NULL)
      {
            root = new node(data);
            return root;
      }
      // To Insert Into Right side of root
      if (data > root->data)
      {
            root->right = insertIntoBst(root->right, data);
      }
      else
      {
            root->left = insertIntoBst(root->left, data);
      }
      return root;
}
void buildBST(node *&root)
{
      cout << "Enter data " << endl;
      int data;
      cin >> data;
      while (data != -1)
      {
            root = insertIntoBst(root, data);
            cout << "Enter data to insert in BST" << endl;
            cin >> data;
      }
}
void inOrder(node *root)
{
      if (root == NULL)
      {
            return;
      }
      inOrder(root->left);
      cout << root->data << " ";
      inOrder(root->right);
}
/* // Searching through Recursion call
bool findPresent(node *root, int element)
{
      if (root == NULL)
      {
            return false;
      }
      if (root->data == element)
      {
            return true;
      }
      if (root->data > element)
      {
            findPresent(root->left, element);
      }
      else
      {
            findPresent(root->right, element);
      }
} */

// Searching through Iterative call
bool findPresent(node *root, int element)
{
      node *temp = root;
      while (temp != NULL)
      {
            if (temp->data == element)
            {
                  return true;
            }
            if (temp->data > element)
            {
                  temp = temp->left;
            }
            else
            {
                  temp = temp->right;
            }
      }
      return false;
}
int main()
{
      // 1 3 7 - 1 - 1 11 - 1 - 1 5 17 - 1 - 1 - 1
      node *root = NULL;
      buildBST(root);
      inOrder(root);
      cout << endl;
      cout << "Enter data to search" << endl;
      int eleme;
      cin >> eleme;
      if (findPresent(root, eleme))
      {
            cout << "element is present" << endl;
      }
      else
      {
            cout << "element is not present" << endl;
      }

      return 0;
}