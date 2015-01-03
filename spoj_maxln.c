#include<stdio.h>
#include<math.h>
int main()
{
    int t,i;
    double r,ac,ab2,answer;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
      scanf("%lf",&r);
      ab2=((16*r*r)-1)/4.0;
      ac= (4*r*r)-ab2;
      answer=ab2+sqrt(ac);
      printf("Case %d: %.2lf\n",i,answer);
    }
    return 0;
} 
