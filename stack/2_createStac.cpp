#include <iostream>
#include <stack>
using namespace std;
int main()
{
      stack<int> st;
      cout << "is  stack element " << st.empty() << endl;
      st.push(23);
      st.push(12);
      st.push(40);
      st.emplace(344);
      st.pop();
      cout << "Top element is : " << st.top() << endl;
      cout << st.size() << endl;
      return 0;
}