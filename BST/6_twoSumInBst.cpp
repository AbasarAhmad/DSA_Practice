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
// first we know inOrder of Bst will be always in assending order
// so we firset store all nodes data in assending order in a vector
// and we will start two pointer one from starting and second from last
// if target value will be greate than the addition of vector s first and last value
// then decrease the last pointer if less than value then increase the first pointer i
bool twoSumInBst(node *root, int target)
{
      vector<int> bt;
      inOrder(root, bt);
      int i = 0, j = bt.size() - 1;
      while (i < j)
      {
            if (bt[i] + bt[j] == target)
            {
                  return true;
            }
            if (bt[i] + bt[j] > target)
            {
                  j--;
            }
            else
            {
                  i++;
            }
      }
      return false;
}

int main()
{
      // 10 8 21 7 27 5 4 3
      node *root = NULL;
      buildBST(root);
      cout << "Enter the target value" << endl;
      int target;
      cin >> target;
      cout << twoSumInBst(root, target);

      return 0;
}