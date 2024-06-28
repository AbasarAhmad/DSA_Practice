#include <iostream>
using namespace std;
class myclass
{
private:
      string s;
      int x;

public:
      string z;
      int y;
      // Setter  :- use for set the private data
      void setData(int a)
      {
            x = a;
      }
      // getter:- Use for print the private the data
      void getData()
      {
            cout << x;
      }
      void SetPubluc(string b, int data)
      {
            z = b;
            y = data;
      }
};
int main()
{
      myclass obj;
      obj.setData(20);
      obj.getData();
      cout << endl;
      obj.SetPubluc("Hello Sheikh", 786);
      cout << obj.y << " and " << obj.z << endl;

      return 0;
}