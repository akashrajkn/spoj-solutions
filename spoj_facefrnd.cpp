/*
problem code : FACEFRND
problem number : 9788
problem link : http://www.spoj.com/problems/FACEFRND/
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

set<int> b;
set<int> ans;

int main()
{
  int m,n, temp;
  scanf( "%d", &n );

  vector<int> v[n];

  for( int i =0; i<n; i++ )
  {
    scanf( "%d", &temp );
    b.insert(temp);

    scanf( "%d", &m );

    for( int j=0; j<m; j++ )
    {
      scanf( "%d", &temp );
      v[i].push_back(temp);
    }
  }

  for( int i=0; i<n; i++ )
  {
    temp= v[i].size();

    for( int j = 0; j<temp; j++ )
    {
      if(b.find(v[i][j]) == b.end() )
      {
        ans.insert(v[i][j]);
      }
    }
  }
  printf("%d\n", ans.size());

  return 0;
}