#include <iostream>

using namespace std;
void Quick(int Arr[], int i, int j)
{
    int piot = Arr[i];
    int lb = i, ub = j;
    if (i < j)
    {

        while (i < j)
        {
            while (Arr[i] <= piot)
            {
                i++;
            }
            while (Arr[j] > piot)
            {
                j--;
            }
            if (i < j)
            {
                int temp = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = temp;
            }
        }
        int temp = Arr[lb];
        Arr[lb] = Arr[j];
        Arr[j] = temp;
        Quick(Arr, lb, j - 1);
        Quick(Arr, j + 1, ub);
    }
}
int main()
{
    int Arr[7] = {5, 8, 3, 4, 2, 4, 7};
    Quick(Arr, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        cout << Arr[i] << " ";
    }

    return 0;
}

/* #include <iostream>
using namespace std;
void quickSort(int aar[],int low,int high){

}
int main()
{
      int n;
      cin >> n;
      int aar[n];
      for (int i = 0; i < n; i++)
      {
            cin >> aar[i];
      }
      quickSort(aar, 0, n);
      for (int i = 0; i < n; i++)
      {
            cout << aar[i] << " ";
      }
      return 0;
} */