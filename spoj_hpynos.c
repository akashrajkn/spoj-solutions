#include<stdio.h>
int p[900];

int main()
{
  unsigned long long n, sum,temp;
  int count, digit, i;

  count=0;
  scanf( "%llu", &n );
  if(n>=2 && n<=9 && n!=7 )
  {
    printf("-1\n");
    return 0;
  }
  while(1)
  {
    count++;
    sum=0;
    while(n!=0)
    {
      digit = n%10;
      n/=10;
      sum+= (digit*digit);
    }
    n=sum;
    if(sum!=1)
    {
      if( p[sum-1]==0 )
      {
        p[sum-1]=1;
      }
      else
      {
        printf("-1\n");
        return 0;
      }
    }
    else
    {
      printf("\n%d\n",count);
      return 0;
    }
  }
  return 0;
}