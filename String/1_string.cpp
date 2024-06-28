#include <iostream>
#include <string.h>
using namespace std;

int main()
{
      char aar[200], saar[200];

      // 3 separate the individual charcters from string

      // gets(aar);
      // int n = strlen(aar);
      // for (int i = 0; i < n; i++)
      // {
      //       cout << aar[i] << " ";
      // }

      // // 4 reverse a string;
      // cout << "Enter  the string" << endl;
      // ;
      // fgets(aar, sizeof aar, stdin);
      // for (int i = strlen(aar); i >= 0; i--)
      // {
      //       cout << aar[i];
      // }

      // 5:-  Total number of words in string
      // cout << "Enter  the string" << endl;
      // fgets(aar, sizeof aar, stdin);
      // int cont = 0;
      // for (int i = 0; aar[i] != '\0'; i++)
      // {
      //       if (aar[i] == ' ' || aar[i] == '\n')
      //       {
      //             cont++;
      //       }
      // }
      // cout << "Total words is:  " << cont;

      // // 6:- Compare two string
      // cout << "Enter  the string" << endl;
      // gets(aar);
      // cout << "Enter the second string" << endl;
      // gets(saar);
      // int n1 = strlen(aar);
      // int n2 = strlen(saar);
      // cout << n1 << "  " << n2 << endl;
      // if (n1 == n2)
      // {
      //       int find = 0;
      //       int i = 0;
      //       while (aar[i] != '\0')
      //       {
      //             if (aar[i] != saar[i])
      //             {
      //                   find = 1;
      //                   break;
      //             }
      //             i++;
      //       }
      //       if (find == 0)
      //       {
      //             cout << "string are same";
      //       }
      //       else
      //       {
      //             cout << "string are different";
      //       }
      // }
      // if (n1 != n2)
      // {
      //       cout << "String are different\n";
      // }

      // //7:-  count total alphabet , digit and special character;
      //   fgets(aar, sizeof aar, stdin);
      //  int alp = 0, dig = 0, sp = 0;
      //  for (int i = 0; i < strlen(aar); i++)
      //  {
      //        if (aar[i] >= 'a' && aar[i] <= 'z' || aar[i] >= 'A' && aar[i] <= 'Z')
      //        {
      //              alp++;
      //        }
      //        else if (aar[i] >= '0' && aar[i] <= '9')
      //        {
      //              dig++;
      //        }
      //        else
      //        {
      //              sp++;
      //        }
      //  }
      //  cout << "Alpabet: " << alp << endl;
      //  cout << "Digit : " << dig << endl;
      //  cout << "Special : " << sp;

      // // count vowels and constants in string
      // fgets(aar, sizeof aar, stdin);
      // int vowel = 0, i;
      // int cons = 0;
      // int len = strlen(aar);

      // for (i = 0; i < len; i++)
      // {

      //       if (aar[i] == 'a' || aar[i] == 'e' || aar[i] == 'i' || aar[i] == 'o' || aar[i] == 'u' || aar[i] == 'A' || aar[i] == 'E' || aar[i] == 'I' || aar[i] == 'O' || aar[i] == 'U')
      //       {
      //             vowel++;
      //       }
      //       else if ((aar[i] >= 'a' && aar[i] <= 'z') || (aar[i] >= 'A' && aar[i] <= 'Z'))
      //       {
      //             cons++;
      //       }
      // }
      // cout << "Vowels: " << vowel << endl;
      // cout << "Constant: " << cons << endl;

      // // maximum occuring character
      // fgets(aar, sizeof aar, stdin);
      // int max = 0, i, j;
      // char element;
      // for (i = 0; i < strlen(aar); i++)
      // {
      //       int temp = 0;
      //       for (j = 0; j < strlen(aar); j++)
      //       {
      //             if (aar[i] == aar[j])
      //             {
      //                   temp++;
      //             }
      //       }
      //       if (max < temp)
      //       {
      //             max = temp;
      //             element = aar[i];
      //       }
      // }
      // cout << "The character is " << max << endl;
      // cout << "The position is " << element << endl;

      // // sort array in accending order
      // fgets(aar, sizeof aar, stdin);

      // char element;
      // for (int i = 1; i < strlen(aar); i++)
      // {
      //       for (int j = 0; j < strlen(aar) - i; j++)
      //       {

      //             if (aar[j] > aar[j + 1])
      //             {
      //                   char temp = aar[j];
      //                   aar[j] = aar[j + 1];
      //                   aar[j + 1] = temp;
      //             }
      //       }
      // }
      // cout << aar;

      // // 13:- extract a substring from a given string
      // fgets(aar, sizeof aar, stdin);
      // int n;
      // cout << "Enter the length" << endl;
      // cin >> n;
      // int pos;
      // cout << "Enter the position where you want string" << endl;
      // cin >> pos;
      // int c = 0;
      // while (c < n)
      // {
      //       saar[c] = aar[pos + c - 1];
      //       c++;
      // }
      // saar[c] = '\0';
      // for (int i = 0; saar[i] != '\0'; i++)
      // {
      //       cout << saar[i];
      // }

      // //14 :- whether a given substring is present in the string
      // cout << "Enter the main string" << endl;
      // gets(aar);
      // cout << "Enter the sunstring" << endl;
      // gets(saar);
      // int l = strlen(saar);
      // int i, j;
      // for (i = 0; aar[i] != '\0'; i++)
      // {
      //       for (j = 0; saar[j] != '\0'; j++)
      //       {
      //             if (aar[i + j] != saar[j])
      //             {
      //                   break;
      //             }
      //       }
      //       if (j == l)
      //       {
      //             cout << " found in " << i + 1 << " position" << endl;
      //       }
      // }
      // cout << "substring not found";

      // // 15:- replace lowercase character by uppercase character
      // gets(aar);
      // int i = 0;
      // while (aar[i] != '\0')
      // {
      //       if (aar[i] >= 65 && aar[i] <= 90)
      //       {
      //             aar[i] = aar[i] + 32;
      //       }
      //       else if (aar[i] >= 97 && aar[i] <= 122)
      //       {
      //             aar[i] = aar[i] - 32;
      //       }
      //       i++;
      // }
      // cout << aar;

      // // 16 :- find the number of 'the' in a string
      // cout << "Main String" << endl;
      // gets(aar);
      // cout << " Enter for search" << endl;
      // gets(saar);
      // int L = strlen(saar);
      // int i = 0, j;
      // int cont = 0;
      // while (aar[i] != '0')
      // {
      //       for (j = 0; saar[j] != '\0'; j++)
      //       {
      //             if (aar[i + j] != saar[j])
      //             {
      //                   break;
      //             }
      //       }
      //       if (j == L)
      //       {
      //             cont++;
      //       }
      //       i++;
      // }
      // if (cont == 0)
      // {
      //       cout << "Element not found" << endl;
      // }
      // else
      // {
      //       cout << cont << " times element found";
      // }

      // // 17 :- remove characters from string
      // gets(aar);
      // int i;
      // int k = 0;
      // for (i = 0; aar[i] != '\0'; i++)
      // {
      //       if (aar[i] >= 'a' && aar[i] <= 'z' || aar[i] >= 'A' && aar[i] <= 'Z')
      //       {
      //             saar[k] = aar[i];
      //             k++;
      //       }
      // }
      // saar[k] = '\0';
      // cout << aar << endl;
      // cout << saar << endl;

      // // 18:-  frequency of any character
      // cout << "Enter the string" << endl;
      // gets(saar);
      // char ch;
      // cout << "enter the character to search" << endl;
      // cin >> ch;
      // int max = 0;
      // int i, j;
      // for (i = 0; saar[i] != '\0'; i++)
      // {
      //       if (saar[i] == ch)
      //       {
      //             max++;
      //       }
      // }
      // cout << "The frequency of '" << ch << "'  is  " << max;
