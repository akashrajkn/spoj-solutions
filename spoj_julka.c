#include<stdio.h>
#include<string.h>
int main()
{
    long long k,n,t,f;
    short p=10;
    while(p--)
    {
        scanf("%lld",&t);
        scanf("%lld",&f);
        n=(t-f)/2;
        k=n+2;
        printf("%lld\n%lld\n",k,n);
    }
    return 0;
}
