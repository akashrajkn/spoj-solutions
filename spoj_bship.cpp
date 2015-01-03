/*
  problem code: BSHIP
  problem number: 14822
  problem link: http://www.spoj.com/problems/BSHIP/
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

#define OfTheKing 0
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


int ship[2001][2001];
int dp1[2001][2001];
int dp2[2001][2001];
char c[2001];



int main()
{
  int m,n,s;

/*
  the solution is pretty straight forward -- simple dp, but here i have used two arrays- dp1 and dp2
  for speed optimization.....
*/


  scanf("%d %d %d",&m, &n, &s);

  rep(i,m) //grid input
  {
    scanf("%s", c);
    rep(j,n)
    {
      if(c[j]=='X')
      {
        ship[i][j] = 1;
      }
    }
  }

  rep(j,n) // first row of dp1
  {
    rep(k,s)
    {
      dp1[0][j] += ship[k][j];
    }
  }
  //remaining rows of dp1 array
  gRep(i, 1, m-s+1)
  {
    rep(j,n)
    {
      dp1[i][j] = dp1[i-1][j] + (ship[i+s-1][j] - ship[i-1][j]);
    }
  }

/*
  rep(i, m-s+1) //generating values for dp1 array
  {
    rep(j, n)
    {
      for(int k = i; k< s+i; ++k)
      {
        dp1[i][j] += ship[k][j];
      }
    }
  }
*/

  float ans = 0;

  rep(i, m-s+1) // first column of dp2 array
  {
    rep(k, s)
    {
      dp2[i][0] += dp1[i][k]; 
    }
    ans+=dp2[i][0];
  }
  //other values of dp2 array
  rep(i,m-s+1)
  {
    gRep(j, 1, n-s+1)
    {
      dp2[i][j] = dp2[i][j-1] + ( dp1[i][j+s-1] - dp1[i][j-1]);
      ans+=dp2[i][j];
    }
  }

/*
  rep(i, m-s+1) // genertating values for dp2 array
  {
    rep(j, n-s+1)
    {
      for(int k=j; k<s+j; ++k)
      {
        dp2[i][j] += dp1[i][k];
      }
      ans+= dp2[i][j];
    }
  }
*/

  printf("%.6f\n", ans/((m-s+1)*(n-s+1)) );

  return OfTheKing;
}
