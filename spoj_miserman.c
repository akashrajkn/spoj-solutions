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
  //scanf("%d",&t);
  t=1;
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
              max=b[i-1][j+1];
          else max=b[i-1][j];
        }
        else if(j==w-1)
        {
          if(b[i-1][j-1]>b[i-1][j])
              max=b[i-1][j];
          else max=b[i-1][j-1];
        }
        else
        {
          if(b[i-1][j-1]>b[i-1][j])
          {
            if(b[i-1][j]>b[i-1][j+1])
              max=b[i-1][j+1];
            else max=b[i-1][j];
          }
          else
          {
            if(b[i-1][j-1]>b[i-1][j+1])
              max=b[i-1][j+1];
            else max=b[i-1][j-1]; 
          }
        }
        b[i][j]=a[i][j]+max;
      }
    }
    max=b[h-1][0];
    for(i=1;i<w;i++)
    {
      if(b[h-1][i]<max)
        max=b[h-1][i];
    }
    printf("%d\n",max);
  }
  return 0;
}


