/*
  problem code: POLEVAL
  problem number: 1744
  problem link: http://www.spoj.com/problems/POLEVAL/
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


ll coeffs[1000];


int main()
{
  /*
    simple, adhoc
  */
  ll n, k, x, t=1, ans, y;

  while (1)
  {
    getInt(n);

    if (n == -1)
    {
      break;
    }

    for (int i = n; i >= 0; --i)
    {
      getInt(coeffs[i]);
    }

    printf("Case %lld:\n", t);

    getInt(k);

    rep(i, k)
    {
      y = 1;
      getInt(x);
      ans = coeffs[0];
      gRep(j, 1, n + 1)
      {
        y *= x;
        ans += (y*coeffs[j]);
      }

      printf("%lld\n", ans);
    }
    t++;
  }

  return OfTheKing;
}


