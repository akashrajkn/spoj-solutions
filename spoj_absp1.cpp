/*
  problem code: ABSP1
  problem number: 18155
  problem link: http://www.spoj.com/problems/ABSP1/
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
  int t, n;

  scanf("%d", &t);

  while(t--)
  {
    scanf("%d", &n);

    ll a[n];

    rep(i,n)
    {
      sc(a[i]);
    }

    ll sum = 0;

    rep(i, n/2)
    {
      sum += ((n- 2*i -1)*(a[n-i-1]-a[i])); //look at teh pattern,,,,,
      /*
        last number is added n-1 times, last but 1 number is added n-3 (add n-2 times, subtract 1 time)....
        and so on..... starting numbers will be the opposite ..... they will be subtracted so many times
      */
    }

    pf(sum);
  }

  return 0;
}