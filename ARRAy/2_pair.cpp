#include <bits/stdc++.h>
using namespace std;

int main()
{
      int arr[] = {10, 16, 7, 14, 5, 3, 12, 9};

      int n = sizeof(arr) / sizeof(arr[0]);
      cout << " Array  : ";
      for (int i = 0; i < n; i++)
      {
            cout << arr[i] << " ";
      }
      vector<pair<int, int>> v;
      for (int i = 0; i < n; i++)
      {
            v.push_back(make_pair(arr[i], i));
      }
      sort(v.begin(), v.end());
      for (int i = 0; i < v.size(); i++)
      {
            arr[v[i].second] = i;
      }
      cout << endl;
      cout << "After Operation  Array  : ";
      for (int i = 0; i < n; i++)
      {
            cout << arr[i] << " ";
      }
      return 0;
}