#include <iostream>
using namespace std;
class Circularque
{
      int *arr;
      int front;
      int back;
      int size;

public:
      // INitialize data stricture
      Circularque(int n)
      {
            size = n;
            arr = new int(size);
            front = back = -1;
      }
      bool Enqueue(int value)
      {
            // To check Whther queue is full
            if ((front == 0 && back == size - 1) || back == (front - 1) % (size - 1))
            {
                  cout << "Queue is full";
                  return false;
            }
            else if (front == -1) // first element to push
            {
                  front = back = 0;
                  arr[back] = value;
            }
            else if (back == size - 1 && front != 0)
            {
                  back = 0; // to maintain cyclic nature
                  arr[back] = value;
            }
            else
            {
                  back++;
                  arr[back] = value;
            }
            return true;
      }
      int Dequeue()
      {
            if (front == -1) // To check Queue is Empty
            {
                  cout << "Queue is Empty " << endl;
                  return -1;
            }
            int ans = arr[front];
            cout << " Dequeue element is " << ans << endl;
            arr[front] = -1;
            if (front == back)
            { // Single element is present
                  front = back = -1;
            }
            else if (front == size - 1)
            {
                  front = 0; // To maintain Cyclic Nature
            }
            else
            {
                  front++;
            }
            return ans;
      }
};
int main()
{
      Circularque cq(34);
      cq.Enqueue(23);
      cq.Enqueue(3);
      cq.Enqueue(20);
      cq.Dequeue();
      cq.Dequeue();

      return 0;
}