// print number through recursion
// #include <iostream>
// using namespace std;
// int cont(int n, int m)
// {
//       if (n >= m + 1)
//       {
//             return m;
//       }
//       cout << n << " ";
//       cont(n + 1, m);
// }
// int main()
// {
//       int n, m;
//       cout << "Enter the number lower and upper number " << endl;
//       cin >> n >> m;
//       cont(n, m);
//       return 0;
// }

// calculate the number through recursion
// #include <iostream>
// using namespace std;
// int Add(int n)
// {
//       if (n <= 0)
//       {
//             return 0;
//       }
//       return n + Add(n - 1);
// }
// int main()
// {
//       int n;
//       cout << " Enter the number is " << endl;
//       cin >> n;
//       cout << " addition of number is " << Add(n);
//       return 0;
// }

// // print fabonacci series through recursion
// #include <iostream>
// using namespace std;
// int printAar(int arr[], int n)
// {
//       if (n == 0)
//       {
//             return 0;
//       }
//       printAar(arr, n - 1);
//       cout << "Element of " << n << " is " << arr[n - 1] << endl;
// }
// int main()
// {
//       int n;
//       cout << " Enter the number is " << endl;
//       cin >> n;
//       int aar[n];
//       for (int i = 0; i < n; i++)
//       {
//             cin >> aar[i];
//       }
//       printAar(aar, n);
//       return 0;
// }

// // cont digit  through recursion
// #include <iostream>
// using namespace std;

// int printAar(int n)
// {
//       static int ctr = 0;
//       if (n != 0)
//       {
//             ctr++;
//             printAar(n / 10);
//       }
//       return ctr;
// }
// int main()
// {
//       int n;
//       cout << " Enter the number is " << endl;
//       cin >> n;
//       cout << printAar(n);
//       return 0;
// }

// // sum of digit  through recursion
// #include <iostream>
// using namespace std;

// int printAar(int n)
// {
//       static int sum = 0;
//       if (n != 0)
//       {
//             sum += n % 10;
//             printAar(n / 10);
//       }
//       return sum;
// }
// int main()
// {
//       int n;
//       cout << " Enter the number is " << endl;
//       cin >> n;
//       cout << printAar(n);
//       return 0;
// }

// // largest element of array  through recursion
// #include <iostream>
// using namespace std;

// int LargeAar(int aar[], int n)
// {
//       static int sum = 0;
//       if (n == 0)
//       {
//             return 0;
//       }
//       if (sum < aar[n - 1])
//       {
//             sum = aar[n - 1];
//       }
//       LargeAar(aar, n - 1);
//       return sum;
// }
// int main()
// {
//       int n;
//       cout << " Enter the number is " << endl;
//       cin >> n;
//       int aar[n];
//       for (int i = 0; i < n; i++)
//       {
//             cin >> aar[i];
//       }
//       cout << "Largest element is " << LargeAar(aar, n);
//       return 0;
// }

// // Reverse a string throgh recursion
// #include <iostream>
// using namespace std;
// void Rev(string s, int l)
// {
//       if (l != 0)
//       {
//             cout << s[l - 1];
//             Rev(s, l - 1);
//       }
// }
// int main()
// {
//       string s;
//       cin >> s;
//       int l = s.length();
//       Rev(s, l);
//       return 0;
// }

// // decimal to binary
// #include <iostream>
// using namespace std;
// int DecimalToBinary(int n)
// {
//       static int sum,factor = 1;
//       if (n != 0)
//       {
//             sum = sum + n % 2 * factor;
//             factor = factor * 10;
//             DecimalToBinary(n / 2);
//       }
//       return sum;
// }
// int main()
// {
//       cout << "Enter the number" << endl;
//       int n;
//       cin >> n;
//       cout << DecimalToBinary(n);
//       return 0;
//}

// // prime of not
// #include <iostream>
// using namespace std;
// int DecimalToBinary(int n, int i)
// {
//       if (i == 1)
//       {
//             return 1;
//       }
//       if (n % i == 0)
//       {
//             return 0;
//       }
//       DecimalToBinary(n, i - 1);
// }
// int main()
// {
//       cout << "Enter the number" << endl;
//       int n;
//       cin >> n;
//       int p = DecimalToBinary(n, n / 2);
//       if (p == 1)
//       {
//             cout << n << " prime number" << endl;
//       }
//       else
//       {
//             cout << "Not prime number" << endl;
//       }
//       return 0;
// }

// // LCM of two numbers using recursion
// #include <iostream>
// using namespace std;
// int findLCM(int n, int b)
// {
//       static int m = 0;
//       m = m + b;
//       if (m % n == 0 && m % b == 0)
//       {
//             return m;
//       }

//       findLCM(n, b);
// }
// int main()
// {
//       cout << "Enter the number" << endl;
//       int n;
//       cin >> n;
//       cout << "Enter the second number" << endl;
//       int m;
//       cin >> m;
//       cout << findLCM(n, m);
//       return 0;
// }

#include <iostream>
using namespace std;

int main()
{
      int n;
      for (int i = 0; i < n; i++)
      {
      }
      return 0;
}
