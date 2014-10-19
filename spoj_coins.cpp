/*
  problem code: COINS
  problem number: 346
  problem link: http://www.spoj.com/problems/COINS/
*/

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

map <long long, long long> m;

long long coins( long long a )
{
  if( a==0 )
  {
    return 0;
  }

  long long c = m[a];

  if(c==0)
  {
    long long d = max( a, coins(a/2)+coins(a/3)+coins(a/4) );
    m[a] = d;
  }

  return m[a];
}


int main()
{
  long long p;

  while(cin>>p)
  {
    printf("%lld\n", coins(p));
  }

  return 0;
}