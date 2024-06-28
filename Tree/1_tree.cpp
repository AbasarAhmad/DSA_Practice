#include <iostream>
#include <queue>
#include <stack>
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
/* void LevelInOrdertTraversal(node *root)
{
      queue<node *> q;// we create a queue who store node*
      q.push(root);// we put first root node in queue
      while (!q.empty())
      {
            node *temp = q.front(); create a node and store front of queue
            cout << temp->data << " ";
            q.pop(); // now pop the first node of queue;
            if (temp->left)// jab taq temp ka left hai tab  taq
            {
                  q.push(temp->left); // temp ka left queue mai push karte rahai
            }
            if (temp->right)// jab taq temp hai tab taq
            {
                  q.push(temp->right); queue mai temp ka right store karte rahai
            }
      }
} */
void LevelInOrderReverseTraversal(node *root)
{
      queue<node *> q;
      stack<int> st;
      q.push(root);      // first queue mai root insert karai
      q.push(NULL);      // uske baad queue mai ek zero ko bhi insert karai
      while (!q.empty()) // jab taq queue empty na ho jaye
      {
            node *temp = q.front(); // ek temp nam ka node banai  jisko queue ke front mai point karva dai
            q.pop();
            if (temp == NULL) // agar temp ka value zero ho  jaye tab tab
            {
                  cout << endl;
                  if (!q.empty()) // agar queue empty nahi hai tab
                  {
                        q.push(NULL); // queue mai NULL push kar dai
                  }
            }
            else
            {
                  st.push(temp->data);
                  if (temp->left)
                  {
                        q.push(temp->left);
                  }
                  if (temp->right)
                  {
                        q.push(temp->right);
                  }
            }
      }
      while (!st.empty())
      {
            cout << st.top() << " ";
            st.pop();
      }
}

void LevelInOrdertTraversal(node *root)
{
      queue<node *> q;
      q.push(root);
      q.push(NULL);
      while (!q.empty())
      {
            node *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                  cout << endl;
                  if (!q.empty())
                  {
                        q.push(NULL);
                  }
            }
            else
            {
                  cout << temp->data << " ";
                  if (temp->left)
                  {
                        q.push(temp->left);
                  }
                  if (temp->right)
                  {
                        q.push(temp->right);
                  }
            }
      }
}
int main()
{
      // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
      node *root = NULL;
      // creating a Tree;
      root = BuildTree(root);
      LevelInOrdertTraversal(root);
      cout << endl;
      LevelInOrderReverseTraversal(root);
      return 0;
}