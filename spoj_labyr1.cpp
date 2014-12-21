/*
  problem code: LABYR1
  problem number: 38
  problem link: http://www.spoj.com/problems/LABYR1/
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

char inp[1000][1000];
int dist[1000][1000];
int que[1000000][2];

pii bfs(int r, int c, int row, int col);

int main()
{
  int t, r, c, r1, c1, first = 1;

  scanf("%d", &t);

//  cin>>t;
  while(t--)
  {
    scanf("%d%d", &c, &r);
//    cin>>c>>r;

    rep(i,r)
    {
      rep(j,c)
      {
        //scanf("%c", &inp[i][j]);
        cin>>inp[i][j];
        if(first==1 && inp[i][j]=='.')
        {
          r1 = i; c1 = j;
          first = 0;
        }
      }
    }
    // connected graphs, acyclic---forms a quad-tree
    //do two bfs.... same as spoj_pt07z.....

    pii far1 = bfs(r1,c1, r, c);
    far1 = bfs(far1.first , far1.second, r, c);

    printf("Maximum rope length is %d.\n", dist[far1.first][far1.second]);
  }

  return 0;
}

pii bfs(int r, int c, int row, int col)
{
  int top = 0, bot=0;

  //O(n^2) to clear???
  rep(i, row)
  {
    rep(j, col)
    {
      if(inp[i][j]=='#')
      {
        dist[i][j] = 0;
      }
      else
      {
        dist[i][j] = -1;
      }
    }
  }

  dist[r][c] = 0;

  que[bot][0] = r;
  que[bot][1] = c;
  bot++;

  int max = dist[r][c];
  int maxNoder = r;
  int maxNodec = c;

  while(bot>=top)
  {
    int currNoder = que[top][0];
    int currNodec = que[top][1];
    top++;

    if(inp[currNoder-1][currNodec]=='.' && dist[currNoder-1][currNodec]==-1)//four directions
    {
      que[bot][0] = currNoder-1;
      que[bot][1] = currNodec;
      bot++;

      dist[currNoder-1][currNodec] = dist[currNoder][currNodec] + 1;

      if( max < dist[currNoder][currNodec]+1 )
      {
        max = dist[currNoder][currNodec]+1;
        maxNoder = currNoder-1;
        maxNodec = currNodec;
      }
    }
    if(inp[currNoder][currNodec-1]=='.' && dist[currNoder][currNodec-1]==-1)//four directions
    {
      que[bot][0] = currNoder;
      que[bot][1] = currNodec-1;
      bot++;

      dist[currNoder][currNodec-1] = dist[currNoder][currNodec] + 1;

      if( max < dist[currNoder][currNodec]+1 )
      {
        max = dist[currNoder][currNodec]+1;
        maxNoder = currNoder;
        maxNodec = currNodec-1;
      }
    }
    if(inp[currNoder][currNodec+1]=='.' && dist[currNoder][currNodec+1]==-1)//four directions
    {
      que[bot][0] = currNoder;
      que[bot][1] = currNodec+1;
      bot++;

      dist[currNoder][currNodec+1] = dist[currNoder][currNodec] + 1;

      if( max < dist[currNoder][currNodec]+1 )
      {
        max = dist[currNoder][currNodec]+1;
        maxNoder = currNoder;
        maxNodec = currNodec+1;
      }
    }
    if(inp[currNoder+1][currNodec]=='.' && dist[currNoder+1][currNodec]==-1)//four directions
    {
      que[bot][0] = currNoder+1;
      que[bot][1] = currNodec;
      bot++;

      dist[currNoder+1][currNodec] = dist[currNoder][currNodec] + 1;

      if( max < dist[currNoder][currNodec]+1 )
      {
        max = dist[currNoder][currNodec]+1;
        maxNoder = currNoder+1;
        maxNodec = currNodec;
      }
    }


  }




  return mp(maxNoder, maxNodec);
}



