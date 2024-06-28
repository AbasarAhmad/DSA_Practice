#include <iostream>
using namespace std;
void countSort(int arr[], int n)
{
      int maxi = arr[0];
      for (int i = 1; i < n; i++)
      {
            if (maxi < arr[i])
            {
                  maxi = arr[i];
            }
      }
      int brr[maxi + 1] = {0};

      for (int i = 0; i <= n; i++)
      {
            brr[arr[i]]++;
      }
      for (int i = 1; i <= n; i++)
      {
            brr[i] = brr[i - 1] + brr[i];
      }
      int ans[n] = {0};
      for (int i = n - 1; i >= 0; i--)
      {
            ans[--brr[arr[i]]] = arr[i];

            // OR WE CAN WRITE BELOW TWO LINE
            // int a = --brr[arr[i]];
            // ans[a] = arr[i];
      }
      for (int i = 0; i < n; i++)
      {
            arr[i] = ans[i];
      }
      for (int i = 0; i < n; i++)
      {
            cout << arr[i] << " ";
      }
}
int main()
{
      // int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};
      int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 5, 7, 10, 10, 10, 3};
      int n = sizeof(arr) / sizeof(arr[0]);
      countSort(arr, n);
      return 0;
}