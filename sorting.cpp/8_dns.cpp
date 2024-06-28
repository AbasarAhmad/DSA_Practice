// Dutch National Flag problem thet take input 0,1,abd 2 only

#include <iostream>
using namespace std;
void DNF(int arr[], int n)
{
      int low = 0;
      int mid = 0;
      int high = n - 1;
      while (mid <= high)
      {
            if (arr[mid] == 0)
            {
                  swap(arr[low], arr[mid]);
                  low++, mid++;
            }
            else if (arr[mid] == 1)
            {
                  mid++;
            }
            else if (arr[high] == 2)
            {
                  high--;
            }
            else if (arr[mid] == 2)
            {
                  swap(arr[mid], arr[high]);
                  high--;
            }
      }

      for (int i = 0; i < n; i++)
      {
            cout << arr[i] << " ";
      }
}
int main()
{
      int arr[] = {1, 2, 2, 2, 2, 1, 0, 1, 2, 0, 1};
      int n = sizeof(arr) / sizeof(arr[0]);
      DNF(arr, n);

      return 0;
}