/*
problem code: AE00
problem number: 4300
problem link: http://www.spoj.com/problems/AE00/
*/
#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  int n, ans=0;

  scanf("%d", &n);

  for( int i=1; i<=n; i++ )
  {
    for( int j=i; j<=n; j++ )
    {
      if( i*j<=n )
      {
        ans++;
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}
