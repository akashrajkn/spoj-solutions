#include <stdio.h>

int main(void) 
{
  long long t, n;
  int p;
  
  scanf( "%lld", &t );
  while( t-- )
  {
    scanf( "%lld %d", &n, &p );
    if( p==0 )
    {
      printf( "Airborne wins.\n" );
    }
    else
    {
      printf( "Pagfloyd wins.\n" );
    }
  }
  
  return 0;
}

