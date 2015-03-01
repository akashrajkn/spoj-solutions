/*
  problem code: MSCHED
  problem number: 18965
  problem link: http://www.spoj.com/problems/MSCHED/
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


vector < pii > milk;
int dl[10001];


int main()
{
  /*
    greedy approach, select the maximum gallons producing cow each time
  */
  ll n, gallon, deadline, ans, current;

  ans = 0;
  getInt(n);

  rep(i, n)
  {
    getInt(gallon);
    getInt(deadline);

    milk.PB(MP(gallon, deadline));
  }

  sort(all(milk));
  
  for (int i = milk.size() - 1; i >= 0; --i)
  {
    current = milk[i].second; // current highest milk - deadline

    while (current)
    {
      if (!dl[current]) //current deadline, nothing is milked
      {
        //choose this
        dl[current] = 1;
        ans += milk[i].first;
        break;
      }
      else
      {
        current--; // choose this cow at previous time
      }
    }
  }
  

  printf("%lld\n", ans);

  return OfTheKing;
}


