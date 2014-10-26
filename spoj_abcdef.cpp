/*
  problem code: ABCDEF
  problem number: 4580
  problem link: http://www.spoj.com/problems/ABCDEF/
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

#define all(v) v.begin(), v.end()

using namespace std;

int main()
{
  int n;

  scanf("%d", &n);
  
  vector<int> a(n);

  for(int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }

  vector<int> c,d;

  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      for(int k=0; k<n; k++)
      {
        c.push_back( a[i]*a[j] + a[k] );
      }
    }
  }

  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      for(int k=0; k<n; k++)
      {
        if(a[k]==0)
          continue;
        d.push_back( (a[i]+a[j])*a[k] );
      }
    }
  }

  sort( all(c) );
  sort( all(d) );

  int csize = c.size();
  int dsize = d.size();
  int lo, hi;
  long long ans = 0;

  for(int i=0; i<csize; i++)
  {
    lo = lower_bound(d.begin(), d.end(), c[i]) - d.begin();
    hi = upper_bound(d.begin(), d.end(), c[i]) - d.begin();
    ans += (hi-lo);
  }


  printf("%lld\n", ans );


  return 0;
}