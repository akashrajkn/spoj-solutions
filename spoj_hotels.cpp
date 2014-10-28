/*
  problem code: HOTELS
  problem number: 9861
  problem link: http://www.spoj.com/problems/HOTELS/
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

using namespace std;

int main()
{
  int n,m;

  scanf( "%d %d", &n, &m );

  int a[n];

  for(int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }

  int left =0, right=0;

  int max = 0;

  int currentSum = a[0];

  while(right<n)
  {
    if( currentSum>max && currentSum <=m )
    {
      max = currentSum;
    }

    if(currentSum<m)
    {
      right++;
      currentSum+=a[right];
    }
    else if(currentSum>m)
    {
      currentSum-=a[left];
      left++;
    }
    else if(currentSum==m)
    {
      printf("%d\n", m );
      
      return 0;
    }
  }

  printf("%d\n", max );

  return 0;
}