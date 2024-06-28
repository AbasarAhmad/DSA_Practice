// The constructor has the same name as the class, it is always public, and it does not have any return value.followed by parentheses ():

/* #include <iostream>
using namespace std;
class myClass
{
public:
      myClass() // constructors
      {
            cout << "This is constructor" << endl;
      }
};
int main()
{
      myClass abc; // Create an object of MyClass (this will call the constructor)
      return 0;
} */

/* #include <iostream>
using namespace std;
class Hero
{
public:
      Hero()
      {
            cout << " costructor called when we call the class" << endl;
      }
};
int main()
{
      cout << " Staticaly called" << endl;
      Hero hh;
      cout << " Now Dynamically called" << endl;
      Hero *b = new Hero;
      return 0;
} */
/*
#include <iostream>
using namespace std;
class Car
{
public:
      string name;
      int price;
      string color;
      Car(string n, int p, string c)
      { // constructor with paramenter n,p and c
            name = n;
            price = p;
            color = c;
      }
};
int main()
{ // create car objects and call the constructor with different values
      Car obj("BMW", 34352342, "Red");
      Car obj1("Audi", 34376582, "Black   ");
      cout << "car name is " << obj.name << " and price  is " << obj.price << " and color is " << obj.color << endl;
      cout << "car name is " << obj1.name << " and price  is " << obj1.price << " and color is " << obj1.color << endl;
      return 0;
}*/
/*
// constructor can also defined outside the class
#include <iostream>
using namespace std;
class Car
{
public:
      string name;
      int price;
      string color;
      Car(string n, int p, string c);
};
Car::Car(string n, int p, string c)
{ // constructor with paramenter n,p and c
      name = n;
      price = p;
      color = c;
}
int main()
{ // create car objects and call the constructor with different values
      Car obj("BMW", 34352342, "Red");
      Car obj1("Audi", 34376582, "Black   ");
      cout << "car name is " << obj.name << " and price  is " << obj.price << " and color is " << obj.color << endl;
      cout << "car name is " << obj1.name << " and price  is " << obj1.price << " and color is " << obj1.color << endl;
      return 0;
}
 */

// use of " this-> " keyword
#include <iostream>
using namespace std;
class color
{
public:
      string red;
      string black;
      /*here red and black in both in class and passed in constructor so if we dont use of "this -> in constructor to say that left side red is belongs to classs and right side red is passed by the user "*/
      color() // defalt constructor
      {
            cout << " Defalt constructor" << endl;
      }
      color(string red, string black) // parametrized constructor
      {
            this->red = red; // this -> show that first red belongs to class
            (*this).black = black;

            //  this-> == (*this)  BOTH MEANS ARE SAME
      }
      // copy constructor
      color(color &temp)
      {
            cout << "copy constructor called " << endl;
            this->red = temp.red;
            this->black = temp.black;
      }
      void print()
      {
            cout << this->red << " is opposite of red " << endl;
            cout << (*this).black << " is opposite of black " << endl;
      }
};
int main()
{
      // color c;
      // c.red = "Green";
      // c.black = "White";
      // OR
      color c("Green", "White");
      c.print();
      // Copy Constructour
      color d(c);
      d.print();
      return 0;
}