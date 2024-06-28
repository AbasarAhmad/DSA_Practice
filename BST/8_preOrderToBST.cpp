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
node *InsertDataIntoBST(node *root, int data)
{
      if (root == NULL)
      {
            root = new node(data);
            return root;
      }
      if (data > root->data)
      {
            root->right = InsertDataIntoBST(root->right, data);
      }
      else

      {
            root->left = InsertDataIntoBST(root->left, data);
      }
      return root;
}
void BuildBst(node *&root)
{
      cout << "Enter data :" << endl;
      int data;
      cin >> data;
      while (data != -1)
      {
            root = InsertDataIntoBST(root, data);
            cout << "Enter the element" << endl;
            cin >> data;
      }
}
void inOrderPrint(node *&root)
{
      if (root == NULL)
      {
            return;
      }
      inOrderPrint(root->left);
      cout << root->data << " ";
      inOrderPrint(root->right);
}
node *solve(vector<int> &vt, int mini, int maxi, int &i)
{
      if (i >= vt.size())
      {
            return NULL;
      }
      if (vt[i] > maxi || vt[i] < mini)
      {
            return NULL;
      }
      node *root = new node(vt[i++]);
      root->left = solve(vt, mini, root->data, i);
      root->right = solve(vt, root->data, maxi, i);
      return root;
}
node *preOrderToBST(vector<int> &vt)
{
      int mini = INT_MIN;
      int maxi = INT_MAX;
      int i = 0;
      return solve(vt, mini, maxi, i);
}
int main()
{
      node *root = NULL;
      // BuildBst(root);
      vector<int> vt;
      vt.push_back(20);
      vt.push_back(10);
      vt.push_back(5);
      vt.push_back(13);
      vt.push_back(15);
      vt.push_back(35);
      vt.push_back(35);
      vt.push_back(42);
      node *ab = preOrderToBST(vt);
      inOrderPrint(ab);

      return 0;
}