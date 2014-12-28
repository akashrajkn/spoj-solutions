/*
  problem code: AGGRCOW
  problem number: 297
  problem link: http://www.spoj.com/problems/AGGRCOW/
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
typedef long long int ll;

ll n,c;
ll a[100001];

ll f(ll);
ll bsearch();

int main()
{
  ll t;

  scanf("%lld", &t);

  while(t--)
  {
    scanf("%lld %lld", &n, &c);

    rep(i,n)
    {
      scanf("%lld", &a[i]);
    }

    sort(a,a+n);

    printf("%lld\n", bsearch() ); //binary search ---- 0:1:a[n-1]---f(num) will be 111111...110000.....00
    //we need to find the last '1' in the array---binary search
  }

  return 0;
}

ll bsearch()
{
  ll lo = 0, hi = a[n-1];

  while(lo<hi)
  {
    int mid = (lo+hi)/2;

    if(f(mid)==1)
    {
      lo = mid+1;
    }
    else
    {
      hi = mid;
    }
  }

  return lo-1;
}

ll f(ll p)
{
  ll counter=1;
  ll lp = a[0];

  for(int i=1; i<n; ++i)
  {
    if( (a[i]-lp) >=p)
    {
      counter++;
      if(counter==c)
      {
        return 1;
      }
      lp =a[i];
    }
  }

  return 0;
}



