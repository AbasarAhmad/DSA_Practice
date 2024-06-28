// INPUT :- {-8,2,3,-6,10}    => OUTPUT :- -8,0,-6,-6
//  find negative value in all 2 pairs otherwise put 0
//  {-8,2} =  -8 ,    {2,3} = 0   , {3,-6}= -6  , {-6,10} = -6

#include <iostream>
#include <vector>
#include <deque>
using namespace std;
vector<int> FindNegativeInK_Pattern(int vt[], int N, int K)
{
}
int main()
{
      int n;
      cout << "Enter the number of value" << endl;
      cin >> n;
      int a[n];
      for (int i = 0; i < n; i++)
      {
            cin >> a[i];
      }
      int k = 2;
      vector<int> bt;
      FindNegativeInK_Pattern(a[], n, k);
      return 0;
}