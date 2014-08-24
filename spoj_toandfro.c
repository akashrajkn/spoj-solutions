#include<stdio.h>
#include<string.h>
int main()
{
    int x=0,y=0;
    char a[200];
    char *ptr;
    int counter;
    int i=0,j=0;
    while(1)
    {
        scanf("%d",&x);
        if(x==0)
            break;
        scanf("%s",a);
        counter=0;
        ptr=a;
        y=strlen(a)/x;
        char b[y][x];
        j=0;
        for(i=0;i<y;i++)
        {
            if(j==0)
            {
                while(1)
                {
                    if(j==x)
                        break;
                    b[i][j]=ptr[counter];
                    counter++;
                    j++;
                }
            }
            else if (j==x)
            {
                while(1)
                {
                    if(j==0)
                        break;
                    b[i][j-1]=ptr[counter];
                    counter++;
                    j--;
                }
            }
        }
        for(i=0;i<x;i++)
        {
            for(j=0;j<y;j++)
                printf("%c",b[j][i]);
        }
        printf("\n");
    }
    return 0;
}
