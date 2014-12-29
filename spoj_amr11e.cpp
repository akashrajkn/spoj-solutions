/*
  problem code: ABCPATH
  problem number: 9921
  problem link: http://www.spoj.com/problems/ABCPATH/
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

int a[1000];
int ans[1001];

int main()
{
  int t, n;
  int counter = 0;

/*
  solution: brute force--->testcases are weak
*/


  scanf("%d", &t);

  //generate primes
  a[1] = 0;
  for( int i=2; i<1000; ++i )
  {
    a[i]=1;
  }

  for( int i=2; i<500; ++i)
  {
    if(a[i])
    {
      for(int j=2; j<=1000/i; ++j)
      {
        a[i*j] = 0;
      }
    }
  }

  int numPrimes;
  int curr = 1;

  for(int i=1; i<3000; ++i)
  {
    numPrimes = 0;
    curr = 1;
    while(curr<1000)
    {
      if( a[curr]==1 )
      {
        if(i%curr==0)
        {
          numPrimes++;
        }
      }

      curr++;

      if(numPrimes==3)
      {
        //cout<<"lucky==="<<i<<endl;
        ans[counter++] = i;
        break;
      }
    }

  }
//cout<<"phew\n";

  while(t--)
  {
    scanf("%d", &n);

    printf("%d\n", ans[n-1] );

  }

  return 0;
}

