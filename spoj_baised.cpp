/*
  problem code: BAISED
  problem number: 2149
  problem link: http://www.spoj.com/problems/BAISED/
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


int main()
{
  ll n,t;
  char c;
  sc(t);

  while(t--)
  {
    sc(n);

    ll a[n];

    rep(i, n)
    {
      while(1)
      {
        scanf("%c", &c);
        if(c==' ')
        {
          break;
        }
      }
      sc(a[i]);
    }

    sort(a, a+n);

    ll ans= 0;
    rep(i,n)
    {
      ans += abs(i + 1 - a[i]);
    }

    printf("%lld\n", ans);
  }

  return 0;
}