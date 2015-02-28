/*
  problem code: CADYDIST
  problem number: 10442
  problem link: http://www.spoj.com/problems/CADYDIST/
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


vector<ll> cost(100000);
vector<ll> clType(100000);


int main()
{
  /*
    greedy approach
  */
  ll n, ci, p, ans;

  while (true)
  {
    getInt(n);
    
    if (n == 0)
    {
      break;
    }

    rep(i, n)
    {
      getInt(ci);
      clType[i] = ci; //number of students in ith class type
    }

    rep(i, n)
    {
      getInt(p);
      cost[i] = p; //cost of ith type of candy
    }

    sort(clType.begin(), clType.begin() + n);
    sort(cost.begin(), cost.begin() + n);

    ans = 0;

    rep(i, n)
    {
      ans += (clType[i] * cost[n - i - 1]);
    }

    printf("%lld\n", ans);
  }

  return OfTheKing;
}


