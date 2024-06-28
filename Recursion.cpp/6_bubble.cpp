#include <iostream>
using namespace std;
void sortArrayWithBubbble(int *aar, int size)
{
      // base case
      if (size == 0 || size == 1)
      {
            return;
      }
      // 1 case solve karai= largest element ko end me rakhai
      for (int i = 0; i < size - 1; i++)
      {
            if (aar[i] > aar[i + 1])
            {
                  swap(aar[i], aar[i + 1]);
            }
      }
      sortArrayWithBubbble(aar, size - 1);
}
int main()
{
      int aar[] = {3, 2, 6, 1, 9, 4};
      int size = 6;
      sortArrayWithBubbble(aar, size);
      for (int i = 0; i < 6; i++)
      {
            cout << aar[i] << " ";
      }
      return 0;
}