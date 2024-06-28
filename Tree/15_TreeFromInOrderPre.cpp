// Program to Create a tree with the help of Inorder and PostOrder
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

void inOrderr(node *root)
{
      if (root == NULL)
      {
            return;
      }
      inOrderr(root->left);
      cout << root->data << " ";
      inOrderr(root->right);
}
int findPosition(int in[], int element, int n)
{
      for (int i = 0; i < n; i++)
      {
            if (in[i] == element)
            {
                  return i;
            }
      }
      return -1;
}
node *solve(int In[], int pre[], int preIndex, int stratInorder, int endInOrder, int n)
{
      if (preIndex >= n || stratInorder > endInOrder)
      {
            return NULL;
      }
      int element = pre[preIndex++];
      node *root = new node(element);
      int positionInInorder = findPosition(In, element, n);
      root->left = solve(In, pre, preIndex, stratInorder, positionInInorder - 1, n);
      root->right = solve(In, pre, preIndex, positionInInorder + 1, endInOrder, n);
      return root;
}
node *BuildTree(int In[], int pre[], int n)
{
      int preOrderIndex = 0;
      node *ans = solve(In, pre, preOrderIndex, 0, n - 1, n);
      return ans;
}
int main()
{
      int inOrder[] = {3, 1, 4, 0, 5, 2};
      int preOrder[] = {0, 1, 3, 4, 2, 5};
      node *roott = BuildTree(inOrder, preOrder, 6);
      inOrderr(roott);
      return 0;
}