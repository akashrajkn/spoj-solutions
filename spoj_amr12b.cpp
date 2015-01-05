/*
  problem code: AMR12B
  problem number: 13042
  problem link: http://www.spoj.com/problems/AMR12B/
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

using namespace std;

#define OfTheKing 0
#define rep(i,n) for(long long i=0; i<n; ++i)
#define gRep(i,p,n) for(long long i=p; i<n; ++i)
#define mp make_pair
#define all(c) c.begin(),c.end()
#define sc(a) scanf("%lld", &a)
#define pf(a) printf("%lld\n",a)
#define ub upper_bound
#define lb lower_bound
#define bs binary_search
#define pb push_back
#define g_u getchar_unlocked() //if windows use getchar()

typedef pair<long long,long long> pii;
typedef long long ll;

int attack[1000001];


//fast input function
inline void inp( int &n )
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
  n=n*sign;
}


int main()
{
  int t, n, m;
  int x, y;

  //scanf("%d", &t);
  inp(t);

  while(t--)
  {
    //scanf("%d %d", &n, &m);
    inp(n);
    inp(m);

    rep(i,n+1)
    {
      attack[i] = i-1;
    }

    rep(i,m)
    {
      //scanf("%d %d", &x, &y);
      inp(x);
      inp(y);

      attack[x]++;
      attack[y]--;
    }

    int gandalf = -1;

    for(int i=n; i>0; --i)
    {
      if(attack[i]==n-1)
      {
        gandalf = i;
        break;
      }
    }

    if(gandalf!=-1)
    {
      printf("2 %d\n", gandalf );
    }
    else
    {
      printf("1\n");
    }

  }

  return OfTheKing;
}



