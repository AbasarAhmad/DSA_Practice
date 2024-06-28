// Program to top view nodes of a tree
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
      if (root == NULL)
      {
            return;
      }
      if (root->left)
      {
            TraversLeftNodes(root->left, ans);
      }
      ans.push_back(root->data);
}

void TraversRightNodes(node *root, vector<int> &ans)
{
      if (root == NULL)
      {
            return;
      }
      ans.push_back(root->data);
      if (root->right)
      {
            TraversRightNodes(root->right, ans);
      }
}
vector<int> TopViewNodes(node *root)
{
      vector<int> ans;
      if (root == NULL)
      {
            return ans;
      }
      // code for push left nodes not leaf nodes
      TraversLeftNodes(root->left, ans);
      //  now push the root nodes
      ans.push_back(root->data);
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
      vt = TopViewNodes(root);
      for (auto i : vt)
      {
            cout << i << " ";
      }
      return 0;
}