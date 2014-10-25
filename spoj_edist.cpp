/*
  problem code: EDIST
  problem number: 3378
  problem link: http://www.spoj.com/problems/EDIST/
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

char a[2005];
char b[2005];

int dp[2005][2005];

int min( int a, int b, int c )
{
  return (a>b)?((b>c)?c:b):((a>c)?c:a);
}


int main()
{
  int t;

  scanf("%d", &t);

  while(t--)
  {
    scanf("%s", a);
    scanf("%s", b);

    int lena = strlen(a);
    int lenb = strlen(b);

    for(int i=0; i<=lena; i++)
    {
      dp[i][0] = i;
    }

    for(int j=0; j<=lenb; j++)
    {
      dp[0][j] =j;
    }


    for(int i=1; i<=lena; i++)
    {
      for(int j=1; j<=lenb; j++)
      {
        int left = dp[i][j-1];
        left+=1;

        int top = dp[i-1][j];
        top+=1;

        int corner = dp[i-1][j-1];
        corner += (a[i-1]!=b[j-1]);

        dp[i][j] = min(left, corner, top);
      }
    }

    printf("%d\n", dp[lena][lenb]);
  }

  return 0;
}



