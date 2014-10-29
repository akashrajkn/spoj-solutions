/*
  problem code: MRECAMAN
  problem number: 3934
  problem link: http://www.spoj.com/problems/MRECAMAN/
*/

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <iterator>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <deque>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <utility>
#include <climits>

#define all(c) c.begin(),c.end()

using namespace std;

void recaman();

long long a[500001]
set<long long> s;

int main()
{
  int k;

  memset(b, 0, 4000000*sizeof(bool));

  b[0] = 1;

  s.insert(0);
  recaman();

  while(1)
  {
    scanf("%d", &k);

    if(k==-1)
    {
      return 0;
    }

    printf("%d\n", a[k]);
  }

  return 0;
}


void recaman()
{
  for(int i=1; i<500001; i++)
  {
    long long temp = a[i-1] - i;
    if( temp>0 && s.find(temp)==s.end() )
    {
      a[i] = temp;
    }
    else
    {
      temp+= (2*i);
      a[i] = temp; 
    }

    s.insert(temp);

  }

}

