#include <iostream>
#include <queue>
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
node *BuildTree(node *root)
{
      cout << "Enter data " << endl;
      int data;
      cin >> data;
      if (data == -1)
      {
            return NULL;
      }
      root = new node(data);
      cout << "Enter the left node for " << root->data << endl;
      root->left = BuildTree(root->left);
      cout << "Enter the right data of " << root->data << endl;
      root->right = BuildTree(root->right);
      return root;
}
void LevelOrderPrint(node *root)
{
      queue<node *> qt;
      qt.push(root);
      qt.push(NULL);
      while (!qt.empty())
      {
            if (qt.front() == NULL)
            {
                  qt.pop();
                  if (!qt.empty())
                  {
                        qt.push(NULL);
                  }
                  cout << endl;
            }
            if (qt.front()->left)
            {
                  qt.push(qt.front()->left);
            }
            if (qt.front()->right)
            {
                  qt.push(qt.front()->right);
            }
            cout << qt.front()->data << " ";
            qt.pop();
      }
}
int a = 0;
void NoOfLeaveNode(node *root)
{
      if (root == NULL)
      {
            return;
      }
      if (root->left == NULL && root->right == NULL)
      {
            a++;
      }
      NoOfLeaveNode(root->left);
      NoOfLeaveNode(root->right);
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
int Height(node *root)
{
      if (root == NULL)
      {
            return NULL;
      }
      int le = Height(root->left);
      int ri = Height(root->right);
      int opt = max(le, ri) + 1;
      return opt;
}
bool isBalanceTree(node *root)
{
      if (root == NULL)
      {
            return true;
      }
      bool le = isBalanceTree(root->left);
      bool ri = isBalanceTree(root->right);
      int diff = (Height(root->left) - Height(root->right)) <= 1;
      if (le && ri && diff)
      {
            return 1;
      }
      else
      {
            return false;
      }
}
bool isIdentcalBT(node *root1, node *root2)
{
      if (root1 == NULL && root2 == NULL)
      {
            return true;
      }
      if (root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL)
      {
            return false;
      }
      bool lef = isIdentcalBT(root1->left, root2->left);
      bool ryt = isIdentcalBT(root1->right, root2->right);
      bool diff = root1->data == root2->data;
      if (lef && ryt && diff)
      {
            return true;
      }
      else
      {
            return false;
      }
}
bool CheckSumNode(node *root)
{
      if (root == NULL)
      {
            return true;
      }
      bool lef = CheckSumNode(root->left);
      bool ryt = CheckSumNode(root->right);
      int k = 0;
      if (root->left != NULL)
      {
            int k = 0;
            k = root->left->data;
      }
      if (root->right != NULL)
      {
            k = root->right->data;
      }
      if (root->left->data && root->right->data || root->left->data || root->right->data)
      {
            bool diff = root->data == k;
            if (lef && ryt && diff)
            {
                  return true;
            }
            else
            {
                  return false;
            }
      }
}
vector<int> ZigZagTraversal(node *root)
{
      vector<int> res;
      queue<node *> qt;
      if (root == NULL)
      {
            return res;
      }
      qt.push(root);
      bool LeftToRight = true;
      while (!qt.empty())
      {
            int size = qt.size();
            vector<int> vt(size);
            for (int i = 0; i < size; i++)
            {
                  node *temp = qt.front();
                  qt.pop();
                  int index = LeftToRight ? i : size - i - 1;
                  vt[index] = temp->data;
                  if (temp->left)
                  {
                        qt.push(temp->left);
                  }
                  if (temp->right)
                  {
                        qt.push(temp->right);
                  }
            }
            LeftToRight = !LeftToRight;
            for (auto i : vt)
            {
                  res.push_back(i);
            }
      }
      return res;
}
void LEFT(node *root, vector<int> &vt)
{
      if (root == NULL)
      {
            return;
      }
      if (root->left != NULL)
      {
            vt.push_back(root->data);
      }
      LEFT(root->left, vt);
}
void Leaf(node *root, vector<int> &vt)
{
      if (root == NULL)
      {
            return;
      }
      Leaf(root->left, vt);
      Leaf(root->right, vt);
      if (root->left == NULL && root->right == NULL)
      {
            vt.push_back(root->data);
      }
}
void RIGHT(node *root, vector<int> &vt)
{
      if (root == NULL)
      {
            return;
      }
      if (root->right != NULL)
            ;
      RIGHT(root->right, vt);
      if (root->right != NULL)
      {
            vt.push_back(root->data);
      }
}
vector<int> BoundaryTraversal(node *root)
{
      vector<int> res;
      if (root == NULL)
      {
            return res;
      }
      res.push_back(root->data);
      LEFT(root->left, res);
      Leaf(root, res);
      RIGHT(root->right, res);
      for (auto a : res)
      {
            cout << a << " ";
      }
      return res;
}
// We calculate the sum of longest leaf node of a tree
void SumOfTree(node *root, int sum, int &maxSum, int len, int &maxlen)
{
      if (root == NULL)
      {
            if (len > maxlen)
            {
                  maxlen = len;
                  maxSum = sum;
            }
            else if (len == maxlen)
            {
                  maxSum = max(maxSum, sum);
            }
            return;
      }
      sum = sum + root->data;
      SumOfTree(root->left, sum, maxSum, len + 1, maxlen);
      SumOfTree(root->right, sum, maxSum, len + 1, maxlen);
}
int SumOfLongestLeafOfTree(node *root)
{
      if (root == NULL)
      {
            return NULL;
      }
      int sum = 0;
      int maxSum = 0;
      int len = 0;
      int maxlen = 0;
      SumOfTree(root, sum, maxSum, len, maxlen);
      return maxSum;
}
// we find lowst common Ancestor(LCA)
node *LCA(node *root, int a, int b)
{
      if (root == NULL || root->data == a || root->data == b)
      {
            return root;
      }
      node *leftAns = LCA(root->left, a, b);
      node *rightAns = LCA(root->right, a, b);

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
      (root->right, a, b);
      return root;
}
int main()
{
      // 15 11 4 - 1 - 1 5 - 1 - 1 13 -  1- 1
      // 1 2 3 -1 -1 5 6 -1 -1 8 -1 -1 4 -1 7 -1 9 10 -1 -1 12 -1 -1
      node *root = NULL;
      root = BuildTree(root);
      inOrder(root);
      cout << endl;
      // LevelOrderPrint(root);
      // NoOfLeaveNode(root);
      // cout << "Number of leaves node is " << a << endl;
      // cout << isBalanceTree(root);
      // node *root2 = NULL;
      // root2 = BuildTree(root2);
      // inOrder(root2);
      // cout << endl;
      // cout << isIdentcalBT(root, root2);
      // to check the sum of left and right is equal to root node
      // cout << CheckSumNode(root);
      // For print Zig Zag Traversal
      /*   vector<int> vt = ZigZagTraversal(root);
        cout << "ZigZag Traversal is : ";
        for (auto i : vt)
        {
              cout << i << " ";
        } */
      // to Print boundary nodes
      /*  vector<int> vt = BoundaryTraversal(root);
       for (auto a : vt)
       {
             // cout << a << " ";
       } */
      // we find Sum  of  longest leaf node
      // cout << SumOfLongestLeafOfTree(root);
      // find LCA (lowest common Ancestor)
      cout << "Enter the two value a and b " << endl;
      int a, b;
      cin >> a >> b;
      node *res = LCA(root, a, b);
      cout << res->data;
      return 0;
}