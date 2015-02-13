/*
problem code: HAYBALE
problem number: 10500
problem link: http://www.spoj.com/problems/HAYBALE/
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


ll n, k, a, b;
ll arr[1000002];
ll medianOfMedians();
int compare(const void *a, const void *b);


int main()
{
  /*
  updation method
  */
  getInt(n);
  getInt(k);

  rep(i, k)
  {
    getInt(a);
    getInt(b);

    arr[a-1]++;
    arr[b]--;
  }

  gRep(i, 1, n)
  {
    arr[i] += arr[i - 1];
  }
  
  printf("%lld\n", medianOfMedians());

  return OfTheKing;
}


ll medianOfMedians()
{
  qsort(arr, n, sizeof(ll), compare);

  return arr[n / 2];
}


int compare(const void *a, const void *b)
{
  return *(ll *)a - *(ll *)b;
}