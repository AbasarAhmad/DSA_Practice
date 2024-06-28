/* // to check given bst is balancce or not
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

int inOrder(node *root, int &aa)
{
      if (root == NULL)
      {
            return NULL;
      }
      int ab = inOrder(root->left, aa);
      int cd = inOrder(root->right, aa);
      if ((ab - cd) >= 1)
      {
            aa = 0;
      }
      return max(ab, cd) + 1;
}
bool isBalance(node *root)
{
      int ab = 1;
      inOrder(root, ab);
      return ab;
}
int main()
{
      node *root = NULL;
      buildBST(root);
      cout << endl;
      if (isBalance(root))
      {
            cout << "Tree is balance " << endl;
      }
      else
      {
            cout << "Tree is not balance " << endl;
      }

      return 0;
} */
// now convert a normal tree in a balance tree
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

void inOrderPrint(node *root)
{
      if (root == NULL)
      {
            return;
      }
      inOrderPrint(root->left);
      cout << root->data << " ";
      inOrderPrint(root->right);
}
void inOrder(node *root, vector<int> &vt)
{
      if (root == NULL)
      {
            return;
      }
      inOrder(root->left, vt);
      vt.push_back(root->data);
      inOrder(root->right, vt);
}
node *inOrderToBST(int start, int end, vector<int> &vt)
{
      if (start > end)
      {
            return NULL;
      }
      int mid = (start + end) / 2;
      node *root = new node(vt[mid]);
      root->left = inOrderToBST(start, mid - 1, vt);
      root->right = inOrderToBST(mid + 1, end, vt);
      return root;
}
node *buildBalanceTree(node *root)
{
      vector<int> vt;
      inOrder(root, vt);
      return inOrderToBST(0, vt.size() - 1, vt);
}

int main()
{
      node *root = NULL;
      buildBST(root);
      inOrderPrint(root);
      cout << endl;
      cout << root->data << endl;
      node *ab = buildBalanceTree(root);
      cout << ab->data << endl;

      return 0;
}