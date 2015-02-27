/*
problem code: CHOCOLA
problem number: 247
problem link: http://www.spoj.com/problems/CHOCOLA/
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
inline void getInt(int &n)
{
  n = 0;
  int ch = g_u;
  int sign = 1;
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
    greedy approach
  */

  int t, m, n, x, y;
  int costtot, costr, costc;

  getInt(t);

  while (t--)
  {
    vector< pair<int, int> > num;
    getInt(m);
    getInt(n);

    costtot = 0; costr = 1; costc = 1;

    rep(i, m-1)
    {
      getInt(x);
      num.PB(MP(x, 1)); //column split
    }

    rep(i, n-1)
    {
      getInt(y);
      num.PB(MP(y, 2)); //row split
    }

    num.resize(m + n-2);

    sort(num.rbegin(), num.rend());

    for (int i = 0; i < num.end() - num.begin(); ++i)
    {
      if (num[i].second == 1)
      {
        costtot += costc*num[i].first;
        costr++;
      }
      else if (num[i].second == 2)
      {
        costtot += costr*num[i].first; //greedy approach
        costc++;
      }
    }

    printf("%d\n", costtot);
  }

  return OfTheKing;
}




