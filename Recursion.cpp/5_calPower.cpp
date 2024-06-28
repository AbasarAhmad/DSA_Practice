#include <iostream>
using namespace std;
int calculatePwer(int a, int b)
{
      // Base case
      if (b == 0)
      {
            return 1;
      }
      // Base case
      if (b == 1)
      {
            return a;
      }
      int ans = calculatePwer(a, b / 2);
      if (b % 2 == 0)
      {
            return ans * ans;
      }
      else
      {
            return a * ans * ans;
      }
}
int main()
{
      int a, b;
      cin >> a >> b;
      int ans = calculatePwer(a, b);
      cout << ans;
      return 0;
}