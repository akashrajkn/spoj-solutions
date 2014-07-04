#include<stdio.h>
int main()
{
    int N,x,y;
    long long m;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d %d",&x,&y);
        if(x==y)
        {
            if(x%2!=0)
            {
                m=2*x -1;
                printf("%lld\n",m);
            }
            else
            {
                m=2*x;
                printf("%lld\n",m);
            }
        }
        else if(y==x-2)
        {
            if(x%2==0)
            {
                m=x+y;
                printf("%lld\n",m);
            }
            else
            {
                m=x+y-1;
                printf("%lld\n",m);
            }
        }
        else printf("No Number\n");
    }
    return 0;
}
