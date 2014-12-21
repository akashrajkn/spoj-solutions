/*
  problem code: ROOTCIPH
  problem number: 6297
  problem link: http://www.spoj.com/problems/ROOTCIPH/
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
#define gRep(i,p,n) for(long long i=p, i<n; ++i)
#define mp make_pair
#define all(c) c.begin(),c.end()

typedef pair<long long,long long> pii;
typedef long long lli;

int main()
{
  int t; 
  lli a,b,c,ans;

  scanf("%d", &t);

  while(t--)
  {
    scanf("%lld %lld %lld", &a, &b, &c);

    ans = a*a - 2*b;
    printf("%lld\n", ans );
  }

  return 0;
}
