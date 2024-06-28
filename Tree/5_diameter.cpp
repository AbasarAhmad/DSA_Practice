// Highest distance between two nodes
#include <iostream>
using namespace std;
class node
{
public:
      int data;
      node *left;
      node *right;
      node(int d)
      {
            data = d;
            left = NULL;
            right = NULL;
      }
};
node *BuildTree(node *root)
{
      cout << "Enter the data: " << endl;
      int data;
      cin >> data;
      root = new node(data);
      if (data == -1)
      {
            return NULL;
      }
      cout << "Enter data for inserting in left " << root->data << endl;
      root->left = BuildTree(root->left);

      cout << "Enter data for inserting in right " << root->data << endl;
      root->right = BuildTree(root->right);
      return root;
}
void InOrder(node *root)
{
      if (root == NULL)
      {
            return;
      }
      InOrder(root->left);
      cout << root->data << " ";
      InOrder(root->right);
}
int Height(node *abc)
{
      if (abc == NULL)
      {
            return 0;
      }
      int leftnode = Height(abc->left);
      int rightnode = Height(abc->right);
      int ans = max(leftnode, rightnode) + 1;
      return ans;
}
/* int DiameterOfTree(node *abc)
{
      if (abc == NULL)
      {
            return 0;
      }
      // int opt1 = DiameterOfTree(abc->left);
      // int opt2 = DiameterOfTree(abc->right);
      int ans = Height(abc->left) + Height(abc->right) + 1;
      // cout << "opt is " << ans << endl;
      // int ans = max(opt1, max(opt2, opt3));
      return ans;
} */
// second method for find diameter  using pair method
pair<int, int> DiameterFast(node *root) // first int is diameter and second int is height
{
      if (root == NULL)
      {
            pair<int, int> p = make_pair(0, 0); // if root root NULL then both int will be zero
            return p;
      }
      pair<int, int> left = DiameterFast(root->left);
      pair<int, int> right = DiameterFast(root->right);
      int opt1 = left.first;
      int opt2 = right.first;
      int opt3 = left.second + right.second + 1;
      pair<int, int> ans;
      ans.first = max(opt1, max(opt2, opt3));
      ans.second = max(left.second, right.second) + 1;
      return ans;
}
int DiameterOfTree(node *root)
{
      return DiameterFast(root).first;
}
int main()
{
      // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
      node *root = NULL;
      // creating a Tree;
      root = BuildTree(root);
      InOrder(root);
      cout << endl;
      // cout << DiameterOfTree(root);
      // cout << +
      cout << DiameterOfTree(root);
      cout << endl;
      cout << Height(root);
      return 0;
}