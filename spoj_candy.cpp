/*
problem code: CANDY
problem number: 2123
problem link: http://www.spoj.com/problems/CANDY/
*/

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
  int n;

  while(1)
  {
    scanf("%d", &n);

    if(n==-1)
    {
      return 0;
    }
    int a[n], sum=0;

    for( int i=0; i<n; i++ )
    {
      scanf("%d", &a[i]);
      sum+=a[i];
    }
    int d = (int)(sum/n);
    if( d*n != sum  )
    {
      printf("-1\n");
      continue;
    }
    int ans=0;
    for( int i=0; i<n; i++ )
    {
      if(a[i]<d)
      {
        ans+=(d-a[i]);
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
