/*
  problem code: ALICESIE
  problem number: 10565
  problem link: http://www.spoj.com/problems/ALICESIE/
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
  int t, n;
  scanf("%d",&t);
  
  while(t--)
  {
    scanf("%d", &n);
    printf("%d\n",n-(n/2) );
  }

  return 0;
}