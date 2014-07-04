#include<stdio.h>
#define gc getchar_unlocked

long read_int();

int main()
{
  long n, ans, p;

  ans = 0;
  n=read_int();
  while(n--)
  {
    p=read_int();
    ans = ans^p;
  }
  printf( "%ld\n", ans );

  return 0;
}

long read_int() 
{
  long ret = 0;

  char c = gc();
  while(c<'0' || c>'9')
  {
    c = gc();
  }

  while(c>='0' && c<='9') 
  {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  
  return ret;
}
