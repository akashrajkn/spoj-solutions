#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  char *a;
  a=malloc(101*sizeof(char));
  double res,aux;
  int counter,len,i,ones,zeros;
  scanf("%s",a);
  len=strlen(a);
  counter=0;
  zeros=0;ones=0;
  for(i=0;i<len;i++)
    if(a[i]=='0')
      counter++;
  res= (double)(counter+0.0)/(len);

  for(i=0;i<len;i++)
  {
    if(i!=len-1 && a[i]=='0')
    {
      if(a[i+1]=='0')
        zeros++;
      if(a[i+1]=='1')
        ones++;
    }
    if(i==len-1 && a[i]=='0')
    {
      if(a[0]=='0')
        zeros++;
      if(a[0]=='1')
        ones++;
    }
  }
  aux=(double)((zeros+0.0)/(ones+zeros));
  if(aux<res)
    printf("ROTATE\n");
  else if(aux>res)
    printf("SHOOT\n");
  else  printf("EQUAL\n");
  return 0;
}
