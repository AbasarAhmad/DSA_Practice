// Iput= [2,1,4,3]
// Output={ 1,-1,3,-1}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void print(vector<int> vt)
{
      for (int i = 0; i < vt.size(); i++)
      {
            cout << vt[i] << " ";
      }
}
vector<int> PushNextSmallerElement(vector<int> &vt, int n)
{
      stack<int> st;
      st.push(-1);
      vector<int> ans(n);
      // agar left sift karna hai to for loop 0 se start hoke n-1 taq jayegi
      for (int i = n - 1; i >= 0; i--)
      {
            int curr = vt[i];
            // jab tak stack ka top ka element current element se jada hai tab taq stack to pop karai

            while (st.top() >= curr)
            {
                  st.pop();
            }
            // ans is the top of stack
            ans[i] = st.top();
            st.push(curr);
      }
      return ans;
}
int main()
{
      vector<int> vt;
      vector<int> bt;
      vt.push_back(2);
      vt.push_back(1);
      vt.push_back(4);
      vt.push_back(3);
      print(vt);
      cout << endl;
      bt = PushNextSmallerElement(vt, vt.size());
      // print(vt);
      print(bt);
      return 0;
}