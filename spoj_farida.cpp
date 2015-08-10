/*
  problem code: FARIDA
  problem link: http://www.spoj.com/problems/FARIDA/
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
//#define p_u(x) putchar_unlocked(x) //if windows use putchar()
#define p_u(x) putchar(x) 
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

int comparator(const void *p, const void *q)
{
  return *((int *)p) - *((int *)q);
}

ll dp[10001];
ll inp[10001];

int main()
{
  ll t, n, temp;

  getInt(t);

  rep(k, t)
  {
    getInt(n);

    if (n == 0)
    {
      printf("Case %lld: 0\n", k + 1);
      continue;
    }

    rep(i, n)
    {
      getInt(temp);

      inp[i] = temp;
    }

    dp[0] = inp[0];
    dp[1] = max(dp[0], inp[1]);

    gRep(i, 2, n)
    {
      dp[i] = max(dp[i - 1], dp[i - 2] + inp[i]);
    }

    printf("Case %lld: %lld\n", k + 1, dp[n - 1]);
  }

  return OfTheKing;
}


