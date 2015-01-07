/*
  problem code: INVCNT
  problem number: 6256
  problem link: http://www.spoj.com/problems/INVCNT/
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

using namespace std;

#define OfTheKing 0
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
#define g_u getchar() //if windows use getchar()
//#define g_u getchar_unlocked()

typedef pair<long long,long long> pii;
typedef long long ll;


//fast input function
inline void getInt( int &n )
{
  n=0;
  int ch=g_u;
  int sign=1;
  while( ch < '0' || ch > '9' )
  {
    if(ch=='-')
    {
      sign=-1;
    }
    ch=g_u;
  }
  while( ch >= '0' && ch <= '9' )
  {
    n=(n<<3)+(n<<1)+ ch-'0';
    ch=g_u;
  }
  n*=sign;
}



ll a[200002];
ll temp[200002];
ll n;

ll mergeSort(ll , ll);
ll merge(ll , ll, ll);


int main()
{
  ll t;

  sc(t);

  while(t--)
  {
    sc(n);

    rep(i,n)
    {
      sc(a[i]);
    }

    pf(mergeSort(0,n-1));
  }

  return OfTheKing;
}


ll mergeSort( ll lo, ll hi )
{
  ll invcnt = 0;
  if(lo<hi)
  {
    ll mid = (lo+hi)/2;
    invcnt = mergeSort(lo,mid);
    invcnt += mergeSort(mid+1, hi);
    invcnt += merge(lo,mid+1,hi);
  }

  return invcnt;
}


ll merge(ll lo, ll mid, ll hi)
{
  ll i = lo, j = mid, k = lo;

  ll invcnt = 0;

  while( i<=mid-1 && j<=hi )
  {
    if( a[i]<=a[j] )
    {
      temp[k++] = a[i++];
    }
    else
    {
      temp[k++] = a[j++];
      invcnt += (mid-i);
    }
  }

  while(i<=mid-1)
  {
    temp[k++] = a[i++];
  }
  while(j<=hi)
  {
    temp[k++] = a[j++];
  }

  gRep(i,lo,hi+1)
  {
    a[i] = temp[i];
  }

  return invcnt;
}
