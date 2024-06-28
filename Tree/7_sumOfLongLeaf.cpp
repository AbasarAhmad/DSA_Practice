// program to find the sum of longest leaf nodes
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
      cout << "Enter the data for left node" << endl;
      root->left = build(root->left);
      cout << "Enter the data for right node" << endl;
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
      cout << root->data << " ",
          inOrder(root->right);
}
void solve(node *root, int sum, int &maxsum, int len, int &maxlen)
{
      if (root == NULL)
      {
            if (len > maxlen)
            {
                  maxlen = len;
                  maxsum = sum;
            }
            else if (len == maxlen)
            {
                  maxsum = max(sum, maxsum);
            }
            return;
      }
      sum = sum + root->data;
      solve(root->left, sum, maxsum, len + 1, maxlen);
      solve(root->right, sum, maxsum, len + 1, maxlen);
}
int sumOfLongestRootNodePath(node *root)
{
      int len = 0;
      int maxlen = 0;
      int sum = 0;
      int maxSum = INT_MIN;
      solve(root, sum, maxSum, len, maxlen);
      return maxSum;
}
int main()
{
      // 1 3 7 - 1 - 1 11 - 1 - 1 5 17 - 1 - 1 - 1
      node *root = NULL;
      root = build(root);
      inOrder(root);
      cout << endl;
      cout << sumOfLongestRootNodePath(root);
      return 0;
}