/*
  problem code: BITMAP
  problem number: 206
  problem link: http://www.spoj.com/problems/BITMAP/
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
#include<unistd.h>

#define INF 100000000;

using namespace std;

int main()
{
  int t, n, m;

  scanf("%d", &t);

  while(t--)
  {
    scanf("%d %d", &n, &m);

    int mat[n][m];
    char inp[m];

    queue < pair<int, int> > q;

    for( int i=0; i<n; i++ )
    {
      scanf("%s", inp);
      for(int j=0; j<m; j++)
      {
        if( inp[j]=='1' )
        {
          q.push( make_pair(i,j) );
          mat[i][j] = 0;
        }
        else
        {
          mat[i][j] = INF;
        }
      }
    }

    pair <int, int > pii;

    //BFS 
    while(!q.empty())
    {
      pii = q.front();
      q.pop();

      int pa = pii.first;
      int pb = pii.second;

      int dist;

      if( pa-1>=0 && mat[pa-1][pb]!=0 )
      {
        dist = mat[pa][pb]+1;
        if( mat[pa-1][pb]>dist )
        {
          mat[pa-1][pb] = dist;
          q.push(make_pair(pa-1, pb));
        }
      }
      if( pa+1<n && mat[pa+1][pb]!=0 )
      {
        dist = mat[pa][pb]+1;
        if( mat[pa+1][pb]>dist )
        {
          mat[pa+1][pb] = dist;
          q.push(make_pair(pa+1, pb));
        } 
      }
      if( pb-1>=0 && mat[pa][pb-1]!=0 )
      {
        dist = mat[pa][pb]+1;
        if( mat[pa][pb-1]>dist )
        {
          mat[pa][pb-1] = dist;
          q.push(make_pair(pa, pb-1));
        } 
      }
      if( pb+1<m && mat[pa][pb+1]!=0 )
      {
        dist = mat[pa][pb]+1;
        if( mat[pa][pb+1]>dist )
        {
          mat[pa][pb+1] = dist;
          q.push(make_pair(pa, pb+1));
        } 
      }
    }

    //print final matrix
    for( int i=0; i<n; i++ )
    {
      for( int j=0; j<m; j++ )
      {
        printf("%d  ", mat[i][j]);
      }
      printf("\n");
    }

  }

  return 0;
}


