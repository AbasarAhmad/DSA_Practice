/* // Program to construct BST
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
// just like preorder traversal
void FlattenPatternPrint(node *root)
{
      node *curr = root;

      while (curr != NULL)
      {
            if (curr->left)
            {
                  node *pred = curr->left;
                  while (pred->right)
                  {
                        pred = pred->right;
                  }
                  pred->right = curr->right;
                  curr->right = curr->left;
                  curr->left = NULL;
            }
            curr = curr->right;
      }
      // left part NULL
      curr = root;
      while (curr != NULL)
      {
            cout << curr->data << " ";
            //       curr->left = NULL;
            curr = curr->right;
      }
}

int main()
{
      // 10 8 21 7 27 5 4 3
      node *root = NULL;
      buildBST(root);
      inOrder(root);
      cout << endl;
      cout << "flattern patern is " << endl;
      FlattenPatternPrint(root);

      return 0;
} */

// flatten BST of a sorted list
// Means convert the tree in a linkedlist
#include <iostream>
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
void inOrder(node *root, node *&prev)
{
      if (root == NULL)
      {
            return;
      }
      inOrder(root->left, prev);
      prev->left = NULL;
      prev->right = root;
      prev = root;
      inOrder(root->right, prev);
}

node *twoSumInBst(node *root)
{
      node *dummy = new node(-1);
      node *prev = dummy;

      inOrder(root, prev);
      prev->left = NULL;
      prev->right = NULL;
      node *res = dummy->right;
      return res;
}

int main()
{
      // 10 8 21 7 27 5 4 3
      node *root = NULL;
      buildBST(root);
      node *ab = twoSumInBst(root);
      while (ab != NULL)
      {
            cout << ab->data << " ";
            ab = ab->right;
      }
      return 0;
}