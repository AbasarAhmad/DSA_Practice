// Program to construct BST
#include <iostream>
#include <vector>
#include <queue>
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
node *insertIntoBst(node *&root, int data)
{
      if (root == NULL)
      {
            root = new node(data);
            return root;
      }
      // To Insert Into Right side of root
      if (data > root->data)
      {
            root->right = insertIntoBst(root->right, data);
      }
      else
      {
            root->left = insertIntoBst(root->left, data);
      }
      return root;
}
void buildBST(node *&root)
{
      cout << "Enter data " << endl;
      int data;
      cin >> data;
      while (data != -1)
      {
            root = insertIntoBst(root, data);
            cout << "Enter data to insert in BST" << endl;
            cin >> data;
      }
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
void MorrisTraversal(node *root)
{
      node *curr, *pre;
      if (root == NULL)
      {
            return;
      }
      curr = root;
      while (curr != NULL)
      {
            if (curr->left == NULL)
            {
                  cout << curr->data << "  ";
                  curr = curr->right;
            }
            else
            {
                  pre = curr->left;
                  while (pre->right != NULL && pre->right != curr)
                  {
                        pre = pre->right;
                  }
            }
            if (pre->right == NULL)
            {
                  pre->right = curr;
                  curr = curr->left;
            }
            else
            {
                  pre->right = NULL;
                  cout << curr->data << "    ";
                  curr = curr->right;
            }
      }
}

int main()
{
      // 10 8 21 7 27 5 4 3
      node *root = NULL;
      buildBST(root);
      inOrder(root);
      cout << endl;
      cout << "Moris Traversal is " << endl;
      MorrisTraversal(root);

      return 0;
}