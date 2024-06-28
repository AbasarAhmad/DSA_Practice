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
int main()
{
      // 1 3 7 - 1 - 1 11 - 1 - 1 5 17 - 1 - 1 - 1
      node *root = NULL;
      buildBST(root);
      cout << endl;
      inOrder(root);

      return 0;
}