/*
  problem code: MCOINS
  problem number: 3885
  problem link: http://www.spoj.com/problems/MCOINS/
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

bool arr[1000001];

int main()
{
  int k, l ,m;

  scanf("%d %d %d",&k,&l,&m);

  int marr[m];   
  int maxm = -1;

  for(int i=0; i<m; ++i)
  {
    scanf("%d", &marr[i]);
    if(marr[i]>maxm)
    {
      maxm = marr[i];
    }
  }

  //true--> A wins, false--> B wins
  arr[0] = false; //if no coins, then B wins

  //dp
  for(int i=1; i<=maxm; ++i)
  {
    arr[i] = !(arr[i-1]); 

    if(i>=k && !(arr[i-k]))
    {
      arr[i] = true;
    }

    if(i>=l && !(arr[i-l]))
    {
      arr[i] = true;
    }
  }


  for(int i=0; i<m; ++i)
  {
    if(arr[marr[i]]==true)
    {
      printf("A");
    }
    else
    {
      printf("B");
    }
  }

  return 0;
}



