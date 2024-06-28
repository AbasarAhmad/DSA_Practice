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
vector<int> ZigZagTraversal(node *root)
{
      vector<int> res;
      if (root == NULL)
      {
            return res;
      }
      queue<node *> qt;
      qt.push(root);
      int leftToRight = true;
      while (!qt.empty())
      {
            int size = qt.size();
            vector<int> temp(size);
            for (int i = 0; i < size; i++)
            {
                  node *frontd = qt.front();
                  qt.pop();
                  int index = leftToRight ? i : size - i - 1;
                  temp[index] = frontd->data;
                  if (frontd->left)
                  {
                        qt.push(frontd->left);
                  }
                  if (frontd->right)
                  {
                        qt.push(frontd->right);
                  }
            }
            leftToRight = !leftToRight;
            for (auto i : temp)
            {
                  res.push_back(i);
            }
      }
      return res;
}
int main()
{
      // 1 3 7 - 1 - 1 11 - 1 - 1 5 17 - 1 - 1 - 1
      node *root = NULL;
      root = build(root);
      inOrder(root);
      cout << endl;
      vector<int> vt;
      vt = ZigZagTraversal(root);
      for (auto i : vt)
      {
            cout << i << " ";
      }
      return 0;
}