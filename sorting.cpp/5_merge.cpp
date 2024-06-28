#include <iostream>
using namespace std;

void merge(int a[], int l, int mid, int r)
{
      int n1 = mid - l + 1;
      int n2 = r - mid;
      int L[n1], R[n2];

      for (int i = 0; i < n1; i++)
      {
            L[i] = a[l + i];
      }
      for (int j = 0; j < n2; j++)
      {
            R[j] = a[mid + 1 + j];
      }
      int i = 0, j = 0, k = l;
      while (i < n1 && j < n2)
      {
            if (L[i] <= R[j])
            {
                  a[k] = L[i];
                  i++, k++;
            }
            else
            {
                  a[k] = R[j];
                  j++, k++;
            }
      }
      while (i < n1)
      {
            a[k] = L[i];
            i++, k++;
      }
      while (j < n2)
      {
            a[k] = R[j];
            j++, k++;
      }
}
void mergeSort(int a[], int l, int r)
{
      if (l >= r)
            return;
      int mid = l + (r - l) / 2;
      mergeSort(a, l, mid);
      mergeSort(a, mid + 1, r);
      merge(a, l, mid, r);
}
int main()
{
      int a[] = {2, 7, 5, 8, 4, 9, 1};
      mergeSort(a, 0, 6);
      for (int i = 0; i < 7; i++)
      {
            cout << a[i] << " ";
      }
      return 0;
}