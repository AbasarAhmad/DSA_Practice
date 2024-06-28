#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int main()
{
      char saar[100], aar[100];
      int i, j;
      // // 21 : convert a string  in upper case

      // gets(saar);
      // for (int i = 0; saar[i] != '\0'; i++)
      // {
      //       if (saar[i] >= 'a' && saar[i] <= 'z')
      //       {
      //             saar[i] = saar[i] - 32;
      //       }
      // }
      // cout << saar;

      //******
      // // 23 : convert a string  in upper case

      // gets(saar);
      // int hex = 0;
      // for (int i = 0; saar[i] != '\0'; i++)
      // {
      //       if (saar[i] >= 'A' && saar[i] <= 'F' || saar[i] >= '0' && saar[i] <= '9')
      //       {
      //             hex = 0;
      //       }
      // }
      // if (hex == 0)
      // {
      //       cout << "hexa decimal number";
      // }
      // else
      // {
      //       cout << "Not a hexa decimal";
      // }

      //  24     // to check uppercase or not character
      //       char ch;
      //       cin >> ch;
      //       // if (ch >= 'A' && ch <= 'Z')
      // //               or
      //       if (isupper(ch))
      //       {
      //             cout << " character is upper case";
      //       }
      //       else
      //       {
      //             cout << "character is not uppercase";
      //       }

      //********

      // // 25: replace the spaces of a string with a specific charcater
      // cout << "Enter the string" << endl;
      // gets(saar);
      // char n;
      // cout << " Enter the replace element" << endl;
      // cin >> n;

      // for (int i = 0; saar[i] != '\0'; i++)
      // {
      //       if (saar[i] == ' ')
      //       {
      //             saar[i] = n;
      //       }
      // }
      // cout << saar;

      //       // 26:- count punctuation characters
      //       cout << "Enter the string" << endl;
      //       gets(saar);
      //       int ctr = 0;

      //       for (int i = 0; saar[i] != '\0'; i++)
      //       {
      //             // if (saar[i] == '.' || saar[i] == ';' || saar[i] == ',' || saar[i] == '()')
      // //     OR
      //             if (ispunct(saar[i]))
      //             {
      //                   ctr++;
      //             }
      //       }
      //       cout << "Puntuation latters is " << ctr;

      // // 29:- remove all space
      // cout << "Enter the string" << endl;
      // gets(saar);
      // int ctr = 0;

      // for (int i = 0; saar[i] != '\0'; i++)
      // {
      //       if (saar[i] != ' ')
      //       {
      //             aar[ctr] = saar[i];
      //             ctr++;
      //       }
      // }
      // aar[ctr] = '\0';
      // cout << aar;

      //       // 31:- split string by space
      //       cout << "Enter the string" << endl;
      //       gets(saar);
      //       int ctr = 0;
      //       j = 0;
      //       char ch[30][30];
      //       for (int i = 0; saar[i] != '\0'; i++)
      //       {
      //             if (saar[i] == ' ' || saar[i] == '\0')
      //             {
      //                   ch[ctr][j] = '\0';
      //                   ctr++;
      //                   j = 0;
      //             }
      //             else
      //             {
      //                   ch[ctr][j] = saar[i];
      //                   j++;
      //             }
      //       }

      //       for (int i = 0; i < ctr; i++)
      //       {
      //             cout << ch[i] << endl;
      //       }
      //       cout << ch;

      // // code for most repeated character and time repeate
      // gets(aar);
      // int max = 0, cont;
      // char ch;
      // for (int i = 0; aar[i] != '\0'; i++)
      // {
      //       cont = 0;
      //       for (int j = i; aar[j] != '\0'; j++)
      //       {
      //             if (aar[i] == aar[j])
      //             {
      //                   cont++;
      //             }
      //       }
      //       if (cont > max)
      //       {
      //             max = cont;
      //             ch = aar[i];
      //       }
      // }
      // cout << " Repeated time  " << max << endl;
      // cout << "Repeated character  " << ch << endl;

      //************ 33 program to cont each character
      // cout << "Enter the  string" << endl;
      // gets(saar);
      // int cont;
      // int n = strlen(saar);
      // for (int i = 0; i < n; i++)
      // {
      //       cont = 0;
      //       for (int j = 0; j < n; j++)
      //       {
      //             if (j < i && saar[i] == saar[j])
      //             {
      //                   break;
      //             }
      //             if (saar[i] == saar[j])
      //             {

      //                   cont++;
      //             }
      //       }
      //       if (cont != 0)
      //       {

      //             cout << saar[i] << "==";
      //             cout << cont << endl;
      //       }
      // }

      // // 34 :- Convet vowel into UpperCase
      // cout << "Enter the  string" << endl;
      // gets(saar);
      // int cont;
      // int n = strlen(saar);
      // for (int i = 0; i < n; i++)
      // {
      //       if (saar[i] == 'a' || saar[i] == 'e' || saar[i] == 'i' || saar[i] == 'o' || saar[i] == 'u')
      //       {
      //             saar[i] = saar[i] - 32;
      //       }
      // }
      // cout << saar;

      // //**** 36:- Verify that a string contains valid parentheses
      // stack<char> st;
      // char s[100];
      // cout << "Enter the  string" << endl;
      // gets(s);
      // int n = strlen(s);
      // // cout << n << "   " << saar;
      // for (int i = 0; i < n; i++)
      // {
      //       if (s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == '<')
      //       {
      //             st.push(s[i]);
      //       }
      //       else if ((s[i] == ')'))
      //       {
      //             if (st.top() == '(' && !st.empty())
      //             {
      //                   st.pop();
      //             }
      //             else
      //             {
      //                   break;
      //             }
      //       }
      //       else if ((s[i] == '}'))
      //       {
      //             if (st.top() == '{' && !st.empty())
      //             {
      //                   st.pop();
      //             }
      //             else
      //             {
      //                   break;
      //             }
      //       }
      //       else if ((s[i] == ']'))
      //       {
      //             if (st.top() == '[' && !st.empty())
      //             {
      //                   st.pop();
      //             }
      //             else
      //             {
      //                   break;
      //             }
      //       }
      //       else if ((s[i] == '>'))
      //       {
      //             if (st.top() == '<' && !st.empty())
      //             {
      //                   st.pop();
      //             }
      //             else
      //             {
      //                   break;
      //             }
      //       }
      // }
      // if (st.empty())
      // {
      //       cout << "bracket are correct" << endl;
      // }
      // else
      // {
      //       cout << "not correct" << endl;
      // }

      // //** 37:- Multiply two string value
      // string s;
      // cin >> s;
      // string s2;
      // cin >> s2;
      // // stoi - function use for convert string into integer
      // int a = stoi(s);
      // int b = stoi(s2);
      // int c = a * b;
      // cout << c << endl;
      // // to_string - use to convert int into string
      // string g = to_string(c);
      // cout << g + "3";
      return 0;
}
