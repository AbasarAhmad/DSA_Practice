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
// Searching through Recursion call
int findMinValue(node *root)
{
      while (root->left != NULL)
      {
            root = root->left;
      }
      return root->data;
}
node *deletionInBst(node *root, int element)
{
      if (root == NULL)
      {
            return root;
      }
      if (root->data == element)
      {
            // if 0 child means delete leaf node
            if (root->left == NULL && root->right == NULL)
            {
                  delete root;
                  return NULL;
            }
            // if 1 child
            // left child
            if (root->left != NULL && root->right == NULL)
            {
                  node *temp = root->left;
                  delete root;
                  return temp;
            }
            // right child
            if (root->right != NULL && root->left == NULL)
            {
                  node *temp = root->right;
                  delete root;
                  return temp;
            }
            // if 2 child
            if (root->left != NULL && root->right != NULL)
            {
                  int mini = findMinValue(root->right);
                  root->data = mini;
                  root->right = deletionInBst(root->right, mini);
                  return root;
            }
      }
      else if (root->data > element)
      {
            root->left = deletionInBst(root->left, element);
      }
      else
      {
            root->right = deletionInBst(root->right, element);
      }
}

// Searching Maximum Value of Binary Search Tree
// We know last right side node will be maximum node of tree
int findMaxValue(node *root)
{
      while (root->right != NULL)
      {
            root = root->right;
      }

      return root->data;
}
int main()
{
      // 10 8 21 7 27 5 4 3
      node *root = NULL;
      buildBST(root);
      inOrder(root);
      cout << endl;
      cout << "Minimum data of tree is " << findMinValue(root);
      cout << endl;
      cout << "Maximum data of tree is " << findMaxValue(root);
      cout << endl;
      cout << "Enter the element to delete" << endl;
      int element;
      cin >> element;
      node *result = deletionInBst(root, element);
      inOrder(result);

      return 0;
}