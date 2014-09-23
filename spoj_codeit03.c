#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int dow( int d, int m, int y )
{
  static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

  y -= m <3;

  return ( y + y/4 - y/100 + y/400 + t[m-1] + d )% 7;
}

int main()
{
  int t, d, m, y, ans;
  char day[7][10] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

  scanf( "%d", &t );

  while(t--)
  {
    scanf( "%d %d %d", &d, &m, &y );

    ans = dow( d, m, y );

    if(ans==0)
    {
      printf("%s\n", day[6] );
    } 
    else
    {
      printf( "%s\n", day[ans - 1] );
    }
  }

  return 0;
}