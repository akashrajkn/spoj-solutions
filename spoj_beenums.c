#include<stdio.h>
#include<math.h>
int main()
{
	long long n,t;

	while(1)
	{
		scanf("%lld",&n);
		if(n==-1)
		{
			break;
		}
		if(n%2!=0)
		{
			n--;
			if(n%3==0)
			{
				n/=3;
				n=(n*4)+1;
				t= sqrt(n);
				if(t*t==n)
				{
					if(t%2!=0)
					{
						printf("Y\n");
					}
					else
					{
						printf("N\n");
					}
				}
				else
				{
					printf("N\n");
				}
			}	
			else
			{
				printf("N\n");
			}
		}
		else
		{
			printf("N\n");
		}
	}

	return 0;
}