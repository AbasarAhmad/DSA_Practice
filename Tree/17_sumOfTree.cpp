//              1                              15
//             /  \                           /  \
//            2    3       TO               11    3
//          /  \                          /   \
//         4    5                        4     5

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
node *builTree(node *root)
{
      cout << "Enter the data " << endl;
      int data;
      cin >> data;
      root = new node(data);
      if (data == -1)
      {
            return NULL;
      }
      cout << "Enter the left data of " << root->data << endl;
      root->left = builTree(root->left);
      cout << "Enter the right data of " << root->data << endl;
      root->right = builTree(root->right);
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
void SumReplace(node *root)
{
      if (root == NULL)
      {
            return;
      }
      SumReplace(root->left);
      SumReplace(root->right);
      if (root->left != NULL)
      {
            root->data += root->left->data;
      }
      if (root->right != NULL)
      {
            root->data += root->right->data;
      }
}
int main()
{
      node *root = NULL;
      root = builTree(root);
      inOrder(root);
      cout << endl;
      SumReplace(root);
      inOrder(root);

      return 0;
}