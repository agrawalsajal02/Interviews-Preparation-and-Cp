#include<iostream>
//use for input sentnnce of string :-  char s[1005];
   // scanf(" %[^\n]s",s);
//always use '\n' in place of endl
#include<stdio.h>

#include<math.h>
#include<string.h>
#include<stdlib.h>
#define gc getchar
#define ll long long int
#define endl '\n'
ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
inline ll input() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  ll ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
int main()
{
    ll t,i;
    t=input();
    cout<<t;
    return 0;
}
