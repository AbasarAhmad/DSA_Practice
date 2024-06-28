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
      cout << "Enter data for inserting in left " << endl;
      root->left = BuildTree(root->left);

      cout << "Enter data for inserting in right " << endl;
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
// Height means = Longest height of tree
int HeightOfTree(node *abc)
{
      if (abc == NULL)
      {
            return 0;
      }
      int leftnode = HeightOfTree(abc->left);
      int rightnode = HeightOfTree(abc->right);
      int ans = max(leftnode, rightnode) + 1;
      return ans;
}
int main()
{
      // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
      node *root = NULL;
      // creating a Tree;
      root = BuildTree(root);
      InOrder(root);
      cout << endl;
      cout << HeightOfTree(root);
      cout << endl;
      return 0;
}