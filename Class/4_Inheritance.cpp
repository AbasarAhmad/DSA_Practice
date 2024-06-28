/*public(members of a class are accessible from
outside the class) and
private(members can only be accessed within the class).The third specifier,
protected, is similar to private,but it can also be accessed in the inherited class :*/

/* // Inheritance
#include <iostream>
using namespace std;
class vahical
{
public:
      string brand = "Ford";
      void honk()
      {
            cout << "Tutu tutu! \n";
      }
};
class car : public vahical
{
public:
      string model = "GiGi Hadid ";
};
int main()
{
      car c;
      cout << c.brand << endl;
      c.honk();
      cout << endl
           << c.model;
      return 0;
} */

/* // Multilevel Inheritance
// Base class (parent)
#include <iostream>
using namespace std;
class MyClass
{
public:
      void myFunction()
      {
            cout << "Some content in parent class.";
      }
};

// Derived class (child)
class MyChild : public MyClass
{
};

// Derived class (grandchild)
class MyGrandChild : public MyChild
{
};

int main()
{
      MyGrandChild myObj;
      myObj.myFunction();
      return 0;
} */

/* // Multiple Inheritance
#include <iostream>
using namespace std;
class A1
{
public:
      void print()
      {
            cout << "Hello Sheikh  ";
      }
};
class B1
{
public:
      void show()
      {
            cout << "How are you ! ";
      }
};
class CA : public A1, public B1
{
      // cout << " And whats going  on ";
};
int main()
{
      CA obj;
      obj.print();
      obj.show();

      return 0;
} */

// protected method
#include <iostream>
using namespace std;
class A1
{
protected:
      int item;

public:
      void print()
      {
            cout << "Hello Sheikh  ";
      }
};
class B1 : public A1
{
public:
      int bonus;
      void setSalary(int s)
      {
            item = s;
            cout << item << endl;
            ;
      }
      void getSalary()
      {
            cout << item;
      }
};

int main()
{
      B1 obj;
      obj.setSalary(999);
      obj.getSalary();
      return 0;
}