/*
problem code: ENIGMATH
problem number: 15965
problem link: http://www.spoj.com/problems/ENIGMATH/
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
#include<list>
#include<bitset>
#include<fstream>

using namespace std;

#define OfTheKing 0
#define rep(i,n) for(long long i=0; i<n; ++i)
#define gRep(i,p,n) for(long long i=p; i<n; ++i)
#define MP make_pair
#define all(c) c.begin(),c.end()
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define PB push_back
#define PF push_front
//#define g_u getchar_unlocked() //if windows use getchar()
#define g_u getchar()

typedef pair<long long, long long> pii;
typedef long long ll;


//fast input function
inline void getInt(ll &n)
{
  n = 0;
  ll ch = g_u;
  ll sign = 1;
  while (ch < '0' || ch > '9')
  {
    if (ch == '-')
    {
      sign = -1;
    }
    ch = g_u;
  }
  while (ch >= '0' && ch <= '9')
  {
    n = (n << 3) + (n << 1) + ch - '0';
    ch = g_u;
  }
  n *= sign;
}


int max(int a, int b)
{
  return a>b ? a : b;
}


ll n, p;
ll BITree[50002];
ll answer[50002];
void updateBIT(ll, ll);
ll queryBIT(ll);


int main()
{
  /*
    Binary indexed trees - to query the number of tasks not completed, update a task as completed

    timeTaken(presentTask) = (remaining elements)*(times[i].first - times[i-1].first -1) +
                             (no. of tasks before times[i].second not completed)

    extraTimeToCompleteCurrentRound = timeTaken(presentTask) + (no. of tasks after times[i].second
                                                                not completed)

    update times[i].second as completed
  */

  vector < pii > times;

  getInt(n);

  //initialize 0th index
  times.PB(MP(0, 0));

  rep(i, n) //get the time inputs
  {
    getInt(p);
    times.PB(MP(p, i+1)); //index is 1-based
    updateBIT(i+1, 1); //initialize BITree as not completed
  }

  //sort vector times wrt pair.first
  sort(all(times));

  ll currentTime = 0;

  gRep(i, 1, n + 1)
  {
    currentTime += (times[i].first - times[i - 1].first - 1)*(n - i + 1);
    currentTime += queryBIT(times[i].second); //num of uncompleted tasks before this one

    answer[times[i].second] = currentTime;

    updateBIT(times[i].second, -1); //update currentindex as completed
    currentTime += (n - i) - queryBIT(times[i].second); //no of uncompleted tasks after this one
  }

  gRep(i, 1, n + 1)
  {
    printf("%lld\n", answer[i]);
  }

  return OfTheKing;
}


void updateBIT(ll idx, ll num)
{
  for (; idx <= n; idx += (idx& -idx))
  {
    BITree[idx] += num;
  }
}


ll queryBIT(ll idx)
{
  ll sum = 0;
  for (; idx > 0; idx -= (idx & -idx))
  {
    sum += BITree[idx];
  }

  return sum;
}