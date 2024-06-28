#include <iostream>
using namespace std;
class Animal
{
public:
      void AnimalSound()
      {
            cout << "The sound of animals " << endl;
      }
};
class dog : public Animal
{
public:
      void AnimalSound()
      {
            cout << "Dog barks bho bho" << endl;
      }
};
class cow : public Animal
{
public:
      void AnimalSound()
      {
            cout << "cow - meeeee meeee" << endl;
      }
};
int main()
{
      Animal a;
      dog d;
      cow c;
      a.AnimalSound();
      d.AnimalSound();
      c.AnimalSound();
      return 0;
}