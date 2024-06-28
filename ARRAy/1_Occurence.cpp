#include <iostream>
using namespace std;
/*
int fistOccrence(int arr[], int n, int k)
{
      int s = 0;
      int e = n - 1;
      int ans = -1;
      while (s <= e)
      {
            int mid = s + (e - s) / 2;
            if (arr[mid] == k)
            {
                  ans = mid;
                  e = mid - 1;
            }
            else if (k > arr[mid])
            {
                  s = mid + 1;
            }
            else if (k < arr[mid])
            {
                  e = mid - 1;
            }
      }
      return ans;
}
int LastOccrence(int arr[], int n, int k)
{
      int s = 0;
      int e = n - 1;
      int ans = -1;
      while (s <= e)
      {
            int mid = s + (e - s) / 2;
            if (arr[mid] == k)
            {
                  ans = mid;
                  s = mid + 1;
            }
            else if (k > arr[mid])
            {
                  s = mid + 1;
            }
            else if (k < arr[mid])
            {
                  e = mid - 1;
            }
      }
      return ans;
}*/

int firstOccurence(int arr[], int n, int k)
{
      int f = -1;
      for (int i = 0; i < n; i++)
      {

            if (arr[i] == k)
            {
                  f = i;
                  return f;
            }
      }
      return f;
}
int LasttOccurence(int arr[], int n, int k)
{
      int f = -1;
      for (int i = 0; i < n; i++)
      {

            if (arr[i] == k)
            {
                  f = i;
            }
      }
      return f;
}
int main()
{
      int arr[] = {1, 3, 5, 5, 5, 5, 9};
      // int first = fistOccrence(arr, 7, 5);
      // int Last = LastOccrence(arr, 7, 5);
      // cout << "First occurance at index  " << first << endl;
      // cout << "Last occurance at index  " << Last << endl;

      // Through For loop
      cout << "First occurence at index " << firstOccurence(arr, 7, 5);
      cout << "Lastt occurence at index " << LasttOccurence(arr, 7, 5);
      return 0;
}