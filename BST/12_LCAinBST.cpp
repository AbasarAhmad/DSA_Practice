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

/* int LCAinBST(node *root, int a, int b)
{
      while (root != NULL)
      {
            if (root->data > a && root->data > b)
            {
                  root = root->left;
            }
            if (root->data < a && root->data < b)
            {
                  root = root->right;
            }
            if (root->data < a && root->data > b || root->data > a && root->data < b)
            {
                  return root->data;
            }
            if (root->data == a && root->data < b || root->data == a && root->data > b || root->data == b && root->data < a || root->data == b && root->data > a)
            {
                  return root->data;
            }
      }
} */
/* // second way to solve
 int LCAinBST(node *root, int a, int b)
{
      while (root != NULL)
      {
            if (root->data > a && root->data > b)
            {
                  root = root->left;
            }
           else if (root->data < a && root->data < b)
            {
                  root = root->right;
            }
            else{
                  return root->data;
            }

      }
}  */
// third way to solve recursevily
node *LCAinBST(node *root, int a, int b)
{
      if (root == NULL)
      {
            return NULL;
      }
      if (root->data < a && root->data < b)
      {
            return LCAinBST(root->right, a, b);
      }
      if (root->data > a && root->data > b)
      {
            return LCAinBST(root->left, a, b);
      }
      return root;
}

int main()
{
      node *root = NULL;
      BuildBst(root);
      int a, b;
      cout << "Enter the first and second data " << endl;
      cin >> a >> b;
      // cout << "LCA of bst is " << LCAinBST(root, a, b);
      node *ab = LCAinBST(root, a, b);
      cout << ab->data;

      return 0;
}