/*
problem code: SCPC11B
problem number: 9756
problem link: http://www.spoj.com/problems/SCPC11B/
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

vector<int> station(1500);


int main()
{
  /*
    adhoc - O(nlogn) solution, can be easily improved to O(n)
  */
  ll n, point, remaining;
  bool possible;

  while (true)
  {
    possible = true;
    getInt(n);

    if (n == 0)
    {
      break;
    }

    rep(i, n)
    {
      getInt(point);
      station[i] = point;
    }

    sort(station.begin(), station.begin() + n);

    gRep(i, 1, n)
    {
      if (station[i] - station[i - 1] > 200)
      {
        possible = false;
        break;
      }
    }

    if (!possible)
    {
      printf("IMPOSSIBLE\n");
      continue;
    }

    remaining = 1422 - station[n - 1];
    if (remaining * 2 > 200)
    {
      printf("IMPOSSIBLE\n");
    }
    else
    {
      printf("POSSIBLE\n");
    }
    
  }

  return OfTheKing;
}


