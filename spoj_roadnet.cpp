/*
problem code: ROADNET
problem number: 178
problem link: http://www.spoj.com/problems/ROADNET/
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


ll dist[201][201];


int main()
{
  ll t, n;
  bool neigh;

  getInt(t);

  while (t--)
  {
    getInt(n);
    
    rep(i, n) //distance table input
    {
      rep(j, n)
      {
        getInt(dist[i][j]);
      }
    }

    //consider each pair and check if it is neighbouring
    rep(i, n-1)
    {
      gRep(j, i + 1, n)
      {
        //check if (i, j) are neighbouring towns
        neigh = true;
        rep(k, n)
        {
          if (k == i || k == j)
          {
            continue;
          }

          if (dist[i][k] + dist[k][j] == dist[i][j])
          {
            neigh = false;
            break;
          }
        }
        if (neigh)
        {
          printf("%lld %lld\n", i + 1, j + 1);
        }
      }
    }
  }

  return OfTheKing;
}

