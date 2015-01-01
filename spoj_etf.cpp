/*
  problem code: ETF
  problem number: 4141
  problem link: http://www.spoj.com/problems/ETF/
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

using namespace std;

#define rep(i,n) for(long long i=0; i<n; ++i)
#define gRep(i,p,n) for(long long i=p; i<n; ++i)
#define mp make_pair
#define all(c) c.begin(),c.end()
#define sc(a) scanf("%lld", &a)
#define pf(a) printf("%lld\n",a)
#define ub upper_bound
#define lb lower_bound
#define bs binary_search
#define pb push_back

typedef pair<long long,long long> pii;
typedef long long ll;

int etf(int);

int main()
{
  int t,n;

  scanf("%d", &t);

  while(t--)
  {
    scanf("%d", &n);

    printf("%d\n", etf(n));
  }

  return 0;
}

int etf(int n)
{
  int result = n;

  for( int i=2; i*i<=n; ++i )
  {
    if(n%i==0)
    {
      result -= (result/i);
    }
    while(n%i==0)
    {
      n/=i;
    }
  }

  if(n>1)
  {
    result -= (result/n);
  }

  return result;
}


