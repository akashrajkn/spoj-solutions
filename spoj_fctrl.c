#include<stdio.h>
int main()
{
    int t;
    long long n,sum=0,p=1,i,counter;
    scanf("%d",&t);
    while(t--)
    {
        p=1;
        counter=0;
        sum=0;
        scanf("%lld",&n);
        for(i=0;;i++)
        {
            if(p*5>n && n>=p)
            {
                counter=i;
                break;
            }
            p*=5;
        }
        p=1;
        for(i=1;i<=counter;i++)
        {
            p*=5;
            sum+=(long long)(n/p);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
