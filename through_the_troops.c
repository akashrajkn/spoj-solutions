/*
SPOJ Problem Set (classical)
9820. Through the troops
Problem code: WPC4F
*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,h,w,i,j,max;
	int **a,**b;
	a=malloc(150*sizeof(int *));
	b=malloc(150*sizeof(int *));
	for(i=0;i<150;i++)
	{
		b[i]=malloc(150*sizeof(int));
		a[i]=malloc(150*sizeof(int));
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&h);
		for(i=0;i<h;i++)
			for(j=0;j<3;j++)
				scanf("%d",&a[i][j]);
		for(i=0;i<150;i++)
			for(j=0;j<150;j++)
				b[i][j]=0;
		for(i=0;i<3;i++)
			b[0][i]=a[0][i];
		max=0;
		for(i=1;i<h;i++)
		{
			for(j=0;j<3;j++)
			{
				if(j==0)
				{
					if(b[i-1][1]>b[i-1][2])
						max=b[i-1][2];
					else max=b[i-1][1];
				}
				else if(j==2)
				{
					if(b[i-1][0]>b[i-1][1])
						max=b[i-1][1];
					else max=b[i-1][0];
				}
				else
				{
					if(b[i-1][0]>b[i-1][2])
						max=b[i-1][2];
					else max=b[i-1][0];
				}
				b[i][j]=a[i][j]+max;
			}
		}
		max=b[h-1][0];
		for(i=1;i<3;i++)
		{
			if(b[h-1][i]<max)
				max=b[h-1][i];
		}
		printf("%d\n",max);
	}
	return 0;
}