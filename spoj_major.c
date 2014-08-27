#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int p[2005];

int main()
{
  int t, n, hitter, i;

  scanf( "%d", &t );

  while(t--)
  {
    hitter = -1;
    memset( p, 0, 2005*sizeof(int) );
    scanf( "%d", &n );
    int a[n];

    for( i=0; i<n; i++ )
    {
      scanf( "%d", &a[i] );
      p[a[i]+1000]++;
    }

    for( i=0; i<2005; i++ )
    {
      if( p[i] > (n/2) )
      {
        printf( "YES %d\n", i-1000 );
        hitter = i;
        break;
      }
    }
    if(hitter == -1)
      printf("NO\n");

  }

  return 0;
}