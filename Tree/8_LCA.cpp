// calculate lowest common node in Binary Tree
//  program to find the sum of longest leaf nodes
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
node *build(node *root)
{
      cout << "Enter the data " << endl;
      int data;
      cin >> data;
      root = new node(data);
      if (data == -1)
      {
            return NULL;
      }
      cout << "Enter the data for left node of " << root->data << endl;
      root->left = build(root->left);
      cout << "Enter the data for right node of " << root->data << endl;
      root->right = build(root->right);
      return root;
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

node *lca(node *root, int n1, int n2)
{
      if (root == NULL)
      {
            return NULL;
      }
      if (root->data == n1 || root->data == n2)
      {
            return root;
      }
      node *leftAns = lca(root->left, n1, n2);
      node *rightAns = lca(root->right, n1, n2);

      if (leftAns == NULL)
      {
            return rightAns;
      }
      else if (rightAns == NULL)
      {
            return leftAns;
      }
      else
      {
            return root;
      }
}
int main()
{
      // 1 3 7 - 1 - 1 11 - 1 - 1 5 17 - 1 - 1 - 1
      node *root = NULL;
      root = build(root);
      inOrder(root);
      cout << endl;
      int n1, n2;
      cout << "enter first element " << endl;
      cin >> n1;
      cout << "enter second element " << endl;
      cin >> n2;
      node *ab = lca(root, n1, n2);
      cout << "\n common Node is " << endl;
      cout << ab->data;
      return 0;
}