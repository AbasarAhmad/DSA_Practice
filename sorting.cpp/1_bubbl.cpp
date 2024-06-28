#include <iostream>
using namespace std;

int main()
{
      int n;
      cout << "Ensert the size of array\n";
      cin >> n;
      cout << "Enter the element of array" << endl;
      int aar[n];
      for (int i = 0; i < n; i++)
      {
            cin >> aar[i];
      }

      // Normal Bubble Sort
      // for (int i = 0; i < n - 1; i++)
      // {
      //       for (int j = 0; j < n - 1 - i; j++)
      //       {
      //             if (aar[j] > aar[j + 1])
      //             {
      //                   int temp = aar[j];
      //                   aar[j] = aar[j + 1];
      //                   aar[j + 1] = temp;
      //             }
      //       }
      // }
      // Adaptive Bubble Sort
      int allreadySort = 0;
      for (int i = 0; i < n - 1; i++)
      {
            cout << "Uses Passes to Sort an array" << i + 1 << endl;
            allreadySort = 1;
            for (int j = 0; j < n - 1 - i; j++)
            {
                  if (aar[j] > aar[j + 1])
                  {
                        int temp = aar[j];
                        aar[j] = aar[j + 1];
                        aar[j + 1] = temp;
                        allreadySort = 0;
                  }
            }
            // if (allreadySort == 1)
            // OR
            if (allreadySort == 1)
            {
                  break;
            }
      }
      for (int i = 0; i < n; i++)
      {
            cout << aar[i] << " ";
      }
      return 0;
}