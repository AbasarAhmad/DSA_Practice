// Program to merge two bst;
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
node *insert(node *root, int val)
{
      if (root == NULL)
      {
            root = new node(val);
            return root;
      }
      if (root->data > val)
      {
            root->left = insert(root->left, val);
      }
      else
      {
            root->right = insert(root->right, val);
      }
}
void *BuiltBST(node *&root)
{
      cout << "Enter data " << endl;
      int data;
      cin >> data;
      while (data != -1)
      {
            root = insert(root, data);
            cout << "Enter data " << endl;
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
void INORDER(node *root, vector<int> &vt)
{
      if (root == NULL)
      {
            return;
      }
      INORDER(root->left, vt);
      vt.push_back(root->data);
      INORDER(root->right, vt);
}
vector<int> MergeVector(vector<int> a, vector<int> b)
{
      vector<int> vt(a.size() + b.size());
      int i = 0, j = 0, k = 0;
      while (i < a.size() && j < b.size())
      {
            if (a[i] < b[j])
            {
                  vt[k++] = a[i];
                  i++;
            }
            else
            {
                  vt[k++] = b[j];
                  j++;
            }
      }
      while (i < a.size())
      {
            vt[k++] = a[i];
            i++;
      }
      while (j < b.size())
      {
            vt[k++] = b[j];
            j++;
      }
      return vt;
}
node *VectorToBst(int start, int end, vector<int> &vt)
{
      if (start > end)
      {
            return NULL;
      }
      int mid = (start + end) / 2;
      node *root = new node(vt[mid]);
      root->left = VectorToBst(start, mid - 1, vt);
      root->right = VectorToBst(mid + 1, end, vt);
      return root;
}
node *MergeTwoBst(node *root1, node *root2)
{
      vector<int> vt1, vt2, vt3;
      INORDER(root1, vt1);
      INORDER(root2, vt2);
      // for merge the vector
      vt3 = MergeVector(vt1, vt2);
      // for (int i = 0; i < vt3.size(); i++)
      // {
      //       cout << vt3[i] << " ";
      // }
      return VectorToBst(0, vt3.size() - 1, vt3);
}
int main()
{
      // 10 8 5 9 12 14 -1
      // 11 6 7 3 13 15 -1
      node *root = NULL;
      BuiltBST(root);
      node *root2 = NULL;
      cout << endl;
      cout << "Create second BST " << endl;
      BuiltBST(root2);
      inOrder(root);
      cout << endl;
      inOrder(root2);
      cout << endl;
      node *root3 = MergeTwoBst(root, root2);
      inOrder(root3);
      return 0;
}