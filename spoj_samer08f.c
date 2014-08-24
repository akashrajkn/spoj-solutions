#include<stdio.h>
int main()
{
    long n;
    long long ans;
    while(1)
    {
        scanf("%ld",&n);
        if(n==0)
        {
            break;
        }
        else
        {
            ans=(2*n*n*n)+(3*n*n)+n;
            ans/=6;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
