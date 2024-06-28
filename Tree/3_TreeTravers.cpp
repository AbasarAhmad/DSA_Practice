// Tree Traversal
//                   1
//                /    \
//               3      5
//             /  \      /  \
//             7   11   17   N
//
// InOrder:- 7 ,3,11,1,17,5
// PreOrder :- 1,3,7,11,5,17
// PostOrder :- 7,11,3,17,5,1
#include <iostream>
#include <queue>
#include <stack>
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
void PreOrder(node *root)
{
      if (root == NULL)
      {
            return;
      }
      cout << root->data << " ";
      PreOrder(root->left);
      PreOrder(root->right);
}
void PostOrder(node *root)
{
      if (root == NULL)
      {
            return;
      }
      PostOrder(root->left);
      PostOrder(root->right);
      cout << root->data << " ";
}
int main()
{
      // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
      node *root = NULL;
      // creating a Tree;
      root = BuildTree(root);
      InOrder(root);
      cout << endl;
      PreOrder(root);
      cout << endl;
      PostOrder(root);
      return 0;
}