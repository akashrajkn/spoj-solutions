#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int t,length,count,i,k;
    long long int a;
    char *b,*c;
    char d;


    b = malloc( 200*sizeof(char) );
    c = malloc( 200*sizeof(char) );
    scanf("%d",&t);

    while(t--)
    {
    	count=0;
    	scanf("%s",b);
    	length= strlen(b);
    	for(i=0;i<length;i++)
    	{
    		if(b[i]>='0' && b[i]<='9')
    		{
    			c[count++] = b[i];
    		}
    		else
    		{
    			c[count]='\0';
    			a = atoi(c);
    			count=0;
    			d=b[i];
    			k=i;
    			break;
    		}
    	}
    	for(;i<length;i++)
    	{
    		if(b[i]>='0' && b[i]<='9')
    		{
    			c[count++] = b[i];
    			printf("%c\n",c[count-1]);
    		}
    		else
    		{
    			c[count]='\0';
    			if(d=='+')
    			{
    				a=a+ atoi(c);	
    				printf("%d\n",atoi(c));
    			}
    			if(d=='*')
    			{
    				a*= atoi(c);	
    			}
    			if(d=='-')
    			{
    				a-= atoi(c);	
    			}
    			if(d=='/')
    			{
    				a/= atoi(c);	
    			}
    			count=0;
    			d=b[i];
    		}
    	}
    	printf("%lld\n",a);
    }

    return 0;
}
