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

      for (int i = 0; i < n - 1; i++)
      {
            for (int j = i + 1; j < n; j++)
            {
                  if (aar[i] > aar[j])
                  {
                        int temp = aar[i];
                        aar[i] = aar[j];
                        aar[j] = temp;
                  }
            }
      }

      for (int i = 0; i < n; i++)
      {
            cout << aar[i] << " ";
      }

      return 0;
}