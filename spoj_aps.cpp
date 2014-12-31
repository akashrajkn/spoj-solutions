/*
  problem code: APS
  problem number: 13753
  problem link: http://www.spoj.com/problems/APS/
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

bool prime[10000007];
ll a[10000007];
ll pd[10000007];
 
void sieve()
{
  for (ll i = 2; i <=10000007; i+= 2)
  {
    prime[i]=true;
    pd[i] = 2; // for even numbers pd is 2
  }

  for (ll i = 3; i <=10000007; i += 2)
  {
    if (!prime[i])
    {
      pd[i] = i;
      for (ll j=i; (j*i) <=10000007; j += 2)
      {
        prime[j*i] = true;
        if(!pd[j*i])
          pd[j*i] = i;
      }
    }
  }
}


int main()
{
  ll t,n;

  sieve(); // generate the primes and the pd array--- pd array contains the smallest prime factor of each nunber

/*
  dp--bottom up approach, all the values a[n] are built before querying

  recursion-memoization using the same apporach caused TLE---
*/
  
  a[0]=0;
  a[1]=0;
  for(int i=2;i<=10000007;i++)
  {
      a[i]=a[i-1]+pd[i];
  }

  sc(t);

  while(t--)
  {
    sc(n);

    pf(a[n]);
  }
  return 0;
}

