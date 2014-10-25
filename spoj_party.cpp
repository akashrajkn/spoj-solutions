/*
  problem code: PARTY
  problem number: 97
  problem link: http://www.spoj.com/problems/PARTY/
*/


#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <iterator>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <deque>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <utility>
#include <climits>
#include <ctime>

using namespace std;

int max( int a, int b )
{
  return a>b?a:b;
}


int main()
{
  int n, wt, i, j;


  while(1)
  {
    scanf("%d %d",&wt, &n);//max weight and number of items

    if(n==0 && wt==0)
    {
      return 0;
    }

    int w[n], v[n]; //weight and value of the items

    for( i=0; i<n; i++ )
    {
      scanf("%d %d", &w[i], &v[i]);
    }

    int knapsack[n+1][wt+1];//matrix for dp 

    for( i=0; i<=n; i++ )
    {
      for( j=0; j<=wt; j++ )
      {
        if( i==0 || j==0 )
        {
          knapsack[i][j]= 0;
        }
        else if( w[i-1]<=j )
        {
          int one = v[i-1]+knapsack[i-1][j-w[i-1]];
          int two = knapsack[i-1][j];

          if(one>two)
          {
            knapsack[i][j] = one;
          }
          else
          {
            knapsack[i][j] = two;
          }          
        }
        else
        {
          knapsack[i][j] = knapsack[i-1][j];
        }

      }
    }

    int i = wt;

    while( knapsack[n][i-1]==knapsack[n][i] )
    {
      i--;
    }

    printf( "%d %d\n", i, knapsack[n][wt] );
  }
  return 0;
}



