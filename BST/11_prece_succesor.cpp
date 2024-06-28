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
void inOrderPrint(node *&root, vector<int> &vt)
{
      if (root == NULL)
      {
            return;
      }
      inOrderPrint(root->left, vt);
      vt.push_back(root->data);
      inOrderPrint(root->right, vt);
}
// Kth Smallest element
// void PredecessorSuccessor(node *root, int k)
// {
//       vector<int> vt;
//       inOrderPrint(root, vt);
//       for (int i = 0; i < vt.size(); i++)
//       {
//             if (vt[i] == k)
//             {
//                   cout << "Predecessor " << vt[i - 1] << endl;
//                   cout << "Successor " << vt[i + 1] << endl;
//             }
//       }
// }

/* // Another way to solve predecessor and Successor
void PredecessorSuccessor(node *root, int k)
{
      node *temp = root;
      int pre = -1;
      int succ = -1;
      while (temp != NULL && temp->data != k)
      {
            if (temp->data > k)
            {
                  succ = temp->data;
                  temp = temp->left;
            }
            else
            {
                  pre = temp->data;
                  temp = temp->right;
            }
      }
      // for predecessor
      node *lefttree = temp->left;
      while (lefttree != NULL)
      {
            pre = lefttree->data;
            lefttree = lefttree->right;
      }
      // for successor
      node *righttree = temp->right;
      while (righttree != NULL)
      {
            succ = righttree->data;
            righttree = righttree->left;
      }

      cout << "Predecessor is " << pre << endl;
      cout << "Successor is " << succ << endl;
} */
// same solution but pair functon is new
pair<int, int> PredecessorSuccessor(node *root, int k)
{
      node *temp = root;
      int pre = -1;
      int succ = -1;
      while (temp != NULL && temp->data != k)
      {
            if (temp->data > k)
            {
                  succ = temp->data;
                  temp = temp->left;
            }
            else
            {
                  pre = temp->data;
                  temp = temp->right;
            }
      }
      // for predecessor
      node *lefttree = temp->left;
      while (lefttree != NULL)
      {
            pre = lefttree->data;
            lefttree = lefttree->right;
      }
      // for successor
      node *righttree = temp->right;
      while (righttree != NULL)
      {
            succ = righttree->data;
            righttree = righttree->left;
      }

      pair<int, int> ans = make_pair(pre, succ);
      return ans;
}

int main()
{
      node *root = NULL;
      BuildBst(root);
      cout << "Enter the data to find prec---" << endl;
      int k;
      cin >> k;
      // PredecessorSuccessor(root, k);
      PredecessorSuccessor(root, k);

      return 0;
}