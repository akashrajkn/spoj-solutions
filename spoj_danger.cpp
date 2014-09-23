#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<iterator>
#include<set>
#include<map>
#include<iostream>
#include<sstream>
#include<deque>
#include<cmath>
#include<memory.h>
#include<algorithm>
#include<utility>

using namespace std;

int val[] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };

int main()
{
  char a[4];
  int n, ans, temp;

  while(1)
  {
    scanf( "%s", a );
    
    if( a[0]=='0' && a[1]=='0' && a[3]=='0' )
    {
      return 0;
    }

    n = ((a[0]-'0')*10) + (a[1]-'0');
  
    temp = val[a[3]-'0'];

    n*=temp;
    
    temp = 1;

    while( temp<n )
    {
      temp*=2;
    }

    if(temp==n)
    {
      printf( "1\n" );
      continue;
    }

    temp/=2;
    ans = n - temp;
    ans*=2;
    ans++;

    printf( "%d\n", ans );
  }

  return 0;
}