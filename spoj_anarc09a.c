#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char a[2005], b[2005];

int main()
{
  int i, j, t, ans, len;
  t=1;

  while(1)
  {
    ans = 0;
    scanf( "%s", a );
    if( a[0]=='-' )
    {
      return 0;
    }
    len = strlen(a);
    j = 0;

    b[j++] = a[0];
    for( i=1; i<len; ++i )
    {
      if( j==0 )
      {
        b[j++]= a[i];
      }
      else if( b[j-1]=='{' && a[i]=='}' )
      {
        j--;
      }
      else
      {
        b[j] = a[i];
        j++;
      }
    }

    if( j==0 )
    {
      printf( "%d. %d\n", t, j );
      t++;
      continue;
    }

    for( i=0; i<j; i+=2 )
    {
      if( b[i]=='{' && b[i+1]=='{' )
      {
        ans++;
      }
      else if( b[i]=='}' && b[i+1]=='}' )
      {
        ans++;
      }
      else if( b[i]=='}' && b[i+1]=='{' )
      {
        ans+=2;
      }
    }

    printf("%d. %d\n",t, ans );
    t++;
  }

  return 0;
}

