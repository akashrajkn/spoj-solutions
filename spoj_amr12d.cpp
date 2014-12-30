/*
  problem code: AMR12D
  problem number: 13043
  problem link: http://www.spoj.com/problems/AMR12D/
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

  scanf("%d", &t);

  while(t--)
  {
    char a[12];
    scanf("%s",a);

    int len = strlen(a);
    int c = 1;
    for(int i=0; i< len/2; ++i)
    {
      if(a[i]!=a[len-i-1])
      {
        c= 0;
        break;
      }
    }

    if(c==1)
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }

  }

  return 0;
}




