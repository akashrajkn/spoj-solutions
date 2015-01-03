#include<stdio.h>
#include<stdlib.h>
int main()
{
  int n,count,i,j,m;
  int m4,m2,m3;
  float temp;
  float *b,*d;
  char a[5];
  scanf("%d",&n);
  b=malloc(n*sizeof(float));
  d=malloc(n*sizeof(float));
  count=0;
  m4=0;m2=0;m3=0;
  for(i=0;i<n;i++)
  {
    scanf("%s",a);
    if(a[2]=='2')
    {
      b[i]=0.5;
      m2++;
    }
    if(a[0]=='1' && a[2]=='4')
    {
      b[i]=0.25;
      m4++;
    }
    if(a[0]=='3')
    {
      b[i]=0.75;
      m3++;
    }
    d[i]=(float)(1-b[i]);
  }
  count=m3;
  m4-=m3;
  count+=(m2/2);
  if(m2%2!=0)
    m2=1;
  if(m2==1)
  {
    count++;
    if(m4>0)
      m4-=2;
  }
  if(m4>0)
  {
    count+=(m4/4);
    if(m4%4!=0)
      count++;
  }
  count++;
  printf("%d\n",count);
  return 0;
}
