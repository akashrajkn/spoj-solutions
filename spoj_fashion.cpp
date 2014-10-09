/*
problem code: FASHION
problem number: 1025
problem link: http://www.spoj.com/problems/FASHION/
*/

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
  int t, n;

  scanf("%d", &t);

  while(t--)
  {
    scanf("%d", &n);
    vector <int> a(n), b(n);

    for( int i=0; i<n; i++ )
    {
      scanf("%d", &a[i]);
    }
    for( int i=0; i<n; i++ )
    {
      scanf("%d", &b[i]);
    }

    sort( a.begin(), a.end() );
    sort( b.begin(), b.end() );

    int ans =0;

    for( int i=0; i<n; i++ )
    {
      ans+= (a[i]*b[i]);
    }
    printf("%d\n", ans);
  }

  return 0;
}
