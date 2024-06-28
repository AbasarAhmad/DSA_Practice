#include <iostream>
#include <vector>
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
node *InsertDataIntoBST(node *root, int data)
{
      if (root == NULL)
      {
            root = new node(data);
            return root;
      }
      if (data > root->data)
      {
            root->right = InsertDataIntoBST(root->right, data);
      }
      else

      {
            root->left = InsertDataIntoBST(root->left, data);
      }
      return root;
}
void BuildBst(node *&root)
{
      cout << "Enter data :" << endl;
      int data;
      cin >> data;
      while (data != -1)
      {
            root = InsertDataIntoBST(root, data);
            cout << "Enter the element" << endl;
            cin >> data;
      }
}
void inOrderPrint(node *&root)
{
      if (root == NULL)
      {
            return;
      }
      inOrderPrint(root->left);
      cout << root->data << " ";
      inOrderPrint(root->right);
}
bool solve(node *root, int min, int max)
{
      if (root == NULL)
      {
            return true;
      }
      if (root->data >= min && root->data <= max)
      {
            bool left = solve(root->left, min, root->data);
            bool right = solve(root->right, root->data, max);
            return left && right;
      }
      else
      {
            return false;
      }
}
bool isValid(node *root)
{
      return solve(root, INT_MIN, INT_MAX);
}

int main()
{
      // node *root = NULL;
      // BuildBst(root);
      node *root = new node(23);
      root->left = new node(12);
      root->left->left = new node(32);
      root->left->right = new node(25);
      root->right = new node(42);
      inOrderPrint(root);
      cout << endl;
      if (isValid(root))
      {
            cout << " Valid BST";
      }
      else
      {
            cout << "Invalid bst";
      }

      return 0;
}