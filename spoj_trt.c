#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define gc getchar_unlocked
#define max(a,b) a>b?a:b

int read_int();
int func( int top, int bottom );

int n;
int cache[2001][2001];
int arr[2001];

int main()
{
  int i, maxelem;

  n = read_int();
  
  memset( cache, 0, sizeof(cache[0][0])*n*n );

  for( i=0; i<n; i++ )
  {
    arr[i] = read_int();
  }

  maxelem = func( 0, n-1 );
  
  printf( "%d\n", maxelem );

  return 0;
}


int func( int top, int bottom )
{
  if( top> bottom )
  {
    return 0;
  }

  if( cache[top][bottom]!=0 )
  {
    return cache[top][bottom];
  }

  int year = n + top - bottom;

  return cache[top][bottom] = max( func( top+1, bottom )+year*arr[top], func( top, bottom-1 )+year*arr[bottom] );
}


int read_int()
{
  int ret = 0;
  char c = gc();

  while( c<'0' || c>'9')
  {
    c = gc();
  }

  while( c>='0' && c<='9' )
  {
    ret = 10*ret + c - 48;
    c = gc();
  }

  return ret; 
}