#include<stdio.h>
int main()
{
  int N,a,b,c,d,sum=0;
  int reverse(int v);
  scanf("%d",&N);
  while(N--)
  {
    scanf("%d %d",&a,&b);
    c=reverse(a);
    d=reverse(b);
    sum=c+d;
    sum=reverse(sum);
    printf("%d\n",sum);
  }
  return 0;
}

int reverse(int a)
{
  int rem,sum;
  rem=0;
  sum=0;
  while(a!=0)
  {
    rem=a%10;
    a=(int)(a/10);
    sum=(sum*10)+rem;
  }
  return sum;
}
