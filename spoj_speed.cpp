/*
  problem code: SPEED
  problem number: 9199
  problem link: http://www.spoj.com/problems/SPEED/
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
#define gRep(i,p,n) for(long long i=p, i<n; ++i)
#define mp make_pair
#define all(c) c.begin(),c.end()
#define sc(a) scanf("%lld", &a)
#define pf(a) printf("%lld\n",a)
//#define g_u getchar_unlocked() //if windows use getchar()
#define g_u getchar()

typedef pair<long long,long long> pii;
typedef long long ll;


//fast input function
inline void getInt( int &n )
{
  n=0;
  int ch=g_u;
  int sign=1;
  while( ch < '0' || ch > '9' )
  {
    if(ch=='-')
    {
      sign=-1;
    }
    ch=g_u;
  }
  while( ch >= '0' && ch <= '9' )
  {
    n=(n<<3)+(n<<1)+ ch-'0';
    ch=g_u;
  }
  n*=sign;
}


int max( int a, int b )
{
  return a>b?a:b;
}


int gcd(int a, int b)
{
  while(b!=0)
  {
    a%=b;
    a^=b;
    b^=a;
    a^=b;
  }

  return a;
}


int main()
{
  int t, s1, s2;

  getInt(t);

  while(t--)
  {
    getInt(s1);
    getInt(s2);

    int diff = s1>s2?s1-s2:s2-s1;

    s1*= (s1<0?-1:1);
    s2*= (s2<0?-1:1);

    printf("%d\n", diff/gcd(s1,s2));
  }

  return OfTheKing;
}
