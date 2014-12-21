/*
  problem code: HISTOGRA
  problem number: 1805
  problem link: http://www.spoj.com/problems/HISTOGRA/
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
#include<climits>

using namespace std;

#define rep(i,n) for(long long i=0; i<n; ++i)
#define gRep(i,p,n) for(long long i=p, i<n; ++i)
#define mp make_pair
#define all(c) c.begin(),c.end()

typedef pair<long long,long long> pii;
typedef long long ll;

ll maxRectangleArea(ll inp[], ll a);

int main()
{
  ll n;

  /*
    This solution runs in O(n). It uses stack. Start from the left most (with an empty stack)
    if stack is empty or the bar in top of stack is smaller than the current bar, then push the bar to stack
    if  current bar is smaller than the top of stack bar, then pop the ts bar and calculate the area with
      that as the smallest block

    the idea: the left 'boundary' with top of stack bar as the smallest bar is the one below the top of stack
    the right 'boundary' is the current bar
  */

  while(1)
  {
    scanf("%lld", &n);

    if(n==0)
    {
      break;
    }

    ll inp[n];

    rep(i, n)
    {
      scanf("%lld", &inp[i]);
    }

    printf("%lld\n", maxRectangleArea(inp, n));
  }

  return 0;
}


ll maxRectangleArea(ll inp[], ll n)
{
  stack<ll> s;

  ll maxArea  = 0;
  ll topStack;
  ll areaWithTS ; // area with top of stack as the minumum bar.
  ll i=0;

  while(i<n)
  {
    if(s.empty() || inp[s.top()]<=inp[i])
    {
      s.push(i++);
    }
    else //pop the top of stack
    {
      topStack = s.top();
      s.pop();

      areaWithTS = inp[topStack]*(s.empty()?i:(i-s.top()-1));

      if(areaWithTS>maxArea)//check if newly calculated area is bigger than the previously max area
      {
        maxArea = areaWithTS;
      }
    }
  }

  //if i=n, pop remaining bars and calculate the area
  while(!s.empty())
  {
    topStack = s.top();
    s.pop();

    areaWithTS = inp[topStack]*(s.empty()?i: (i-s.top()-1));

    if(areaWithTS>maxArea)
    {
      maxArea = areaWithTS;
    }
  }

  return maxArea;
}





