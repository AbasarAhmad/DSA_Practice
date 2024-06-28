#include <iostream>
using namespace std;
void merge(int *aar, int low, int high)
{
      int mid = (low + high) / 2;
      int len1 = mid - low + 1;
      int len2 = high - mid;
      int *first = new int[len1];
      int *second = new int[len2];
      // copy values
      int mainArrayIndex = low;
      for (int i = 0; i < len1; i++)
      {
            first[i] = aar[mainArrayIndex++];
      }
      int k = mid + 1;
      for (int i = 0; i < len2; i++)
      {
            second[i] = aar[mainArrayIndex++];
      }
}
void MergeSort(int *aar, int start, int end)
{
      if (start > end)
      {
            return;
      }
      int mid = (start + end) / 2;
      // left part sort karna hai
      MergeSort(aar, start, mid);
      // right part sort karna hai
      MergeSort(aar, mid + 1, end);
      // Now marge
      merge(aar, start, end);
}
int main()
{
      int aar[] = {5, 2, 9, 4, 8, 1, 7};
      int size = 7 - 1;
      MergeSort(aar, 0, size);
      return 0;
}