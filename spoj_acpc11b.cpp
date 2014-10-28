/*
  problem code: ACPC11B
  problem number: 10239
  problem link: http://www.spoj.com/problems/ACPC11B/
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

#define all(c) c.begin(),c.end()

using namespace std;

int main()
{
  int t, n1, n2;

  scanf("%d", &t);

  while(t--)
  {
    scanf("%d", &n1);
    int a[n1];

    for(int i=0; i<n1; i++)
    {
      scanf("%d", &a[i]);
    }

    scanf("%d", &n2);
    int b[n2];

    for(int i=0; i<n2; i++)
    {
      scanf("%d", &b[i]);
    }

    sort( a, a+n1 );
    sort( b, b+n2 );

    int i,j,diff;
    i=0; j=0;
    int min_diff = INT_MAX;

    while(i<n1 && j<n2 )
    {
      diff = abs(a[i]-b[j]);

      if(diff<min_diff)
      {
        min_diff = diff;
        if(min_diff==0)
        {
          break;
        }
      }

      if(a[i]>b[j])
      {
        j++;
      }
      else if(a[i]<=b[j])
      {
        i++;
      }
    }

    printf("%d\n",min_diff );
  }

  return 0; 
}










