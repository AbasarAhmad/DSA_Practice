/* #include <iostream>
using namespace std;
// void inc(int &n)
// {
//       n++;
// }
int getSum(int *arr, int n)
{
      int sum = 0;
      for (int i = 0; i < n; i++)
      {
            sum += arr[i];
      }
      return sum;
}
void change(int &n)
{
      n++;
}
int main()
{
      int i = 7;
      // int &j = i;
      // cout << i << endl;
      // i++;
      // cout << j << endl;
      // j++;
      // cout << i << endl;
      // cout << " Before fuction " << i << endl;
      // inc(i);
      // cout << " after fuction " << i << endl;
      int n;
      cin >> n;
      int *arr = new int[n];
      for (int i = 0; i < n; i++)
      {
            cin >> arr[i];
      }
      int ans = getSum(arr, n);
      cout << ans << endl;
      return 0;
} */

// Creating 2-D Array Dynamic Memory
#include <iostream>
using namespace std;

int main()
{
      // int n;
      // cin >> n;

      // // 2-D Array has been created
      // int **arr = new int *[n];
      // for (int i = 0; i < n; i++)
      // {
      //       arr[i] = new int[n];
      // }
      int row, col;
      cin >> row >> col;
      int **arr = new int *[row];
      for (int i = 0; i < row; i++)
      {
            arr[i] = new int[col];
      }
      // Taking INput in Array
      for (int i = 0; i < row; i++)
      {
            for (int j = 0; j < col; j++)
            {
                  cin >> arr[i][j];
            }
      }
      // Print the Array
      for (int i = 0; i < row; i++)
      {
            for (int j = 0; j < col; j++)
            {
                  cout << arr[i][j] << " ";
            }
            cout << endl;
      }
      // releasing memory
      for (int i = 0; i < row; i++)
      {
            delete[] arr[i];
      }
      delete[] arr;

      return 0;
}