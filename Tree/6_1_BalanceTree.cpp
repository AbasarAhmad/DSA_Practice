#include <iostream>
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
      cout << "Enter data for inserting in left " << root->data << endl;
      root->left = BuildTree(root->left);

      cout << "Enter data for inserting in right " << root->data << endl;
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
int Height(node *abc)
{
      if (abc == NULL)
      {
            return 0;
      }
      int leftnode = Height(abc->left);
      int rightnode = Height(abc->right);
      int ans = max(leftnode, rightnode) + 1;
      return ans;
}

/*
// To check given Tree is balanced of Not ,[ left part - right part <=1 ]
bool isBalance(node *root)
{
      if (root == NULL)
      {
            return true;
      }
      bool left = isBalance(root->left);
      bool right = isBalance(root->right);
      bool diff = abs(Height(root->left) - Height(root->right)) <= 1;
      if (left && right && diff)
      {
            return 1;
      }
      else
      {
            return false;
      }
} */

// Another way to find the tree is balance or not in Upper solution timeComplexity is n^2
pair<bool, int> FindFast(node *root) // first is boolean and second is integer
{
      if (root == NULL)
      {
            // if root is nUll then first will be true and second will be zero means height will be zero
            pair<bool, int> p = make_pair(true, 0);
            return p; // return pair
      }
      pair<bool, int> lef = FindFast(root->left);
      pair<bool, int> ryt = FindFast(root->right);
      bool lefAns = lef.first; // pahle ka boolean value
      bool rytAns = ryt.first; // dusre ka boolean value
      bool diff = (lef.second - ryt.second) <= 1;
      pair<bool, int> ans;
      ans.second = max(lef.second, ryt.second) + 1;
      if (lefAns && rytAns && diff)
      {
            ans.first = true;
      }
      else
      {
            ans.first = false;
      }
      return ans;
}
bool isBalance(node *root)
{
      return FindFast(root).first;
}
bool isIdentical(node *root1, node *root2)
{
      if (root1 == NULL && root2 == NULL)
      {
            return true;
      }
      if (root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL)
      {
            return false;
      }

      bool left = isIdentical(root1->left, root2->left);
      bool right = isIdentical(root1->right, root2->right);
      bool value = root1->data == root2->data;
      if (left && right && value)
      {
            return true;
      }
      else
      {
            return false;
      }
}
int main()
{
      // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
      node *root = NULL;
      // creating a Tree;
      root = BuildTree(root);
      InOrder(root);
      cout << endl;
      // cout << isBalance(root);
      cout << endl;
      node *root2 = NULL;
      root2 = BuildTree(root2);
      cout << isIdentical(root, root2);
      return 0;
}