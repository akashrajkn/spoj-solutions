/*
  problem code: SHPATH
  problem number: 15
  problem link: http://www.spoj.com/problems/SHPATH/
*/

//Dijstra's algorithm
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
#include<climits>

#define INF 100000000;

using namespace std;

void dijkstra(int a, int b, int c );
int minDistance( int a[], int b, int c );

int adjMat[10001][10001];

int main()
{
  int t, n, p, nr, r, cost, src, dest, temp;
  char src1[11], dest1[11];

  scanf("%d", &t);

  while(t--)
  {
    scanf("%d", &n);
    map < string, int> M;  //maps the city name to a number
    char city[11];

    for(int i=0; i<n; i++)
    {
      for(int j=0; j<n; j++)
      {
        adjMat[i][j] = 0;
      }
    }

    //input city and neighbours
    for( int i=1; i<=n; i++ )
    {
      scanf("%s", city);

      M[city] = i; //map city name to city number

      scanf("%d", &p);

      for( int j=0; j<p; j++ )
      {
        scanf("%d %d", &nr, &cost);

        adjMat[i][nr] = cost;
      }
    }

    //paths to calculate the min dist
    scanf("%d", &r);
    src=-1, dest=-1;
    for( int i=0; i<r; i++ )
    {
      scanf("%s %s", src1, dest1);

      src = M[src1];
      dest = M[dest1];

      //dijkstra's algorithm
      dijkstra( src, dest, n+1 ); //size is n+1.. cities are 1 indexed
    }
  }

  return 0;
}


//calculate the minimum dist vertex from the set of vertices not included in the sptSet
int minDistance( int dist[], bool sptSet[], int size )
{
  int min = INT_MAX, min_index;

  for(int i=0; i<size; i++)
  {
    if(sptSet[i]==false && dist[i]<=min)
    {
      min = dist[i];
      min_index = i;
    }
  }
  return min_index;
}


void dijkstra(int src, int dest, int size )
{
  int dist[size];// distance of every vertex from the src vertex

  bool sptSet[size]; //shortest path tree set....

  //initialization
  for( int i=0; i<size; i++ )
  {
    dist[i] = INT_MAX;
    sptSet[i] = false;
  }

  dist[src]=0; // dist of src from itself is 0.

  for(int i=0; i<size-1; i++)
  {
    int u = minDistance(dist, sptSet, size);

    //vertex u is included in sptSet
    sptSet[u] = true;

    for(int j=0; j<size; j++)
    {
      if( !sptSet[j] && adjMat[u][j] && dist[u]!=INT_MAX && dist[u]+adjMat[u][j]< dist[j] )
      {
        dist[j]=dist[u]+adjMat[u][j]; //path from src vertex to jth vertex through vertex u is smaller than previously calculated
      }
    }
  }

  printf("%d\n", dist[dest]); //required distance of dest from src
}



