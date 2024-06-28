// in this question we find the smallest nth node of a bst
// we just trival in inOrder becaue we know inorder will be in accending order

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
// Kth Smallest element
void KthElementPrint(node *root, int &i, int k)
{
      if (root == NULL)
      {
            return;
      }
      KthElementPrint(root->left, i, k);
      i++;
      if (i == k)
      {
            cout << root->data;
      }
      KthElementPrint(root->right, i, k);
}
// KthLargest Element
void KthLargestElementPrint(node *root, int &i, int k)
{
      if (root == NULL)
      {
            return;
      }
      KthLargestElementPrint(root->right, i, k);
      i++;
      if (i == k)
      {
            cout << root->data;
      }
      KthLargestElementPrint(root->left, i, k);
}

int main()
{
      node *root = NULL;
      BuildBst(root);
      int i = 0;
      KthElementPrint(root, i, 3);
      cout << endl;
      int k = 0;
      KthLargestElementPrint(root, k, 3);
      return 0;
}