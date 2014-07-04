#include<stdio.h>
#include<stdlib.h>

int main()
{
  int t;
  unsigned long long n;

  scanf( "%d", &t );

  while(t--)
  {
    scanf( "%llu", &n );
    printf( "%llu", (n*(3*n+1)/2)%1000007 );
  }

  return 0;
}