//    spoj - classical problem - 3923. Philodpher's stone - problem code: BYTESM2



/*
This problem is a simple application of Dynamic Programming. We are asked to find the maximum number of stones 
that Harry can pick up. 
The idea:
	Suppose that we need to find the number of stones to be picked up in the current position (i,j), i.e., we 
	have already computed number of stones picked up so far (up to row i-1). The current position is (i,j). 
	When we were in the previous row (i-1), the column elements that could access the current column (j) are 
	j-1, j and j+1. Let us call the given array of numbers as A. Create another array B where we store the 
	cumulative sum of stones collected for every row. Initially, fill the first row of array B with the 
	elements of first row of array A. After that, loop over array B to find all the entries. For a given 
	position (i,j), B(i,j) is the sum of A(i,j) and the maximum of B(i-1,j-1), B(i-1,j) and B(i-1,j+1).
	
	for j=0 to (No_of_columns)
		B[0][j]=A[0][j]
	for i=1 to (No_of_rows)
		for j=0 to (No_of_columns)
			B[i][j]= A[i][j] + max( B[i-1][j-1], B[i-1][j], B[i-1][j+1] )
	Maximum= B[0][0]
	No_of_rows = t	
for i=1 to (No_of_columns)
		if ( maximum > B[t-1][i] )
			maximum= B[t-1][i]
t is the number of rows. Since array index starts from 0, (t-1) refers to the last row. �Maximum� is the max 
umber of stones picked up.Since it is the cumulative sum, the maximum number of stones picked up is 
biggest element in the last row of array B. 
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
		scanf("%d %d",&h,&w);
		for(i=0;i<h;i++)
			for(j=0;j<w;j++)
				scanf("%d",&a[i][j]);
		for(i=0;i<150;i++)
			for(j=0;j<150;j++)
				b[i][j]=0;
		for(i=0;i<w;i++)
			b[0][i]=a[0][i];
		max=0;
		for(i=1;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				if(j==0)
				{
					if(b[i-1][j]>b[i-1][j+1])
							max=b[i-1][j];
					else max=b[i-1][j+1];
				}
				else if(j==w-1)
				{
					if(b[i-1][j-1]>b[i-1][j])
							max=b[i-1][j-1];
					else max=b[i-1][j];
				}
				else
				{
					if(b[i-1][j-1]>b[i-1][j])
					{
						if(b[i-1][j-1]>b[i-1][j+1])
							max=b[i-1][j-1];
						else max=b[i-1][j+1];
					}
					else
					{
						if(b[i-1][j]>b[i-1][j+1])
							max=b[i-1][j];
						else max=b[i-1][j+1];	
					}
				}
				b[i][j]=a[i][j]+max;
			}
		}
		max=b[h-1][0];
		for(i=1;i<w;i++)
		{
			if(b[h-1][i]>max)
				max=b[h-1][i];
		}
		printf("%d\n",max);
	}
	return 0;
}
