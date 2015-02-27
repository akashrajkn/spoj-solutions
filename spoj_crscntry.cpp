/*
problem code: CRSCNTRY
problem number: 66
problem link: http://www.spoj.com/problems/CRSCNTRY/
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
#include<bitset>
#include<fstream>

using namespace std;

#define OfTheKing 0
#define rep(i,n) for(long long i=0; i<n; ++i)
#define gRep(i,p,n) for(long long i=p; i<n; ++i)
#define MP make_pair
#define all(c) c.begin(),c.end()
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define PB push_back
#define PF push_front
//#define g_u getchar_unlocked() //if windows use getchar()
#define g_u getchar()

typedef pair<long long, long long> pii;
typedef long long ll;


//fast input function
inline void getInt(int &n)
{
  n = 0;
  int ch = g_u;
  int sign = 1;
  while (ch < '0' || ch > '9')
  {
    if (ch == '-')
    {
      sign = -1;
    }
    ch = g_u;
  }
  while (ch >= '0' && ch <= '9')
  {
    n = (n << 3) + (n << 1) + ch - '0';
    ch = g_u;
  }
  n *= sign;
}


int max(int a, int b)
{
  return a>b ? a : b;
}


int lcs(vector<int> &a, vector<int> &b);


int main()
{
  int t, checkpoint;
  int maxCheckpoints; //max number of checkpoints coniciding

  getInt(t);

  while (t--)
  {
    maxCheckpoints = 0;
    vector<int> agnes, tom;

    while (1) //get input for agnes route card
    {
      getInt(checkpoint);
      if (checkpoint == 0)
      {
        break;
      }
      agnes.PB(checkpoint);
    }

    while (1) //get input for tom route card
    {
      tom.clear();
      while (1) //each route
      {
        getInt(checkpoint);
        if (checkpoint == 0)
        {
          break;
        }
        tom.PB(checkpoint);
      }
      if (tom.empty()) // if current route is empty, then exit
      {
        break;
      }

      //process tom's present route and check with agnes' route
      maxCheckpoints = max(maxCheckpoints, lcs(agnes, tom));
    }

    printf("%d\n", maxCheckpoints);
  }


  return OfTheKing;
}


int lcs(vector<int> &agnes, vector<int> &tom)
{
  int m, n;
  m = agnes.size();
  n = tom.size();

  int dp[m + 1][n + 1];

  rep(i, m+1)
  {
    rep(j, n+1)
    {
      if (i == 0 || j == 0)
      {
        dp[i][j] = 0;
      }
      else if (agnes[i - 1] == tom[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return dp[m][n];
}

