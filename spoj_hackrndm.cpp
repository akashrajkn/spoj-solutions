/*
  problem code: HACKRNDM
  problem number: 9734
  problem link: http://www.spoj.com/problems/HACKRNDM/
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
#define pb push_back

typedef pair<long long,long long> pii;
typedef long long ll;

int main()
{
  int n,k,x;

  scanf("%d %d", &n, &k);

  vector<int> a(n);

  rep(i, n)
  {
    scanf("%d", &x);
    a[i] = x;
  }

  sort(all(a));

  int count = 0;

  rep(i,n)
  {
    if( binary_search(all(a), a[i]+k) )
    {
      count++;
    }
  }

  printf("%d\n", count );

  return 0;
}
