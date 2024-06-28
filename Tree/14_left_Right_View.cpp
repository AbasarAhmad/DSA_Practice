/* // Program to Left  view nodes of a tree
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
void solve(node *root, vector<int> &ans, int level)
{
      if (root == NULL)
      {
            return;
      }
      if (level == ans.size())
      {

            ans.push_back(root->data);
      }

      solve(root->left, ans, level + 1);
      solve(root->right, ans, level + 1);
}
vector<int> LeftView(node *root)
{
      vector<int> ans;
      if (root == NULL)
      {
            return ans;
      }
      solve(root, ans, 0);
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
      vt = LeftView(root);
      for (auto i : vt)
      {
            cout << i << " ";
      }
      return 0;
} */

// Program to Right  view nodes of a tree
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
void solve(node *root, vector<int> &ans, int level)
{
      cout << level << " ";
      if (root == NULL)
      {
            return;
      }
      if (level == ans.size())
      {

            ans.push_back(root->data);
      }

      solve(root->right, ans, level + 1);
      solve(root->left, ans, level + 1);
}
vector<int> RightView(node *root)
{
      vector<int> ans;
      if (root == NULL)
      {
            return ans;
      }
      solve(root, ans, 0);
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
      vt = RightView(root);
      cout << endl;
      for (auto i : vt)
      {
            cout << i << " ";
      }
      return 0;
}