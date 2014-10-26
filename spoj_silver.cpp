/*
  problem code: SILVER
  problem number: 8785
  problem link: http://www.spoj.com/problems/SILVER/
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

int main()
{
  int n, ans;

  while(1)
  {
    scanf("%d", &n);

    if(n==0)
    {
      return 0;
    }

    ans = (int)(log(n)/log(2));

    printf("%d\n", ans);
  }

  return 0;
}