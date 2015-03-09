/*
problem code: NOTATRI
problem number: 
problem link: http://www.spoj.com/problems/NOTATRI/
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


int max(int a, int b)
{
  return a>b ? a : b;
}

vector<ll> stick(2001);


int main()
{
  ll n, num, ans;

  while (1)
  {
    ans = 0;
    getInt(n);

    if (n == 0)
    {
      break;
    }

    rep(i, n)
    {
      getInt(num);
      stick[i] = num;
    }

    sort(stick.begin(), stick.begin() + n); // sort the sticks

    for (int i = n - 1; i > 1; --i)
    {
      int j = 0;
      int k = i - 1;

      while (j < k)
      {
        while (j < k && stick[j] + stick[k] >= stick[i])
        {
          --k;
        }

        ans += (k - j);
        ++j;
      }

    }

    printf("%lld\n", ans);
  }

  return OfTheKing;
}

