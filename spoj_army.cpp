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


int main(int argc, char *argv[])
{
  int t, ng, nm;

  scanf("%d",&t);

  while(t--)
  {
    scanf("%d %d", &ng, &nm);

    vector<pii> g;
    int power;

    rep(i,ng)
    {
      scanf("%d", &power );
      g.pb(mp(power, 2));
    }

    rep(i,nm)
    {
      scanf("%d", &power);
      g.pb(mp(power,1));
    }

    sort(all(g));

    if(g[ng+nm-1].second == 1)
    {
      printf("MechaGodzilla\n");
    }
    else
    {
      printf("Godzilla\n");
    }
  }

  return 0;
}



