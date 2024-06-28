// wave for means a>b<c

#include <iostream>
using namespace std;
void DNF(int arr[], int n)
{
      for (int i = 1; i < n; i += 2)
      {
            if (arr[i - 1] < arr[i])
            {
                  swap(arr[i - 1], arr[i]);
            }
            if (i + 1 < n)
            {

                  if (arr[i] > arr[i + 1])
                  {
                        swap(arr[i], arr[i + 1]);
                  }
            }
      }

      for (int i = 0; i < n; i++)
      {
            cout << arr[i] << " ";
      }
}
int main()
{
      int arr[] = {0, 1, 3, 5, 6, 10, 17, 18};
      // OUTPUT=3 1 7 4 6 2 5 // 3>1<7>4<6>2<5
      int n = sizeof(arr) / sizeof(arr[0]);
      DNF(arr, n);

      return 0;
}