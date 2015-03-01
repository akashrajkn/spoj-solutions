/*
problem code: TSHOW1
problem number: 11354
problem link: http://www.spoj.com/problems/TSHOW1/
*/

#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<iterator>
#include<set>
#include<map>
#include<iostream>
#include<sstream>
#include<deque>
#include<cmath>
#include<memory.h>
#include<algorithm>
#include<utility>
#include<climits>
#include<list>
#include<bitset>
#include<fstream>

using namespace std;

#define OfTheKing 0
#define rep(i,n) for(long long i=0; i<n; ++i)
#define gRep(i,p,n) for(long long i=p; i<n; ++i)
#define MP make_pair
#define all(c) c.begin(),c.end()
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define PB push_back
#define PF push_front
//#define g_u getchar_unlocked() //if windows use getchar()
#define g_u getchar()

typedef pair<long long, long long> pii;
typedef long long ll;


//fast input function
inline void getInt(ll &n)
{
  n = 0;
  ll ch = g_u;
  ll sign = 1;
  while (ch < '0' || ch > '9')
  {
    if (ch == '-')
    {
      sign = -1;
    }
    ch = g_u;
  }
  while (ch >= '0' && ch <= '9')
  {
    n = (n << 3) + (n << 1) + ch - '0';
    ch = g_u;
  }
  n *= sign;
}


int max(int a, int b)
{
  return a>b ? a : b;
}


int main()
{
  /*
    BFS, adhoc
  */

  ll t, k;

  getInt(t);

  while (t--)
  {
    getInt(k);

    vector<char> ans;

    while (k > 0)
    {
      if (k & 1) //k is odd
      {
        ans.PB('5');
      }
      else //k is even
      {
        ans.PB('6');
      }
      k = (k - 1) / 2; // the kth number is obtained by appending '5' or '6' to ((k-1)/2)th number
    }

    ll len = ans.size();

    rep(i, len)
    {
      printf("%c", ans[len - i - 1]);
    }
    printf("\n");
  }

  return OfTheKing;
}


