#include <stdio.h>
 int gcd(int a,int b)
{
    return !b?a:gcd(b,a%b);
}
int mod(char s[],int d)
{
int r = 0,i;
for(i=0;s[i];i++){
r=10*r +(s[i] - 48);
r %= d;
}
return r;
}
int main(){
int test , a;
char b[254];
scanf("%d",&test);
while(test--){
scanf("%d%s",&a,b);
if(!a)
printf("%s\n",b);
else
printf("%d\n",gcd(a,mod(b,a)));
}
return 0;
}
