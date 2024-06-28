// addition of how many path will be equal to k
// calculate lowest common node in Binary Tree
//  program to find the sum of longest leaf nodes
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
void solve(node *root, int k, int &cnt, vector<int> vt)
{
      if (root == NULL)
      {
            return;
      }
      vt.push_back(root->data);
      // left recursive
      solve(root->left, k, cnt, vt);
      solve(root->right, k, cnt, vt);
      int size = vt.size();

      int sum = 0;
      cout << endl;
      for (int i = size - 1; i >= 0; i--)
      {
            cout << vt[i] << " ";
      }
      vt.pop_back();
}
int sumK(node *root, int k)
{
      vector<int> vt;
      int cnt = 0;
      solve(root, k, cnt, vt);
      return cnt;
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
      root = build(root);
      inOrder(root);
      cout << endl;
      int k;
      cout << "Enter the sum" << endl;
      cin >> k;
      sumK(root, k);
      return 0;
}