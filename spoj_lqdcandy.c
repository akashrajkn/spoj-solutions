#include<stdio.h>

#include<math.h>
long long min;
int main()
{
  long long t,n,i,need,p,j;
  scanf("%lld",&t);
  while(t--)
  {
    need=1;
    scanf("%lld",&n);
    i=ceil(log2(n));
    need=need<<i;
    for(j=0;j<=i;j++)
    {
      p=n>>j;
      if(p & 1 == 1)
      {
        min=j;
        break;
      }
    }
    printf("%lld %lld\n",need,i-min);
  }
  return 0;
}

