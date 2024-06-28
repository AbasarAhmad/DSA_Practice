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
      int code = c;
      string ros = s.substr(1);
      SubString(ros, ans);
      SubString(ros, ans + c);
      SubString(ros, ans + c + to_string(code));
}
int main()
{
      SubString("AB", "");
      return 0;
}