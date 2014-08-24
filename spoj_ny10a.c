#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
  int t, n, i;
  char b[41];
  int ans;

  ans=malloc(8*sizeof(int));

  scanf( "%d", &t );
  while(t--)
  {
    scanf( "%d", &n );
    scanf( "%s", b );

    for( i=0; i<38; i++ )
    {
      if( b[i]=='H' )
      {
        if( b[i+1]=='H' )
        {
          if( b[i+2]=='H' )
          {
            ans[7]++; //HHH
          }
          else
          {
            ans[6]++; //HHT
          }
        }
        else
        {
          if( b[i+2]=='H' )
          {
            ans[5]++; //HTH
          }
          else
          {
            ans[4]++; //HTT
          }
        }
      }
      else
      {
        if( b[i+1]=='H' )
        {
          if( b[i+2]=='H' )
          {
            ans[3]++; //THH
          }
          else
          {
            ans[2]++; //THT
          }
        }
        else
        {
          if( b[i+2]=='H' )
          {
            ans[1]++; //TTH
          }
          else
          {
            ans[0]++; //TTT
          }
        }
      }
    }

    printf( "%d ", n );
    for( i=0; i<8; i++ )
    {
      printf( "%d ", ans[i] );
    }
    printf( "\n" );
  }

  return 0;
}