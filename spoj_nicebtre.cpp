/*
  problem code: NICEBTRE
  problem number: 13384
  problem link: http://www.spoj.com/problems/NICRBTRE/
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

int counter;
string c;
int recur();


int main()
{
  int t;

  scanf("%d",&t);

  while(t--)
  {
    cin>>c;
    counter=0;
    printf("%d\n", recur()-1);
  }

  return 0;
}


int recur()
{
  if(c[counter++]=='l')
  {
    return 1;
  }

  return max(recur(), recur())+1;
}





