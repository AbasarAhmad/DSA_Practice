/* #include <iostream>
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
int main()
{
      // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
      node *root = NULL;
      // creating a Tree;
      root = BuildTree(root);
      InOrder(root);
      // cout << endl;
      return 0;
} */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
      vector<int> nums;
      nums.push_back(1);
      nums.push_back(7);
      nums.push_back(3);
      nums.push_back(6);
      nums.push_back(5);
      nums.push_back(6);
      for (int i = 0; i < nums.size(); i++)
      {
            int left = 0;
            if (i != 0)
            {
                  int j = i - 1;
                  while (j >= 0)
                  {
                        left += nums[j];
                        j--;
                  }
            }
            int ryt = 0;
            if (i != nums.size() - 1)
            {
                  int k = i + 1;
                  while (k < nums.size())
                  {
                        ryt += nums[k];
                        k++;
                  }
            }
            if (left == ryt)
            {
                  cout << nums[i - 1];
            }
      }
      return 0;
}