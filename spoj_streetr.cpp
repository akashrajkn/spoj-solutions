/*
problem code: STREETR
problem number: 8132
problem link: http://www.spoj.com/problems/STREETR/
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


ll gcd(ll a, ll b);
vector<int> position(100000);


int main()
{
  /*
    gcd, adhoc
  */
  ll n, temp1, temp2, num, sum = 0;

  getInt(n);
  getInt(temp1);

  rep(i, n-1)
  {
    getInt(temp2);
    position[i] = temp2-temp1;
    temp1 = temp2;
  }

  //sort(position.begin(), position.begin() + n);

  num = gcd(position[0], position[1]);

  gRep(i, 2, n-1)
  {
    num = gcd(num, position[i]);
  }

  rep(i, n - 1)
  {
    sum += (position[i] / num - 1);
  }

  printf("%lld\n", sum);

  return OfTheKing;
}


ll gcd(ll a, ll b)
{
  while (b != 0)
  {
    a %= b;
    a ^= b;
    b ^= a;
    a ^= b;
  }

  return a;
}
