/* #include <iostream>
using namespace std;
class myclass // The class
{
public:         // Access specifier
      int data; // Attribute(int variable)
      string s; // Attribute (string)
};
int main()
{
      myclass ab; //  create an object of myclass
      // Access attribute and set values
      ab.data = 333;
      ab.s = "Sheikh Riyaz";
      // print Attribute
      cout << ab.data << " and " << ab.s << endl;
      myclass shy;
      shy.s = " Shy is second object";
      shy.data = 9000;
      cout << shy.data << " and " << shy.s;

      return 0;
} */

// There are two ways to define functions that belongs to a class :

//     1) :-Inside class definition
//     2) :- Outside class definition
#include <iostream>
using namespace std;
class myclass
{
public:
      int data;
      string s;
      // Method/function defined inside the class
      void myMethod()
      {
            data = 54;
            s = "Sheikh";
            cout << " thhis is Inside class definition ";
            cout << " Because its written inside the class" << endl;
            cout << s << "  and " << data << endl;
      }
      // to create outside class you have to declare it inside the class
      void OutsideClass(int money);
};
void myclass::OutsideClass(int money)
{
      cout << " this out side class allready declare in class " << endl;
      data = 555;
      s = "How are you";
      cout << s << "  and " << data << " ans money is " << money << endl;
}
int main()
{
      myclass obj;
      obj.myMethod();
      cout << endl;
      obj.OutsideClass(99);

      return 0;
}
