#include<stdio.h>
int main()
{
    int t,i,j,temp,m,n;
    int a[200];
    temp=0;
    int y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        a[0]=1;
        m=1;
        temp=0;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<m;j++)
            {
                y=a[j]*i+temp;
                a[j]=y%10;
                temp=y/10;
            }
            while(temp>0)
            {
                a[m]=temp%10;
                temp/=10;
                m++;
            }
        }
        for(i=m-1;i>=0;i--)
        {
            printf("%d",a[i]);
        }
        printf("\n");


    }



    return 0;
}
