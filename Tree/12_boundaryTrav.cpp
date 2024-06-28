// Program to print boundary nodes of tree
// program to print zig zag traversal
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
void TraversLeftNodes(node *root, vector<int> &ans)
{
      if (root == NULL || (root->left == NULL && root->right == NULL))
      {
            return;
      }
      ans.push_back(root->data);
      if (root->left)
      {
            TraversLeftNodes(root->left, ans);
      }
      else
      {
            TraversLeftNodes(root->right, ans);
      }
}
void TraverseLeafNode(node *root, vector<int> &ans)
{
      if (root == NULL)
      {
            return;
      }
      if (root->left == NULL && root->right == NULL)
      {
            ans.push_back(root->data);
            return;
      }
      TraverseLeafNode(root->left, ans);
      TraverseLeafNode(root->right, ans);
}
void TraversRightNodes(node *root, vector<int> &ans)
{
      if (root == NULL || (root->left == NULL && root->right == NULL))
      {
            return;
      }
      if (root->right)
      {
            TraversRightNodes(root->right, ans);
      }
      else
      {
            TraversRightNodes(root->left, ans);
      }
      // jab right vala pointer vapas jayega tb ans vector mai store karna hai
      ans.push_back(root->data);
}
vector<int> BoundaryCondition(node *root)
{
      vector<int> ans;
      if (root == NULL)
      {
            return ans;
      }
      // pushing the root node in ans vector
      ans.push_back(root->data);
      // code for push left nodes not leaf nodes
      TraversLeftNodes(root->left, ans);
      // for Push the leaf(aakhiri nodes) node in ans  vector
      TraverseLeafNode(root->left, ans);
      TraverseLeafNode(root->right, ans);
      // push right Nodes of boundary in ans vector
      TraversRightNodes(root->right, ans);
      return ans;
}
int main()
{
      // 1 3 7 - 1 - 1 11 - 1 - 1 5 17 - 1 - 1 - 1
      node *root = NULL;
      root = build(root);
      inOrder(root);
      cout << endl;
      vector<int> vt;
      vt = BoundaryCondition(root);
      for (auto i : vt)
      {
            cout << i << " ";
      }
      return 0;
}