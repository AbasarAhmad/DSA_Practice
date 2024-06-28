#include <iostream>
using namespace std;
void SubString(string s, string ans)
{
      if (s.length() == 0)
      {
            cout << ans << endl;
            return;
      }
      char c = s[0];
      string ros = s.substr(1);
      SubString(ros, ans);
      SubString(ros, ans + c);
}
int main()
{
      SubString("ABC", "");
      return 0;
}