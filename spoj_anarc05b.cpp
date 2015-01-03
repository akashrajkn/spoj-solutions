#include<cstdio>
#include<set>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
#include<memory>
#include<queue>
#include<deque>
#include<iterator>
#include<sstream>
#include<stack>
#include<utility>
#include<cmath>
#include<cstdlib>

using namespace std;

int main()
{
  int n1, n2, maxa1, maxa2, max;
  int i, j;

  while( 1 )
  {
    scanf("%d", &n1);
    if( n1==0 )
    {
      break;
    }
    vector<int> a1(n1);

    for( i=0; i<n1; ++i )
    {
      scanf( "%d", &a1[i] );
    }

    scanf( "%d", &n2 );
    vector<int> a2(n2);

    for( i=0; i<n2; ++i )
    {
      scanf( "%d", &a2[i] );
    }
    maxa2 = 0;
    maxa1 = 0;
    max = 0;

    i=0; j=0;
    while( i<n1 && j<n2 )
    {
      if( a1[i]==a2[j] )
      {
        max+= ( (maxa1>maxa2) ? maxa1:maxa2 );
        max+= a1[i];
        //printf( "%d %d %d %d %d\n", maxa1, maxa2, max, a1[i], a2[j]  );
        i++; j++;
        maxa1 = 0;
        maxa2 = 0;
      }
      else if( a1[i]>a2[j] )
      {
        maxa2+=a2[j];
        j++;
      }
      else if( a2[j]>a1[i] )
      {
        maxa1+=a1[i];
        i++;
      }
    }
    if( i<n1 )
    {
      for( int k=i; k< n1; ++k )
      {
        maxa1+=a1[k];
      }

      max+= ( (maxa2>maxa1)?maxa2:maxa1 );
    }
    else if( j<n2 )
    {
      for( int k=j; k<n2; ++k )
      {
        maxa2+=a2[k];
      }

      max+= ( (maxa2>maxa1)?maxa2:maxa1 );
    }

    printf( "%d\n", max );
  }

  return 0;
}
