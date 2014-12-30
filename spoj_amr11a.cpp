/*
  problem code: AMR11A
  problem number: 10228
  problem link: http://www.spoj.com/problems/AMR11A/
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
  int t,r,c;
  bool pos;

  /*
    hint: dp, but build the solution from behind. suppose we are at (r-1,c-1) cell, then optimal way to
    go to (r,c) is max(s[r][c-1], s[r-1][c]). now minimum value required required to go from r-1,c-1 can
    be calculated by choosing left or bottom cell.
  */

  scanf("%d", &t);

  while(t--)
  {
    pos = true;
    scanf("%d %d", &r, &c);

    int s[r+1][c+1];
    int dp[r+1][c+1];
    int dpsum[r+1][c+1];
    dp[1][1] = 1;
    dpsum[1][1] = 1;

    gRep(i,1,r+1)
    {
      gRep(j,1,c+1)
      {
        scanf("%d", &s[i][j]);
        if(s[i][j]<0)
        {
          pos = false;
        }
      }
    }

    if(pos) // if all values are non-negative, then start with '1'
    {
      printf("1\n");
      continue;
    }
    s[r][c] = 1;

    //last row
    for( int i=c-1; i>0; --i)
    {
      s[r][i] = s[r][i+1] - s[r][i];
      if(s[r][i]<1)
      {
        s[r][i] = 1; // if we start at (r,i) minmum amount of power needed to go to r,i+1 would be 1
      }
    }

    //last col
    for( int i=r-1; i>0; --i)
    {
      s[i][c] = s[i+1][c] - s[i][c];
      if(s[i][c]<1)
      {
        s[i][c] = 1;
      }
    }

    //for other rows and columns
    for( int i=r-1; i>0; --i )
    {
      for( int j=c-1; j>0; --j )
      {
        if(s[i+1][j]>s[i][j+1]) // select min of right and bottom cells
        {
          //select bottom cell
          s[i][j] = s[i][j+1] - s[i][j];
        }
        else
        {
          s[i][j] = s[i+1][j] - s[i][j];
        }
        if(s[i][j]<1)
        {
          s[i][j] = 1;
        }
      }
    }

    printf("%d\n", s[1][1]);


//print all the vals
/*
    cout<<"dpsum\n";
    gRep(i,1,r+1)
    {
      gRep(j, 1, c+1)
      {
        cout<<dpsum[i][j]<<" ";
      }
      cout<<endl;
    }


    cout<<"dp\n";
    gRep(i,1,r+1)
    {
      gRep(j, 1, c+1)
      {
        cout<<dp[i][j]<<" ";
      }
      cout<<endl;
    }

//
*/
    //cout<<endl;
  }

  return 0;
}



