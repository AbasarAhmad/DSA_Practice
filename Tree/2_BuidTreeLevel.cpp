// Bild a tree in OrderLevel
#include <iostream>
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
// Buill Tree from Level
void BuildFromLevelOrder(node *&root)
{
      queue<node *> q;
      cout << "Enter data: " << endl;
      int data;
      cin >> data;
      root = new node(data);
      q.push(root);
      while (!q.empty())
      {
            node *temp = q.front();
            q.pop();
            cout << "Enter the left data of " << temp->data << endl;
            int leftData;
            cin >> leftData;
            if (leftData != -1)
            {
                  temp->left = new node(leftData);
                  q.push(temp->left);
            }

            cout << "Enter the right data of " << temp->data << endl;
            int rightData;
            cin >> rightData;
            if (rightData != -1)
            {
                  temp->right = new node(rightData);
                  q.push(temp->right);
            }
      }
}

// To calculate the number of leafs
int noOfLeafNodes(node *root)
{
      if (root == NULL)
      {
            return 0;
      }
      if (root->left == NULL && root->right == NULL)
      {
            return 1;
      }
      return noOfLeafNodes(root->left) + noOfLeafNodes(root->right);
}
// second rule to calculte the number of leafs
int cmt = 0;
void CPostOrder(node *root)
{
      if (root == NULL)
      {
            return;
      }
      if (root->left == NULL && root->right == NULL)
      {
            cmt++;
      }
      CPostOrder(root->left);
      CPostOrder(root->right);
}
void inOrder(node *root)
{
}
int main()
{
      node *root = NULL;
      BuildFromLevelOrder(root);
      // cout << noOfLeafNodes(root);
      cout << endl;
      // CPostOrder(root);
      // cout << "leafs in tree is " << cmt;
      return 0;
}