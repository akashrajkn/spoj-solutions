/*
  problem code: PERMUT1
  problem number: 64
  problem link: http://www.spoj.com/problems/PERMMUT1/
*/

//simple dp

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

using namespace std;

int permut1( int a, int b );
int dp[13][99];

int main()
{
  int t, n, k;

  scanf("%d", &t);

  for(int i=0; i<13; i++)
  {
    for(int j=0; j<99; j++)
    {
      dp[i][j] = -1;
    }
  }

  while(t--)
  {
    scanf("%d %d", &n, &k);

    printf("%d\n", permut1( n,k ));
  }

  return 0;
}


int permut1( int n, int k )
{
  if(n==0)
    return 0;
  if(k==0)
    return 1;

  if(dp[n][k]!=-1)
  {
    return dp[n][k];
  }

  int sum = 0;
  for( int i=0; i<n && k-i >=0 ; i++ )
  {
    sum += permut1( n-1, k-i );
  }

  return (dp[n][k]= sum);
}

