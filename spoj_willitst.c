#include<stdio.h>
int main()
{
  long long n,p;
  scanf("%lld",&n);
  p=n-1;
  if(n&p)
    printf("NIE\n");
  else printf("TAK\n");
  return 0;
}
