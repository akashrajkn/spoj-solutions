/*
  problem code: AMR12G
  problem number: 13046
  problem link: http://www.spoj.com/problems/AMR12G/
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
  int t,n, m,k;

/*
  greedy solution: each time find the row with minimum on switches and flip the state, thereby getting
  more on lights overall... soln is O(n)
*/

  scanf("%d", &t);

  while(t--)
  {
    scanf("%d%d%d", &n, &m, &k);

    int state[n];
    char str[100];
    memset(state, 0, n*sizeof(int));

    rep(i,n)
    {
      scanf("%s", str);

      rep(j,m)
      {
        if(str[j]=='*')
        {
          state[i]++;
        }
      }
    }

    rep(i, k)
    {
      //change the state of a row
      int min = 0;
      gRep(j,1,n)
      {
        if(state[j]<state[min])
        {
          min = j;
        }
      }

      state[min] = m - state[min];
    }

    int ans = 0;

    rep(i,n)
    {
      ans+=state[i];
    }

    printf("%d\n", ans);
  }

  return 0;
}
