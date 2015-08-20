/*
problem code: NICEDAY
problem number:
problem link: http://www.spoj.com/problems/NICEDAY/
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

struct ranks
{
  ll a, b, c;
};

bool compare(const ranks &a, const ranks &b)
{
  return a.a < b.a;
}

ll readTree(ll);
void update(ll, ll, ll);

ll bitTree[100002];


int main()
{
  ll t, n, temp;

  getInt(t);

  while (t--)
  {
    getInt(n);

    ranks *r = (struct ranks *)malloc(n*sizeof(ranks));

    rep(i, n)
    {
      getInt(temp);
      r[i].a = temp;
      getInt(temp);
      r[i].b = temp;
      getInt(temp);
      r[i].c = temp;
    }

    sort(r, r + n, compare);

    fill(bitTree, bitTree + n + 2, LLONG_MAX);

    ll excellent = 0;

    rep(i, n)
    {
      ll current = readTree(r[i].b);

      if (current > r[i].c)
      {
        excellent++;
      }

      update(r[i].b, r[i].c, n);
    }

    printf("%lld\n", excellent);
  }


  return OfTheKing;
}


ll readTree(ll idx)
{
  ll pMin = LLONG_MAX;

  while (idx)
  {
    pMin = min(bitTree[idx], pMin);
    idx -= (idx & -idx);
  }

  return pMin;
}


void update(ll idx, ll val, ll n)
{
  while (idx <= n)
  {
    bitTree[idx] = min(val, bitTree[idx]);
    idx += (idx & -idx);
  }
}





