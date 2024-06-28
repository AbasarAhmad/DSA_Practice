// Kth Ancestor in a tree;
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

node *lca(node *root, int &k, int element)
{
      if (root == NULL)
      {
            return NULL;
      }
      if (root->data == element)
      {
            return root;
      }
      node *leftAns = lca(root->left, k, element);
      node *rightAns = lca(root->right, k, element);

      if (leftAns != NULL && rightAns == NULL)
      {
            k--;
            if (k <= 0)
            {
                  k = INT_MAX;
                  // here locked the root
                  return root;
            }
            return leftAns;
      }

      else if (leftAns == NULL && rightAns != NULL)
      {
            k--;
            if (k <= 0)
            {
                  k = INT_MAX;
                  return root;
            }
            return rightAns;
      }
      else
      {
            return NULL;
      }
}
int HighestLCA(node *root, int position, int element)
{
      node *ab = lca(root, position, element);
      if (ab == NULL || ab->data == element)
      {
            return -1;
      }
      else
      {
            return ab->data;
      }
}
int main()
{
      // 1 3 7 - 1 - 1 11 - 1 - 1 5 17 - 1 - 1 - 1
      node *root = NULL;
      root = build(root);
      inOrder(root);
      cout << endl;
      int n1, k;
      cout << "enter element " << endl;
      cin >> n1;
      cout << "Enter the position till you want ancestor" << endl;
      cin >> k;
      cout << HighestLCA(root, k, n1);

      return 0;
}