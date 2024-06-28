#include <iostream>
using namespace std;
void HighestIndexArea(int aar[], int n)
{
      int length = 0;
      for (int i = 0; i < n; i++)
      {
            int curr = aar[i];
            int j = i + 1;
            int totalIndex = 1;
            while (aar[j] >= aar[i] && j < n)
            {
                  totalIndex++;
                  j++;
            }
            int k = i - 1;
            while (aar[k] > aar[i] && k >= 0)
            {
                  totalIndex++;
                  k--;
            }

            if (length < (aar[i] * totalIndex))
            {
                  length = (aar[i] * totalIndex);
            }
            // int length = aar[i] * totalIndex;
      }
      cout << "Biggest Area is : " << length << endl;
}
int main()
{
      int n;
      cout << "Enter the number of element" << endl;
      cin >> n;
      int aar[n];
      cout << "Enter the hights " << endl;
      for (int i = 0; i < n; i++)
      {
            cin >> aar[i];
      }
      cout << endl;
      for (int i = 0; i < n; i++)
      {
            cout << aar[i] << " ";
      }
      HighestIndexArea(aar, n);
      return 0;
}