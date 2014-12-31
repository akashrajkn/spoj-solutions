/*
  problem code: ATOMS
  problem number: 18164
  problem link: http://www.spoj.com/problems/ATOMS/
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
  int t;
  unsigned long long n,k,m;

  scanf("%d", &t);

  while(t--)
  {
    scanf("%llu %llu %llu", &n, &k, &m);

    unsigned long long ans = m/n;
    unsigned long long temp, t1;

    t1 = 0;

    if(ans>0)
    {
      temp = k;

      while(ans>=temp)
      {
        t1++;
        temp*=k;
        if(temp<0)
        {
          break;
        }
      }
    }

    printf("%llu\n", t1);
  }




  return 0;
}



