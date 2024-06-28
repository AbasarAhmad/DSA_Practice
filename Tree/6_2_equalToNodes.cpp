// check the sum of left and right tree is equal to root node
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
node *BuildTree(node *root)
{
      cout << "Enter data " << endl;
      int data;
      cin >> data;
      root = new node(data);
      if (data == -1)
      {
            return NULL;
      }
      cout << "Enter the left data of " << root->data << endl;
      root->left = BuildTree(root->left);
      cout << "Enter the right data of " << root->data << endl;
      root->right = BuildTree(root->right);
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
pair<bool, int> solve(node *root)
{
      // if root is null then bool will be true and value vill be zero
      if (root == NULL)
      {
            pair<bool, int> p = make_pair(true, 0);
            return p;
      }
      // if root's are leaf node means who doesn't hace left and right sub tree
      if (root->left == NULL && root->right == NULL)
      {
            // here we will return root's data for calculation of uppers data
            pair<bool, int> p = make_pair(true, root->data);
            return p;
      }
      pair<bool, int> lef = solve(root->left);
      pair<bool, int> ryt = solve(root->right);
      bool le = lef.first;
      bool ri = ryt.first;
      // if root node is eqal to additon of left node and right node
      bool dif = root->data == lef.second + ryt.second;
      // here we create pair to update the values
      pair<bool, int> ans;
      // add the left and right nodes data for return the upper node
      ans.second = lef.second + ryt.second;
      if (le && ri && dif)
      {
            ans.first = true;
      }
      else
      {
            ans.first = false;
      }
      return ans;
}
bool isSumEqalToNode(node *root)
{
      // here we call pair function's first who store bool value
      return solve(root).first;
}
int main()
{
      node *root = NULL;
      root = BuildTree(root);
      inOrder(root);
      cout << endl;
      cout << isSumEqalToNode(root);
      return 0;
}