// #include <iostream>
// using namespace std;
// void printdigit(int n, string aar[])
// {
//       if (n == 0)
//       {
//             return;
//       }
//       int digit = n % 10;
//       n = n / 10;
//       printdigit(n, aar);
//       cout << aar[digit] << "  ";
// }
// int main()
// {
//       string aar[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
//       int n;
//       cin >> n;
//       printdigit(n, aar);
//       return 0;
// }

// // Check for sorted Araay using recursion
// #include <iostream>
// using namespace std;
// bool isSorted(int *aar, int n) // or int aar[]
// {
//       if (n == 0 || n == 1)
//       {
//             return true;
//       }
//       if (aar[0] > aar[1])
//       {
//             return false;
//       }
//       else
//       {
//             bool remainingPart = isSorted(aar + 1, n - 1);
//             return remainingPart;
//       }
// }
// int main()
// {
//       int aar[] = {1, 3, 4, 8, 9};
//       bool ans = isSorted(aar, 5);
//       if (ans)
//       {
//             cout << "Array is sorted";
//       }
//       else
//       {
//             cout << "Array is unsorted";
//       }
//       return 0;
// }

// searching a key from array using recursion
#include <iostream>
using namespace std;
// bool isfind(int *aar, int i, int size, int key)
// {
//       if (i == size)
//       {
//             return 0;
//       }
//       if (aar[i] == key)
//       {
//             return true;
//       }
//       isfind(aar, i + 1, size, key);
// }
//        OR
// bool isfind(int *aar, int size, int key)
// {
//       if (size == 0)
//       {
//             return false;
//       }
//       if (aar[0] == key)
//       {
//             return true;
//       }
//       else
//       {
//             bool remainPart = isfind(aar + 1, size - 1, key);
//             return remainPart;
//       }
// }
// int main()
// {
//       int aar[] = {1, 3, 4, 8, 9};
//       // bool ans = isfind(aar, 0, 5, 22);
//       //     OR
//       bool ans = isfind(aar, 5, 3);
//       if (ans)
//       {
//             cout << "Element is find";
//       }
//       else
//       {
//             cout << "Element is not find";
//       }
//       return 0;
// }

// searching a key from array using Binary recursion recursion
#include <iostream>
using namespace std;
void print(int *aar, int start, int end)
{
      for (int i = start; i < end; i++)
      {
            cout << aar[i] << " ";
      }
      cout << endl;
}
bool binarySearch(int *aar, int start, int end, int key)
{
      // print(aar, start, end);
      if (start > end)
      {
            return false;
      }
      int mid = (start + end) / 2;
      cout << aar[mid] << endl;
      if (aar[mid] == key)
      {
            return true;
      }
      if (aar[mid] < key)
      {
            return binarySearch(aar, mid + 1, end, key);
      }
      else
      {
            return binarySearch(aar, start, mid - 1, key);
      }
}
int main()
{
      int aar[] = {1, 3, 4, 8, 9, 10, 11};
      // bool ans = isfind(aar, 0, 5, 22);
      //     OR
      bool ans = binarySearch(aar, 0, 7, 11);
      if (ans)
      {
            cout << "Element is find";
      }
      else
      {
            cout << "Element is not find";
      }
      return 0;
}